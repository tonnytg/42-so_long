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
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_game		*game;
	int			error;

	game = malloc(sizeof(t_game));
	game->map = malloc(sizeof(t_map));
	game->images = malloc(sizeof(t_images));
	game->player = malloc(sizeof(t_player));
	build_window(game);
	error = load_map(argc, argv, game);
	if (error == 1)
		return (1);
	load_images(game);
	build_map(game);
	read_map(game->map);
	mlx_hook(game->window, 17, 1L << 2, destroy_window, game);
	mlx_hook(game->window, 2, 1L << 0, key_press, game);
	mlx_loop(game->mlx);
	return (0);
}
