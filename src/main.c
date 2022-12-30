/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:48:03 by antthoma          #+#    #+#             */
/*   Updated: 2022/12/28 17:47:39 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game		*game;

	game = NULL;
	game = init_game(game);
	if (check_format_file(argc, argv))
		msg_error(game, "Error\nyou need to pass correct map name_map.ber\n", 1);
	if (read_map_file(game, argv))
		msg_error(game, "Error\nproblem to read map\n", 1);
	if (build_window(game))
		msg_error(game, "Error\ncannot build window\n", 0);
	if (load_map(argv, game))
		msg_error(game, "Error\ncannot load map\n", 3);
	load_images(game);
	if (check_map_walls(game))
		msg_error(game, "Error\ninvalid map, wrong walls\n", 2);
	build_map(game);
	if (check_path(game))
		msg_error(game, "Error\ninvalid path\n", 2);
	load_map(argv, game);
	load_events(game);
	mlx_expose_hook(game->window, expose_hook, game);
	mlx_loop(game->mlx);
	return (0);
}
