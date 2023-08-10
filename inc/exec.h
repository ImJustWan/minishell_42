/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:09:39 by mrony             #+#    #+#             */
/*   Updated: 2023/08/10 17:01:25 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include "builtins.h"
# include <unistd.h>
# include <fcntl.h>

# define MALLERRPATH "Path malloc failled"
# define MALFAILED -2
# define CMDERR "command not found"

/* exec.c */
int		ft_extract_rdr(t_minishit *hell, t_node **tree);
void	ft_exec(t_minishit *hell, t_node **tree);

/* exec_utils.c */
void	ft_set_redir(t_minishit *hell, t_node **cmd, int *fds);

/* exec_check_redir.c */
int		ft_check_rdr(t_minishit *hell,t_node *redir);

/* exec_fork.c */
int ft_forked_cmd(t_minishit *hell, t_node **cmd, int *fds);

/* exec_single_blt.c */
int ft_exec_bltin(t_minishit *hell, char **argv, int *fds);


/* exec_path.c */
int	check_path(char **envp, t_minishit *hell, t_node *cmd);

/* exec_errors*/
void	ft_exec_err(char *shell, char *cmd, char *arg, char *error);

#endif