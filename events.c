/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:48:03 by antthoma          #+#    #+#             */
/*   Updated: 2022/12/21 03:34:38 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_key(t_game *game, int oldX, int oldY)
{
	if ((game->map->location[game->player->y][game->player->x] == '1') ||
		(game->map->location[game->player->y][game->player->x] == 'E' &&
		 game->player->collected != game->map->count_collectibles))
	{
		game->player->x = oldX;
		game->player->y = oldY;
	}
	else
	{
		if (game->map->location[game->player->y][game->player->x] == 'C')
			game->player->collected++;
		if (game->map->location[game->player->y][game->player->x] == 'E')
		{
			if (game->player->collected == game->map->count_collectibles)
			{
				ft_putstr("You Win!\n");
				destroy_window(game);
			}
		}
		game->map->location[oldY][oldX] = '0';
		game->map->location[game->player->y][game->player->x] = 'P';
		game->player->moved++;
	}
}

int	key_press(int keycode, t_game *game)
{
	int	old_x;
	int	old_y;

	old_x = game->player->x;
	old_y = game->player->y;
	if (keycode == ESC)
		destroy_window(game);
	if (keycode == UP)
		game->player->y--;
	if (keycode == DOWN)
		game->player->y++;
	if (keycode == LEFT)
		game->player->x--;
	if (keycode == RIGHT)
		game->player->x++;
	ft_check_key(game, old_x, old_y);
	mlx_clear_window(game->mlx, game->window);
	build_map(game);
	return (0);
}

int	expose_hook(t_game *game)
{
	build_map(game);
	return (0);
}
