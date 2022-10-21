SRC=./src

all:
	make -C $(SRC)/minilibx
	clang $(SRC)/main.c -I src/minilibx -lXext -lX11 -lmlx -L src/minilibx  -o main

clean:
	rm -f main

fclean: clean
	rm -f main

re:
	make fclean
	make all

.PHONY: all clean fclean re