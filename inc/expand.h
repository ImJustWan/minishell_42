/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:13:20 by tgibier           #+#    #+#             */
/*   Updated: 2023/09/24 14:13:02 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "minishell.h"

int		expander(t_minishit *hell, t_token *token);
int		check_dollar(char *str, int i);
int		dollar_sign(char *str);
int		get_start(char *str);
int		get_end(char *str, int i);
char	*get_value(t_minishit *hell, char *str);

#endif
