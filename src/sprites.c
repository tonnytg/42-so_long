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

void	put_image(t_game *game, int *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx,
		game->window, image,
		x * PIXEL_SIZE, y * PIXEL_SIZE);
}

int	load_images(t_game *game)
{
	game->images->wall = mlx_xpm_file_to_image(game->mlx, "src/images/wall.xpm",
			&game->images->x, &game->images->y);
	game->images->collectible = mlx_xpm_file_to_image(game->mlx,
			"src/images/collectible.xpm", &game->images->x, &game->images->y);
	game->images->exit = mlx_xpm_file_to_image(game->mlx,
			"src/images/exit.xpm",
			&game->images->x, &game->images->y);
	game->images->player = mlx_xpm_file_to_image(game->mlx,
			"src/images/player.xpm",
			&game->images->x, &game->images->y);
	if (!game->images->wall
		|| !game->images->collectible
		|| !game->images->exit
		|| !game->images->player)
		return (1);
	return (0);
}
