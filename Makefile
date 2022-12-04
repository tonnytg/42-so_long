SRC=./src

all:
	make -C $(SRC)/minilibx
	clang $(SRC)/main.c $(SRC)/get_next_line.c $(SRC)/utils.c -I src/minilibx -lXext -lX11 -lmlx -L src/minilibx  -o main

clean:
	rm -f main

fclean: clean
	rm src/minilibx/libmlx_Darwin.a
	rm src/minilibx/libmlx.a
	rm src/minilibx/test/main.o
	rm src/minilibx/test/mlx-test
	rm -rf src/minilibx/obj/

re:
	make fclean
	make all

.PHONY: all clean fclean re