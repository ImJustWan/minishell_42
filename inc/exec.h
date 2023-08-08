/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:09:39 by mrony             #+#    #+#             */
/*   Updated: 2023/08/07 14:33:23 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include "builtins.h"
# include <unistd.h>
# include <fcntl.h>

/* exec.c */
void	ft_extract_rdr(t_minishit *hell, t_node **tree);
void	ft_exec(t_minishit *hell, t_node **tree);

/* exec_check_redir.c */
int		ft_check_rdr(t_minishit *hell,t_node *redir);

/* exec_errors*/
void	ft_exec_err(char *shell, char *cmd, char *arg, char *error);

#endif