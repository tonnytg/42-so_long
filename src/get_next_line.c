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

static char	*ft_check_cache(char *cache, char *line, int fd, int *x)
{
	cache = ft_read_buff(fd);
	*x = 0;
	if (!cache)
		if (line[0] == '\0')
			return (NULL);
	return (cache);
}

static char	*run_loop(char *cache, char *line, int *x, int *trigger)
{
	int	length;

	length = ft_strlen(cache);
	while (*x < length)
	{
		line = ft_char_append(line, cache[*x]);
		if (cache[*x] == '\n')
		{
			*trigger = 1;
			*x = *x + 1;
			break ;
		}
		*x = *x + 1;
	}
	return (line);
}

static char	*build_line(int fd)
{
	static char	*cache;
	char		*line;
	static int	x;
	int			trigger;

	line = ft_strdup("");
	trigger = 0;
	while (1)
	{
		if (!cache)
		{
			cache = ft_check_cache(cache, line, fd, &x);
		}
		if (!cache)
			return (line);
		line = run_loop(cache, line, &x, &trigger);
		if (trigger == 1)
			break ;
		free(cache);
		cache = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = build_line(fd);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
