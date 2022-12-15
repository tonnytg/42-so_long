/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:48:03 by antthoma          #+#    #+#             */
/*   Updated: 2022/12/02 13:48:21 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
}

int	build_window(t_game *game)
{
	game->width = PIXEL_SIZE * game->map->count_columns;
	game->height = PIXEL_SIZE * game->map->count_lines;
	game->mlx = mlx_init();
	if (!game->mlx)
		msg_error("Error\nFailed to connect with graphical system\n", game, 1);
	mlx_get_screen_size(game->mlx, &game->screen_width, &game->screen_height);
	if ((game->width > game->screen_width) || (game->height > game->screen_height))
		msg_error("Error\nWindow size it is lower than map\n", game, 1);
	game->window = mlx_new_window(game->mlx, game->width,
			game->height, "so_long");
	if (!game->window)
		msg_error("Error\nFailed to create window on screen\n", game, 1);
	return (0);
}