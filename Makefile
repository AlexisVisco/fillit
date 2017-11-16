# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cepalle <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 08:52:55 by cepalle           #+#    #+#              #
#    Updated: 2017/11/16 08:53:43 by cepalle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit
CFLAGS= -Wall -Wextra -Werror
SRC= exit_close.c parse_input.c resolve.c main.c print_ltet.c is_correct.c \
	 move_corner.c print_ltet_res.c inter_tet.c ft_putchar.c resolve_bit.c \
	 memtet_to_bit.c ft_bzero.c

all:$(NAME)

$(NAME):$(SRC)
	gcc $(CFLAGS) -o $(NAME) $(SRC)

clean:

re: fclean all

fclean: clean
	rm -f $(NAME)

test:all
	./fillit test/sample00.fillit
	./fillit test/sample01.fillit
	./fillit test/sample02.fillit
	./fillit test/sample03.fillit

