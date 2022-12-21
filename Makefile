# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 13:48:03 by antthoma          #+#    #+#              #
#    Updated: 2022/12/21 03:41:46 by antthoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		so_long
HEADER		=		$(NAME).h
CC			=		clang
FILES 		=		events.c 		\
					get_next_line.c \
					utils.c 		\
					utils_math.c 	\
					map.c 			\
					map_read.c 		\
					window.c 		\
					sprites.c 		\
					valid_path.c	\
					clean.c			\
					main.c
OBJ 		=		$(FILES:.c=.o)
MINILIBX	= 		./minilibx/libmlx_Linux.a
CFLAGS		= 		-Wall -Wextra -Werror -Wpedantic -g3
LIB_FLAGS	=		-I minilibx -lXext -lX11 -lmlx -L minilibx

all:$(NAME)

$(NAME): $(OBJ) $(MINILIBX)
	${CC} ${CFLAGS} $(FILES) -I ./minilibx -lXext -lX11 -lmlx -L ./minilibx  -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $(FILES) -I ./$(HEADER)

$(MINILIBX):
	make -C minilibx

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make clean -C minilibx

re: fclean all

.PHONY: all clean fclean re