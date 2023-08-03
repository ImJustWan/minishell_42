/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:20:38 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/03 16:11:47 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	clean_hell(t_minishit *hell)
{
	if (hell->my_env)
		ft_free(hell->my_env);
	if (hell->token)
		ft_clear_token(hell->token);
	if (hell->node)
		ft_clear_node(hell->node);
	if (hell->path)
		ft_free(hell->path);
}

int	parsing(t_minishit *hell)
{
	if (lexer(hell) == FALSE)
		return (FALSE);
	if (parser(hell) == FALSE)
		return (FALSE);
	/*
		exec here
	*/
	clean_hell(hell);
	clean_init(hell);
	return (TRUE);
}


/* 
 
	// while (hell->node)
	// {
	// 	printf("type is %d index is %d\n", hell->node->type, hell->node->index);
	// 	hell->node = hell->node->next;
	// }
	check if built_in
 
*/
