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

int	loadMap(t_map *map, char **args)
{
	int		column;
	int		line;
	int		fd;
	char	*temp;

	map->location[0] = (int *)malloc(sizeof(int *) * 10);
	map->location[1] = (int *)malloc(sizeof(int *) * 10);
	map->location[2] = (int *)malloc(sizeof(int *) * 10);
	map->location[3] = (int *)malloc(sizeof(int *) * 10);
	map->location[4] = (int *)malloc(sizeof(int *) * 10);
	fd = open(args[1], O_RDONLY);
	temp = get_next_line(fd);
	if (temp == NULL)
		return (1);
	line = 0;
	while (temp != NULL && line < 5)
	{
		column = 0;
		while(column < 14)
		{
			if (temp[column] != '\n')
				map->location[line][column] = temp[column];
			column++;
		}
		temp = get_next_line(fd);
		if (temp == NULL)
			return (1);
		line++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	map;
	char	*text;

	map.location = malloc(sizeof(int *) * 50);
	if (argc != 2)
	{
		printf("error to read argument of map\n");
		return (1);
	}
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		printf("Error: mlx_init() returned NULL\n");
	loadMap(&map, argv);
	game.window = mlx_new_window(game.mlx, 350, 250, "Hello world!");
	mlx_hook(game.window, 17, 1L << 2, destroy_window, &game);
	mlx_key_hook(game.window, key_event, 0);
	mlx_loop(game.mlx);
	return (0);
}
