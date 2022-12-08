/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c	                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:48:03 by antthoma          #+#    #+#             */
/*   Updated: 2022/12/02 13:48:21 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	build_map(t_game *game)
{
	int	column;
	int	line;

	line = 0;
	while (line < 5)
	{
		column = 0;
		while (column < 14)
		{
			if (game->map->location[line][column] == '1')
				mlx_put_image_to_window(game->mlx,
										game->window, game->images->wall,
										column * PIXEL_SIZE, line * PIXEL_SIZE);
			if (game->map->location[line][column] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
										game->images->collectible,
										column * PIXEL_SIZE, line * PIXEL_SIZE);
			if (game->map->location[line][column] == 'E')
				mlx_put_image_to_window(game->mlx, game->window,
										game->images->exit,
										column * PIXEL_SIZE, line * PIXEL_SIZE);
			if (game->map->location[line][column] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->window,
										game->images->player,
										column * PIXEL_SIZE, line * PIXEL_SIZE);
				game->player->x = column;
				game->player->y = line;
				printf("--\nPlayer position: %d, %d\n", game->player->x,
					   game->player->y);
				printf("Player moved: %d\n", game->player->moved);
				printf("player collected: %d\n", game->player->collected);
			}
			column++;
		}
		line++;
	}
	build_display_movement(game);
	return (0);
}

int	read_map(t_map *map)
{
	int	column;
	int	line;

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

// TODO: Segment fault when trying to read the map without argv[1]
int	load_map(int argc, char **argv, t_game *game)
{
	int		column;
	int		line;
	char	*tempContent;

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
		while (column < 14)
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

int build_display_movement(t_game *game)
{
	char *str;
	str = ft_itoa(game->player->moved);
	mlx_string_put(game->mlx,game->window,10,15,0xFF99FF,str);
	return (0);
}
