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
#include <stdlib.h>

t_game	*init_game(t_game *game)
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
	game->images = malloc(sizeof(t_images));
	game->player = malloc(sizeof(t_player));
	game->player->x = 0;
	game->player->y = 0;
	game->player->moved = 0;
	game->player->collected = 0;
	return (game);
}

void	load_events(t_game *game)
{
	mlx_hook(game->window, 17, 1L << 2, destroy_window, game);
	mlx_hook(game->window, 2, 1L << 0, key_press, game);
}

void	clean_game(t_game *game)
{
	free(game->map->location);
	free(game->map);
	free(game->images);
	free(game->player);
	free(game->mlx);
	free(game);
}

int	msg_error(t_game *game, char *msg)
{
	clean_game(game);
	ft_putstr(msg);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_game		*game;
	int			error;

	game = NULL;
	game = init_game(game);
	game->mlx = malloc(sizeof(int *));
	if (argc != 2)
		msg_error(game, "error, invalid argument\n");
	error = read_map_file(game, argv);
	if (error == 1)
		msg_error(game, "error, problem to read map file\n");
	error = build_window(game);
	if (error == 1)
		msg_error(game, "error, to build window size\n");
	load_map(argv, game);
	load_images(game);
	if (game->map->location[0][0] == '1')
		build_map(game);
	else
		msg_error(game, "error, invalid map\n");
	load_events(game);
	mlx_loop(game->mlx);
	return (0);
}
