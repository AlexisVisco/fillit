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

NAME= fillit
CC= gcc
CFLAGS= -Wall -Wextra -Werror

INCLUDEDIR=includes/
CFILENAME= exit_close.c parse_input.c resolve.c main.c print_ltet.c \
	 is_correct.c move_corner.c print_ltet_res.c inter_tet.c ft_putchar.c \
	 double_handler.c feed_mask.c ft_bzero.c init_memtet.c

SRCDIR=srcs/
SRC=$(addprefix $(SRCDIR), $(CFILENAME))

OBJDIR=objs/
OBJ= $(addprefix $(OBJDIR), $(CFILENAME:.c=.o))


all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) -c $^ $(CFLAGS) -o $@ -I $(INCLUDEDIR)

clean:
	rm -f $(OBJ)

re: fclean all

fclean: clean
	rm -f $(NAME)
