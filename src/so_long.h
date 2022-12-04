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

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define BUFFER_SIZE 42
# define PIXEL_SIZE 32

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_map
{
	int		**location;
}	t_map;

typedef struct s_images
{
	void	*floor;
	int		*wall;
	int		x;
	int		y;
	void	*collectible;
	void	*exit;
	void	*player;
}	t_images;

typedef struct s_player
{
	int x;
	int y;
} t_player;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	int				width;
	int				height;
	struct s_images	*images;
	struct s_map	*map;
	struct s_player	*player;
}	t_game;



char	*get_next_line(int fd);
int		ft_count_word(char *str, int *start);
size_t	ft_strlen(char const *str);
char	*ft_str_join(char const *s1, char const *s2);
char	*ft_split_str(char *str, int *start);
char	*get_data(int fd, char *data);
char	*ft_char_append(char *s1, char c);
char	*ft_read_buff(int fd);
char	*ft_strdup(char *str);
int buildMap(t_map *map, t_game *game, t_images *images, t_player *player);

#endif //SO_LONG_H
