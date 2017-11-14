NAME= fillit
LIB= libft/libft.a
CFLAGS= -Wall -Wextra -Werror -O3
SRC= exit_close.c parse_input.c resolve.c main.c print_ltet.c is_correct.c \
	 move_corner.c print_ltet_res.c inter_tet.c ft_putchar.c resolve_bit.c \
	 memtet_to_bit.c

all:$(NAME) $(LIB)

$(NAME):$(SRC)
	gcc $(CFLAGS) -o $(NAME) $(SRC)  -L./libft/ -lft

$(LIB):
	make -C libft/ all clean

clean:

re: fclean all

fclean: clean
	rm -f $(NAME)

test:all
	./fillit test/sample00.fillit
	./fillit test/sample01.fillit
	./fillit test/sample02.fillit
	./fillit test/sample03.fillit

