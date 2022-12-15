#include "so_long.h"

int	check_rules(t_game *game)
{
	if (game->map->count_columns == game->map->count_lines
		|| game->map->count_columns < 2
		|| game->map->count_lines < 2)
		return (1);
	if (game->map->count_collectibles == 0
		|| game->map->count_exits != 1
		|| game->map->count_player != 1
		|| game->map->count_walls == 0
		|| game->map->count_wrong_c != 0)
		return (1);
	return (0);
}

static int	map_count_itens(t_game *game, char *line, int x)
{
	if (line[x] == 'C')
		game->map->count_collectibles++;
	else if (x > game->map->count_columns)
		game->map->count_columns = x;
	else if (line[x] == 'P')
		game->map->count_player++;
	else if (line[x] == 'E')
		game->map->count_exits++;
	else if (line[x] == '1')
		game->map->count_walls++;
	else if (line[x] == '0')
		game->map->count_floors++;
	else
		if (line[x] != '\n' && line[x] != 0)
			game->map->count_wrong_c++;
	return (0);
}

int	map_read_file(t_game *game, char **argv)
{
	int		x;
	char	*line;

	game->map->fd = open(argv[1], O_RDONLY);
	if (game->map->fd == -1)
		msg_error("Error\nMap file not found\n", game, 1);
	line = get_next_line(game->map->fd);
	if (line == NULL)
		msg_error("Error\nMap file empty\n", game, 1);
	game->map->count_lines = 0;
	while (line != NULL)
	{
		x = 0;
		game->map->count_lines++;
		while (line[x++] != '\0')
			map_count_itens(game, line, x);
		free(line);
		line = get_next_line(game->map->fd);
	}
	if (check_rules(game))
		msg_error("Error\nThis is not a valid map\n", game, 1);
	return (0);
}