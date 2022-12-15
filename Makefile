# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 13:48:03 by antthoma          #+#    #+#              #
#    Updated: 2022/12/15 04:09:33 by antthoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		so_long
HEADER		=		$(NAME).h
CC			=		clang
FILES 		=		init.c 			\
					events.c 		\
					check_path.c	\
					get_next_line.c \
					utils.c 		\
					utils_math.c 	\
					map.c 			\
					map_read_file.c	\
					window.c 		\
					images.c 		\
					main.c
OBJ 		=		$(FILES:.c=.o)
MINILIBX	= 		./minilibx/libmlx_Linux.a
CFLAGS		= 		-Wall -Wextra -Werror -Wpedantic -g3
LIB_FLAGS	=		-I minilibx -lXext -lX11 -lmlx -L minilibx

all:$(NAME)

$(NAME): $(OBJ) $(MINILIBX)
	${CC} ${CFLAGS} $(FILES) -I ./minilibx -lXext -lX11 -lmlx -L ./minilibx  -o $(NAME)

$(OBJ):
	$(CC) $(CFLAGS) -c $(FILES) -I ./$(HEADER)

$(MINILIBX):
	git clone https://github.com/42Paris/minilibx-linux.git minilibx
	cd ./minilibx && ./configure

clean:
	rm -f $(NAME)
	rm -f $(OBJ)

fclean: clean
	rm -rf ./minilibx

debug: re
	leaks $(NAME) --atExit -- ./$(NAME) map.ber

re: fclean all

.PHONY: all clean fclean re