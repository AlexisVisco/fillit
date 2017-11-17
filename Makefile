# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cepalle <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 08:52:55 by cepalle           #+#    #+#              #
#    Updated: 2017/11/16 10:09:02 by cepalle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
NAME= fillit
CFLAGS= -Wall -Wextra -Werror
SRC= exit_close.c parse_input.c resolve.c main.c print_ltet.c is_correct.c \
	 move_corner.c print_ltet_res.c inter_tet.c ft_putchar.c resolve_bit.c \
	 memtet_to_bit.c ft_bzero.c init_memtet.c

OBJ= $(SRC:.c=.o)

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $^ $(CFLAGS) -o $@

clean:
	rm -f $(OBJ)

re: fclean all

fclean: clean
	rm -f $(NAME)
