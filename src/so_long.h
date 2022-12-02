//
// Created by Antonio Thomacelli on 01/12/22.
//
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef INC_42_SO_LONG_SO_LONG_H
#define INC_42_SO_LONG_SO_LONG_H

#define ESC 65307
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363

typedef struct s_game
{
	void	*mlx;
	void	*window;
}	t_game;

#endif //INC_42_SO_LONG_SO_LONG_H
