# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 13:48:03 by antthoma          #+#    #+#              #
#    Updated: 2022/12/28 23:50:49 by antthoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		so_long
HEADER		=		$(NAME).h
CC			=		clang
SRC			=		./src
FILES 		=		./src/events.c 		\
					./src/get_next_line.c \
					./src/utils.c 		\
					./src/utils_math.c 	\
					./src/map.c 			\
					./src/map2.c			\
					./src/read_map.c 		\
					./src/read_map2.c		\
					./src/window.c 		\
					./src/sprites.c 		\
					./src/valid_path.c	\
					./src/clean.c			\
					./src/error.c		\
					./src/init.c			\
					./src/main.c
OBJ 		=		$(FILES:.c=.o)
MINILIBX	= 		$(SRC)/minilibx/libmlx_Linux.a
CFLAGS		= 		-Wall -Wextra -Werror -Wpedantic -g3
LIB_FLAGS	=		-I minilibx -lXext -lX11 -lmlx -L minilibx

all:$(NAME)

$(NAME): $(OBJ) $(MINILIBX)
	${CC} ${CFLAGS} $(FILES) -I ./minilibx -lXext -lX11 -lmlx -L ./minilibx  -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $(FILES) -I ./$(HEADER)

$(MINILIBX):
	make -C $(SRC)/minilibx

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make clean -C $(SRC)/minilibx

re: fclean all

.PHONY: all clean fclean re