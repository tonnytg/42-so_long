/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:48:03 by antthoma          #+#    #+#             */
/*   Updated: 2022/12/29 00:32:56 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	empty_get_next_line(t_game *game)
{
	while (game->content != NULL)
	{
		free(game->content);
		game->content = get_next_line(game->map->fd);
	}
}

int	get_content_file(t_game *game)
{
	while (game->content[game->x] != '\0')
	{
		if (game->content[game->x] == '\n' && game->trigger == 0)
		{
			game->trigger = 1;
			game->error_c = game->x;
		}
		if (game->trigger == 1 && game->content[game->x] == '\n'
			&& game->error_c != game->x)
		{
			empty_get_next_line(game);
			return (1);
		}
		map_count_itens(game, game->content, game->x);
		game->x++;
	}
	return (0);
}
