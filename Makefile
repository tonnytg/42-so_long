SRC=./src

all:
	make -C $(SRC)/minilibx
	clang -o main $(SRC)/*.c src/minilibx/libmlx.a

clean:
	rm -f main

fclean: clean
	rm -f main

re:
	make fclean
	make all

.PHONY: all clean fclean re