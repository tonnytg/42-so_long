/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:48:03 by antthoma          #+#    #+#             */
/*   Updated: 2022/12/28 00:50:14 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:48:03 by antthoma          #+#    #+#             */
/*   Updated: 2022/12/21 02:24:09 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_dfs(int column, int line, int *trigger, t_map *map)
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
	is_valid_dfs(column + 1, line, trigger, map);
	is_valid_dfs(column - 1, line, trigger, map);
	is_valid_dfs(column, line + 1, trigger, map);
	is_valid_dfs(column, line - 1, trigger, map);
	if (*trigger == 1)
		return (1);
	return (0);
}

int	check_path(t_game *game)
{
	int		line;
	int		column;
	int		trigger;
	int		check;
	t_map	*map;

	trigger = 0;
	check = 0;
	map = game->map;
	column = game->player->x;
	line = game->player->y;
	check = is_valid_dfs(column, line, &trigger, map);
	if (check == 1)
		return (0);
	return (1);
}
