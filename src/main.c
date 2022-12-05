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

int buildWindow(t_game *game)
{
	game->width = 416;
	game->height = 160;
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->width, game->height, "so_long");
	if (!game->window
		|| !game->mlx)
		return (1);
	return (0);
}

int loadMap(int argc, char **argv, t_game *game)
{
	int column;
	int line;
	char *tempContent;
	if (argc != 2)
		return (1);
	printf("Loading map...\n");
	game->map->location = malloc(sizeof(int *) * 5);
	game->map->location[0] = malloc(sizeof(int) * 15);
	game->map->location[1] = malloc(sizeof(int) * 15);
	game->map->location[2] = malloc(sizeof(int) * 15);
	game->map->location[3] = malloc(sizeof(int) * 15);
	game->map->location[4] = malloc(sizeof(int) * 15);
	game->map->fd = open(argv[1], O_RDONLY);
	tempContent = get_next_line(game->map->fd);
	if (tempContent == NULL)
		return (1);
	line = 0;
	while (line < 5)
	{
		column = 0;
		while(column < 14)
		{
			if (tempContent[column] != '\n')
				game->map->location[line][column] = tempContent[column];
			column++;
		}
		tempContent = get_next_line(game->map->fd);
		if (tempContent == NULL)
			return (0);
		line++;
	}
	return (0);
}

int loadImages(t_game *game)
{
	game->images->wall = mlx_xpm_file_to_image(game->mlx, "src/images/wall.xpm",
											   &game->images->x, &game->images->y);
	game->images->collectible = mlx_xpm_file_to_image(game->mlx, "src/images/collectible.xpm",
													  &game->images->x, &game->images->y);
	game->images->exit = mlx_xpm_file_to_image(game->mlx, "src/images/exit.xpm",
											   &game->images->x, &game->images->y);
	game->images->player = mlx_xpm_file_to_image(game->mlx, "src/images/player.xpm",
												 &game->images->x, &game->images->y);
	if (!game->images->wall
		|| !game->images->collectible
		|| !game->images->exit
		|| !game->images->player)
		return (1);
	return (0);
}

int buildMap(t_game *game)
{
	printf("Building map...\n");
	int column;
	int line;

	line = 0;
	while (line < 5)
	{
		column = 0;
		while (column < 14)
		{
			if (game->map->location[line][column] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->images->wall, column * PIXEL_SIZE, line * PIXEL_SIZE);
			if (game->map->location[line][column] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, game->images->collectible, column * PIXEL_SIZE, line * PIXEL_SIZE);
			if (game->map->location[line][column] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->images->exit, column * PIXEL_SIZE, line * PIXEL_SIZE);
			if (game->map->location[line][column] == 'P')
			{
				printf("Player found at %d, %d\n", column, line);
				mlx_put_image_to_window(game->mlx, game->window, game->images->player, column * PIXEL_SIZE, line * PIXEL_SIZE);
				game->player->x = column;
				game->player->y = line;
				printf("Player position: %d, %d\n", game->player->x, game->player->y);
			}
			column++;
		}
		line++;
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

int keyPress(int keycode, t_game *game)
{
	printf("event happened %d\n", keycode);
	printf("x: %d\n", game->player->x);
	printf("y: %d\n", game->player->y);

	int oldX;
	int oldY;

	oldX = game->player->x;
	oldY = game->player->y;
	if (keycode == UP)
		game->player->y--;
	if (keycode == DOWN)
		game->player->y++;
	if (keycode == LEFT)
		game->player->x--;
	if (keycode == RIGHT)
		game->player->x++;
	if (game->map->location[game->player->y][game->player->x] == '1')
	{
		game->player->x = oldX;
		game->player->y = oldY;
	} else
	{
		game->map->location[oldY][oldX] = '0';
		game->map->location[game->player->y][game->player->x] = 'P';
	}
	mlx_clear_window(game->mlx, game->window);
	buildMap(game);

	return (0);
}

int	main(int argc, char **argv)
{
	t_game		*game;
	int			error;

	game = malloc(sizeof(t_game));
	game->map = malloc(sizeof(t_map));
	game->images = malloc(sizeof(t_images));
	game->player = malloc(sizeof(t_player));
	error = buildWindow(game);
	if (error == 1)
		return (1);
	printf("width: %d\n", game->width);
	printf("height: %d\n", game->height);
	printf("window: %p\n", game->window);
	loadMap(argc, argv, game);
	loadImages(game);
	buildMap(game);
//	readMap(game->map);

	// key press events
	printf("player x: %d\n", game->player->x);
	printf("player y: %d\n", game->player->y);
	mlx_hook(game->window, 2, 1L<<0, keyPress, game);
	mlx_loop(game->mlx);
	return (0);
}
