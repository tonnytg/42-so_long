/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:48:03 by antthoma          #+#    #+#             */
/*   Updated: 2022/12/02 13:48:21 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	readMap(t_map *map)
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
	printf("\n---\n");
	return (0);
}

int is_valid_dfs(int column, int line, int *trigger, t_map *map)
{
	if (*trigger == 1)
		return (1);
	if (map->location[line][column] == '1')
		return (0);
	if (map->location[line][column] == 'V')
		return (0);
	if (map->location[line][column] == 'E')
	{
		*trigger = 1;
		return (1);
	}
	map->location[line][column] = 'V';
	readMap(map);
	is_valid_dfs(column + 1, line, trigger, map);
	is_valid_dfs(column - 1, line, trigger, map);
	is_valid_dfs(column, line + 1, trigger, map);
	is_valid_dfs(column, line - 1, trigger, map);
	return (0);
}

int check_path(t_game *game)
{
	int line;
	int column;
	int trigger;

	trigger = 0;
	t_map *map;
	map = game->map;
	column = game->player->x;
	line = game->player->y;

	if (is_valid_dfs(column, line, &trigger, map) == 1)
		return (0);
	return (1);
}
