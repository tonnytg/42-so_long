#include "so_long.h"

int map_rules(t_game *game, char *line, int x)
{
	if (line[x] == 'C')
		game->map->count_collectibles++;
	if (x > game->map->count_columns)
		game->map->count_columns = x;
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
			map_rules(game, line, x);
		free(line);
		line = get_next_line(game->map->fd);
	}
	return (0);
}
