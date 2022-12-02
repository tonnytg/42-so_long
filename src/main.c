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
	printf("destroy window %d\n", *(int *)game->window);
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
}

int	key_event(int key)
{
	printf("key=%d\n", key);
	if (key == ESC)
		exit(0);
	if (key == UP)
		exit(0);
	if (key == DOWN)
		exit(0);
	if (key == LEFT)
		exit(0);
	if (key == RIGHT)
		exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("error to read argument of map");
		return (1);
	}
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		printf("Error: mlx_init() returned NULL");
	// TODO: check if map is valid
	// TODO: Create a function to read map
	game.window = mlx_new_window(game.mlx, 350, 250, "Hello world!");
	mlx_hook(game.window, 17, 1L << 2, destroy_window, &game);
	mlx_key_hook(game.window, key_event, 0);
	mlx_loop(game.mlx);
	return (0);
}
