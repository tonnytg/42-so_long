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

void	put_player(t_game *game, int x, int y)
{
	put_image(game, game->images->player, x, y);
	game->player->x = x;
	game->player->y = y;
}

int	build_map(t_game *game)
{
	int	column;
	int	line;

	line = 0;
	while (line < game->map->count_lines)
	{
		column = 0;
		while (column < game->map->count_columns)
		{
			if (game->map->location[line][column] == '1')
				put_image(game, game->images->wall, column, line);
			if (game->map->location[line][column] == 'C')
				put_image(game, game->images->collectible, column, line);
			if (game->map->location[line][column] == 'E')
				put_image(game, game->images->exit, column, line);
			if (game->map->location[line][column] == 'P')
				put_player(game, column, line);
			column++;
		}
		line++;
	}
	build_display_movement(game);
	return (0);
}

static void	ft_init_map(t_game *game, char **argv)
{
	int	x;
	int	y;

	game->map->fd = open(argv[1], O_RDONLY);
	game->map->location = malloc(sizeof(int *) * game->map->count_lines);
	x = 0;
	while ( x < game->map->count_lines)
	{
		game->map->location[x] = malloc(sizeof(int) * game->map->count_columns);
		x++;
	}
	x = 0;
	while (x < game->map->count_lines)
	{
		y = 0;
		while (y < game->map->count_columns)
		{
			game->map->location[x][y] = 0;
			y++;
		}
		x++;
	}
}

int	load_map(char **argv, t_game *game)
{
	int		column;
	int		line;
	char	*tempContent;

	ft_init_map(game, argv);
	tempContent = get_next_line(game->map->fd);
	if (tempContent == NULL)
		return (1);
	line = 0;
	while (line <= game->map->count_lines)
	{
		column = 0;
		while (column <= game->map->count_columns)
		{
			if (tempContent[column] != '\n')
				game->map->location[line][column] = tempContent[column];
			column++;
		}
		free(tempContent);
		tempContent = get_next_line(game->map->fd);
		if (tempContent == NULL)
			return (0);
		line++;
	}
	return (0);
}

int	build_display_movement(t_game *game)
{
	char	*str;

	str = NULL;
	str = ft_itoa(game->player->moved);
	if (!str)
	{
		free(str);
		return (1);
	}
	mlx_string_put(game->mlx, game->window, 10, 15, 0xFF99FF, str);
	free(str);
	return (0);
}
