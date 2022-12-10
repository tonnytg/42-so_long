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

t_game *init_game(t_game *game)
{
	game = malloc(sizeof(t_game));
	game->map = malloc(sizeof(t_map));
	game->map->fd = 0;
	game->map->location = NULL;
	game->map->count_lines = 0;
	game->map->count_columns = 0;
	game->map->count_collectibles = 0;
	game->images = malloc(sizeof(t_images));
	game->player = malloc(sizeof(t_player));
	game->player->x = 0;
	game->player->y = 0;
	game->player->moved = 0;
	game->player->collected = 0;
	return (game);
}

void load_events(t_game *game)
{
	mlx_hook(game->window, 17, 1L << 2, destroy_window, game);
	mlx_hook(game->window, 2, 1L << 0, key_press, game);	
}

void clean_game(t_game *game)
{
	free(game->map->location);
	free(game->map);
	free(game->images);
	free(game->player);
	free(game->mlx);
	free(game);
}

int	main(int argc, char **argv)
{
	t_game		*game;
	int			error;

	game = NULL;
	if (argc != 2)
		return (1);
	game = init_game(game);
	error = read_map_file(game, argv);
	if (error == 1)
	{
		game->mlx = malloc(sizeof(int *));
		clean_game(game);
		return (1);
	}
	error = build_window(game);
	if (error == 1)
	{
		clean_game(game);
		return (1);
	}
	load_map(argv, game);
	load_images(game);
	if (game->map->location[0][0] == '1')
		build_map(game);
	else
		return (1);
	load_events(game);
	mlx_loop(game->mlx);
	return (0);
}
