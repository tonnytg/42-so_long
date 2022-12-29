/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c	                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:48:03 by antthoma          #+#    #+#             */
/*   Updated: 2022/12/02 13:48:21 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop_content_map(t_game *game)
{
	while (game->content != NULL && game->line < game->map->count_lines)
	{
		game->column = 0;
		while (game->column < game->map->count_columns)
		{
			if (game->content[game->column] != '\n')
				game->map->location[game->line][game->column]
						= game->content[game->column];
			if (game->content[game->column] == '\n'
				&& game->column != game->map->count_columns)
			{
				free(game->content);
				return (1);
			}
			game->column++;
		}
		free(game->content);
		game->content = get_next_line(game->map->fd);
		game->line++;
	}
	return (0);
}
