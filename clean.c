/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:48:03 by antthoma          #+#    #+#             */
/*   Updated: 2022/12/21 03:40:30 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	zero_map_location(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->map->count_lines)
	{
		free(game->map->location[x]);
		x++;
	}
	free(game->map->location);
	return (0);
}

int	clean_game(t_game *game, int trigger)
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
	return (0);
}
