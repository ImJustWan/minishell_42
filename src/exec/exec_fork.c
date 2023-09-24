/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:25:39 by mrony             #+#    #+#             */
/*   Updated: 2023/09/24 12:42:52 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "env.h"

static void	ft_bin_cmd(t_minishit *hell, t_node **comd, int *fds)
{
	char	*path;

	path = NULL;
	if (fds[1] != 1)
	{
		dup2(fds[1], STDOUT_FILENO);
		close(fds[1]);
	}
	if (fds[0] != 0)
	{
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
	}
	path = ft_check_path(hell, (*comd)->argv[0]);
	if (!path)
		clean_exit(hell);
	execve(path, (*comd)->argv, hell->my_env);
	clean_exit(hell);
}

void	ft_clear_argv(char **argv)
{
	int	tab_s;
	int	i;
	int	j;

	tab_s = ft_table_size(argv);
	i = -1;
	while (++i < tab_s)
		if (argv[i][0])
			break ;
	if (i == tab_s)
		return ;
	j = 0;
	while (i < tab_s)
	{
		argv[j] = argv[i];
		i++;
		j++;
	}
}

void	ft_exec_cmd(t_minishit *hell, t_node **comd, int *mem_fd)
{
	int	fds[2];

	fds[0] = 0;
	fds[1] = 1;
	dup2(*mem_fd, STDIN_FILENO);
	close(*mem_fd);
	ft_clear_argv((*comd)->argv);
	if (ft_check_rdr((*comd)) == FAILED)
	{
		close(*mem_fd);
		clean_exit(hell);
	}
	ft_set_redir(comd, fds);
	if ((*comd)->type == cmd && (*comd)->built_in == FALSE)
		ft_bin_cmd(hell, comd, fds);
	else if ((*comd)->type == cmd && (*comd)->built_in == TRUE)
	{
		ft_exec_bltin(hell, (*comd)->argv, fds);
		if (fds[1] != 1)
			close(fds[1]);
		if (fds[0] != 0)
			close(fds[0]);
		clean_exit(hell);
	}
}

void	ft_close_fds(t_node *node)
{
	while (node)
	{
		if (node->fd[0] != -1)
			close(node->fd[0]);
		if (node->fd[1] != -1)
			close(node->fd[1]);
		node = node->left;
	}
}

int	ft_exec_last_cmd(t_minishit *hell, t_node **comd, int *mem_fd)
{
	int	pid;
	int	exit_status;
	int	i;

	pid = fork();
	i = 0;
	ft_clear_argv((*comd)->argv);
	if (pid == 0)
		ft_exec_cmd(hell, comd, mem_fd);
	else
	{
		close(*mem_fd);
		hell->pids[hell->pipes] = pid;
		while (i <= hell->pipes)
		{
			waitpid(hell->pids[i], &exit_status, WUNTRACED);
			i++;
		}
		if (WIFEXITED(exit_status) == TRUE)
			hell->exit = WEXITSTATUS(exit_status);
	}
	ft_close_fds(*comd);
	return (hell->exit);
}
