#include "so_long.h"

int	check_rules(t_game *game)
{
	if (game->map->count_columns == game->map->count_lines ||
		game->map->count_columns < 2 ||
		game->map->count_lines < 2)
		return (1);
	if (game->map->count_collectibles == 0 ||
		game->map->count_exits != 1 ||
		game->map->count_player != 1)
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
		while (line[x++] != '\0')
			map_count_itens(game, line, x);
		free(line);
		line = get_next_line(game->map->fd);
	}
	if (check_rules(game))
		return (1);
	return (0);
}
