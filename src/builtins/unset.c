/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:01:21 by mrony             #+#    #+#             */
/*   Updated: 2023/08/03 16:06:58 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

int	ft_unset(t_minishit *hell, char **argv)
{
	int	var_l;
	int	i;

	if (!args->arg || !args)
		return (-1);
	var_i = ft_var_line(hell->my_env, args->arg);
	if (var_i >= 0)
		ft_del_var(&hell->my_env, var_i);
	else
		return (-1);
	return(0);
}