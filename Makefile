NAME = "so_long"
SRC = ./src
FILES = $(SRC)/*.c
CC_FLAGS = -Wall -Wextra -Werror -Wpedantic -std=c99 -g3
LIB_FLAGS = -I src/minilibx -lXext -lX11 -lmlx -L src/minilibx

all: $(NAME)

$(NAME):
	@make -C $(SRC)/minilibx
	@clang $(CC_FLAGS) $(FILES) $(LIB_FLAGS) -o $(NAME)

clean:
	rm -f $(NAME)
	@make -C $(SRC)/minilibx clean

fclean: clean
	@make -C $(SRC)/minilibx fclean

re: fclean all

.PHONY: all clean fclean re