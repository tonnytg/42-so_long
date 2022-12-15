/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:48:03 by antthoma          #+#    #+#             */
/*   Updated: 2022/12/10 18:47:44 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game		*game;

	game = NULL;
	if (argc != 2)
		return (1);
	game = init_game(game);
	map_read_file(game, argv);
	build_window(game);
	load_map(argv, game);
	check_path(game);
	load_map(argv, game);
	load_images(game);
	build_map(game);
	load_events(game);
	mlx_loop(game->mlx);
	return (0);
}
