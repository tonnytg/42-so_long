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
	return (0);
}

int	exit_game(t_game *game)
{
	printf("exit game\n");
	destroy_window(game);
	exit(0);
}

int	keyPressed(int key, t_player *player)
{
	printf("key pressed %d\n", key);
	printf("key=%d\n", key);
	if (key == ESC)
	{
		printf("ESC\n");
		exit(0);
	}
	if (key == UP)
	{
		printf("UP %d %d\n", player->x, player->y);
		return (0);
	}
	if (key == DOWN)
	{
		printf("DOWN %d %d\n", player->x, player->y);
		return (0);
	}
	if (key == LEFT)
	{
		printf("LEFT %d %d\n", player->x, player->y);
		return (0);
	}
	if (key == RIGHT)
	{
		printf("RIGHT %d %d\n", player->x, player->y);
		return (0);
	}
	return (0);
}



int readMap(t_map *map)
{
	int column;
	int line;

	column = 0;
	line = 0;
	while (line < 5)
	{
		while (column < 14)
		{
			printf("(%d)", map->location[line][column]);
			column++;
		}
		printf("\n");
		column = 0;
		line++;
	}
	return (0);
}

int loadImage(t_images *images, t_game *game)
{
	images->wall = mlx_xpm_file_to_image(game->mlx, "src/wall.xpm", &images->x, &images->y);
	if (!images->wall)
		return (1);
	images->player = mlx_xpm_file_to_image(game->mlx, "src/player.xpm", &images->x, &images->y);
	if (!images->player)
		return (1);
	images->exit = mlx_xpm_file_to_image(game->mlx, "src/exit.xpm", &images->x, &images->y);
	if (!images->exit)
		return (1);
	images->collectible = mlx_xpm_file_to_image(game->mlx, "src/collectible.xpm", &images->x, &images->y);
	if (!images->collectible)
		return (1);
	return (0);
}

int buildMap(t_map *map, t_game *game, t_images *images, t_player *player)
{
	int column;
	int line;

	line = 0;
	while (line < 5)
	{
		column = 0;
		while (column < 14)
		{
			if (map->location[line][column] == 49)
				mlx_put_image_to_window(game->mlx, game->window, images->wall,
										(column * PIXEL_SIZE), (line * PIXEL_SIZE));
			if (map->location[line][column] == 80)
			{
				mlx_put_image_to_window(game->mlx, game->window, images->player,
										(column * PIXEL_SIZE), (line * PIXEL_SIZE));
				player->x = column;
				player->y = line;
				printf("Player: %d %d\n", player->x, player->y);
			}
			if (map->location[line][column] == 67)
				mlx_put_image_to_window(game->mlx, game->window, images->collectible,
										(column * PIXEL_SIZE), (line * PIXEL_SIZE));
			if (map->location[line][column] == 69)
				mlx_put_image_to_window(game->mlx, game->window, images->exit,
										(column * PIXEL_SIZE), (line * PIXEL_SIZE));
			column++;
		}
		line++;
	}
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
	map->location[5] = NULL;
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
			return (0);
		line++;
	}
	return (0);
}

int buildWindow(t_game *game)
{
	game->width = 416;
	game->height = 160;

	game->window = mlx_new_window(game->mlx, game->width, game->height, "so_long");
	if (!game->window)
		return (1);
	return (0);
}

int	key_event(int key)
{
	printf("key pressed %d\n", key);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_map		map;
	t_images	images;
	t_player	player;
	int			error;


	game.player = &player;
	player.x = *(int *)malloc(sizeof(int));
	player.y = *(int *)malloc(sizeof(int));
	map.location = malloc(sizeof(int *) * 50);
	if (argc != 2)
	{
		printf("error to read argument of map\n");
		return (1);
	}
	game.mlx = mlx_init();
	if (game.mlx == NULL) {
		printf("Error: mlx_init() returned NULL\n");
	}
	error = loadMap(&map, argv);
	if (error == 1)
	{
		printf("Error: failed to loadMap\n");
		return (1);
	}
	buildWindow(&game);
	loadImage(&images, &game);
	readMap(&map);
	buildMap(&map, &game, &images, &player);
	mlx_key_hook(game.window, key_event, &game);
	mlx_hook(game.window, 17, 0, exit_game, &game);
	mlx_hook(game.window, 2, 1L<<0, keyPressed, &player);
	mlx_loop(game.mlx);
	return (0);
}
