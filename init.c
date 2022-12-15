/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:48:03 by antthoma          #+#    #+#             */
/*   Updated: 2022/12/02 13:48:21 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game *init_game(t_game *game)
{
	game = malloc(sizeof(t_game));
	game->map = malloc(sizeof(t_map));
	game->map->fd = 0;
	game->map->location = NULL;
	game->map->count_lines = 0;
	game->map->count_columns = 0;
	game->map->count_collectibles = 0;
	game->map->count_player = 0;
	game->map->count_exits = 0;
	game->map->count_walls = 0;
	game->map->count_floors = 0;
	game->map->count_wrong_c = 0;
	game->images = malloc(sizeof(t_images));
	game->player = malloc(sizeof(t_player));
	game->player->x = 0;
	game->player->y = 0;
	game->player->moved = 0;
	game->player->collected = 0;
	return (game);
}

void	clean_game(t_game *game, int trigger)
{
	if (trigger == 1)
		game->mlx = malloc(sizeof(void *));
	if (trigger == 2)
	{
		mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_image(game->mlx, game->images->wall);
		mlx_destroy_image(game->mlx, game->images->player);
		mlx_destroy_image(game->mlx, game->images->collectible);
		mlx_destroy_image(game->mlx, game->images->exit);
	}
	free(game->player);
	free(game->images);
	free(game->mlx);
}

void	msg_error(char *msg, t_game *game, int trigger)
{
	ft_putstr(msg);
	clean_game(game, trigger);
	exit (1);
}
