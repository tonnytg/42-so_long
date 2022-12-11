/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:48:03 by antthoma          #+#    #+#             */
/*   Updated: 2022/12/12 00:20:50 by antthoma         ###   ########.fr       */
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
	return (0);
}

static int	map_count_itens(t_game *game, char *line, int x)
{
	if (line[x] == 'C')
		game->map->count_collectibles++;
	if (x > game->map->count_columns)
		game->map->count_columns = x;
	if (line[x] == 'P')
		game->map->count_player++;
	if (line[x] == 'E')
		game->map->count_exits++;
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
	int		x;
	char	*line;

	game->map->fd = open(argv[1], O_RDONLY);
	if (game->map->fd == -1)
		return (1);
	line = get_next_line(game->map->fd);
	if (line == NULL)
		return (1);
	game->map->count_lines = 0;
	while (line != NULL)
	{
		x = 0;
		game->map->count_lines++;
		while (line[x] != '\0')
		{
			map_count_itens(game, line, x);
			x++;
		}
		free(line);
		line = get_next_line(game->map->fd);
	}
	if (check_rules(game))
		return (1);
	return (0);
}
