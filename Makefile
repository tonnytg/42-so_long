NAME = "so_long"
SRC = ./src
FILES = $(SRC)/*.c
CC_FLAGS = -Wall -Wextra -Werror -Wpedantic -std=c99 -g3

all:
	make -C $(SRC)/minilibx
	clang $(CC_FLAGS) $(FILES) -I src/minilibx -lXext -lX11 -lmlx -L src/minilibx  -o $(NAME)

$(NAME): all

clean:
	rm -f $(NAME)

fclean: clean
	rm src/minilibx/libmlx_Darwin.a
	rm src/minilibx/libmlx.a
	rm src/minilibx/test/main.o
	rm src/minilibx/test/mlx-test
	rm -rf src/minilibx/obj/

re:
	make fclean
	make all

debug: all
	leaks --atExit --list -- ./so_long src/maps/map.ber

.PHONY: all clean fclean re