/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:48:03 by antthoma          #+#    #+#             */
/*   Updated: 2022/12/28 22:13:50 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init_game(t_game *game)
{
	game = malloc(sizeof(t_game));
	game->error = 0;
	game->error_c = 0;
	game->trigger = 0;
	game->map = malloc(sizeof(t_map));
	game->map->fd = 0;
	game->map->location = NULL;
	game->map->count_lines = 0;
	game->map->count_columns = 0;
	game->map->count_collectibles = 0;
	game->map->count_player = 0;
	game->map->count_exits = 0;
	game->map->count_zeros = 0;
	game->map->count_walls = 0;
	game->map->count_wrong_c = 0;
	game->images = malloc(sizeof(t_images));
	game->player = malloc(sizeof(t_player));
	game->player->x = 0;
	game->player->y = 0;
	game->player->moved = 0;
	game->player->collected = 0;
	return (game);
}
