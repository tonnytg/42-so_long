/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:48:03 by antthoma          #+#    #+#             */
/*   Updated: 2022/12/29 00:35:14 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rules(t_game *game)
{
	if ((game->map->count_columns == game->map->count_lines)
		|| game->map->count_columns < 2
		|| game->map->count_lines < 2)
		return (1);
	if (game->map->count_collectibles == 0
		|| game->map->count_exits != 1
		|| game->map->count_player != 1)
		return (1);
	if (game->map->count_wrong_c > 0)
		return (1);
	return (0);
}

int	map_count_itens(t_game *game, char *line, int x)
{
	if (line[x] == 'C')
		game->map->count_collectibles++;
	else if (x > game->map->count_columns)
		game->map->count_columns = x;
	else if (line[x] == 'P')
		game->map->count_player++;
	else if (line[x] == 'E')
		game->map->count_exits++;
	else if (line[x] == '0')
		game->map->count_zeros++;
	else if (line[x] == '1')
		game->map->count_walls++;
	else
	if (line[x] != '\n')
		game->map->count_wrong_c++;
	return (0);
}

int	check_map_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map->count_lines)
	{
		x = 0;
		if (y == 0 || y == (game->map->count_lines - 1))
		{
			while (x < game->map->count_columns)
			{
				if (game->map->location[y][x] != '1')
					return (1);
				x++;
			}
		}
		else
		if (game->map->location[y][0] != '1'
			|| game->map->location[y][game->map->count_columns - 1] != '1')
			return (1);
		y++;
	}
	return (0);
}

int	check_format_file(int argc, char **argv)
{
	int	total;

	if (argc != 2)
		return (1);
	total = ft_strlen(argv[1]);
	if (total != 0)
		if (argv[1][total - 1] == 'r')
			if (argv[1][total - 2] == 'e')
				if (argv[1][total - 3] == 'b')
					if (argv[1][total - 4] == '.')
						return (0);
	return (1);
}

int	read_map_file(t_game *game, char **argv)
{
	game->map->fd = open(argv[1], O_RDONLY);
	if (game->map->fd == -1)
		return (1);
	game->content = get_next_line(game->map->fd);
	if (game->content == NULL)
		return (1);
	game->map->count_lines = 0;
	while (game->content != NULL && game->error == 0)
	{
		game->x = 0;
		game->map->count_lines++;
		if (get_content_file(game))
			return (1);
		free(game->content);
		game->content = get_next_line(game->map->fd);
		if (game->content != NULL && game->content[0] == '\n')
		{
			game->error = 1;
			empty_get_next_line(game);
		}
	}
	if (check_rules(game))
		return (1);
	return (0);
}
