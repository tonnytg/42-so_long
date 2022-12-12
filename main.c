/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:48:03 by antthoma          #+#    #+#             */
/*   Updated: 2022/12/12 04:07:34 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	clean_game(t_game *game, int trigger)
{
	if (trigger == 1)
	{
		mlx_destroy_image(game->mlx, game->images->wall);
		mlx_destroy_image(game->mlx, game->images->player);
		mlx_destroy_image(game->mlx, game->images->collectible);
		mlx_destroy_image(game->mlx, game->images->exit);
	}
	free(game->player);
	free(game->images);
	free(game->mlx);
}

int	msg_error(t_game *game, char *msg, int trigger)
{
	clean_game(game, trigger);
	ft_putstr(msg);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_game		*game;

	game = NULL;
	game = init_game(game);
	if (check_format_file(argc, argv))
	{
		game->mlx = malloc(sizeof(void *));
		msg_error(game, "Error\nyou need to pass correct map name_map.ber\n", 0);
	}
	if (read_map_file(game, argv))
	{
		game->mlx = malloc(sizeof(void *));
		msg_error(game, "Error\nproblem to read map\n", 0);
	}
	if (build_window(game))
		msg_error(game, "Error\ncannot build window\n", 0);
	load_map(argv, game);
	load_images(game);
	if (check_map_walls(game))
	{
		mlx_destroy_window(game->mlx, game->window);
		msg_error(game, "Error\ninvalid map, wrong walls\n", 1);
	}
	build_map(game);
	load_events(game);
	mlx_loop(game->mlx);
	return (0);
}
