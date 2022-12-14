NAME = "so_long"
FILES = *.c
CC_FLAGS = -Wall -Wextra -Werror -g3
LIB_FLAGS = -I minilibx -lXext -lX11 -lmlx -L minilibx

all: $(NAME)

$(NAME):
	@make -C minilibx
	@clang $(CC_FLAGS) $(FILES) $(LIB_FLAGS) -o $(NAME)

clean:
	rm -f $(NAME)
	@make -C minilibx clean

fclean: clean
	@make -C minilibx fclean

re: fclean all

.PHONY: all clean fclean re