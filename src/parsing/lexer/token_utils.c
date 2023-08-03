/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:07:19 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/03 16:10:53 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	is_token(char c)
{
	if (c == '>')
		return (OUTPUT);
	if (c == '<')
		return (INPUT);
	if (c == '|')
		return (PIPE);
	if (c == ';')
		return (END);
	else
		return (-1);
}