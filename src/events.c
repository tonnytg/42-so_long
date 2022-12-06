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

int	key_press(int keycode, t_game *game)
{
	int	oldX;
	int	oldY;

	oldX = game->player->x;
	oldY = game->player->y;
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
	if ((game->map->location[game->player->y][game->player->x] == '1') ||
		(game->map->location[game->player->y][game->player->x] == 'E' &&
		 game->player->collected != 1))
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
			if (game->player->collected == 1)
			{
				printf("\n\n\nYou win!\n");
				printf("With %d moves\n\n\n", game->player->moved);
				destroy_window(game);
			}
		}
		game->map->location[oldY][oldX] = '0';
		game->map->location[game->player->y][game->player->x] = 'P';
		game->player->moved++;
	}
	mlx_clear_window(game->mlx, game->window);
	build_map(game);
	return (0);
}
