#include "so_long.h"

int	destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	printf("test %s\n", (char *)game);
	exit(0);
}

int	key_event(int key)
{
	printf("key=%d\n", key);
	if (key == ESC)
		exit(0);
	if (key == UP)
		exit(0);
	if (key == DOWN)
		exit(0);
	if (key == LEFT)
		exit(0);
	if (key == RIGHT)
		exit(0);
	return (0);
}

int	main(void)
{
	t_game	game;
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		printf("Error: mlx_init() returned NULL");
	game.window = mlx_new_window(game.mlx, 350, 250, "Hello world!");
	mlx_hook(game.window, 17, 1L << 2, destroy_window, &game);
	mlx_key_hook(game.window, key_event, 0);
	mlx_loop(game.mlx);
	return (0);
}
