/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:26:00 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/14 09:11:50 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>

struct	s_coord
{
	char	x;
	char	y;
};

typedef struct s_coord	t_coord;

struct	s_tetriminos
{
	t_coord	crds[4];
};

typedef struct s_tetriminos	t_tetriminos;

struct	s_memtet
{
	t_tetriminos	ltet[26];
	t_coord			lcrds[26];
	char			l;
	char			c;
};

typedef struct s_memtet	t_memtet;

struct	s_tetriminos_bit
{
	uint64_t	mask;
	char		l;
	char		h;
};

typedef struct s_tetriminos_bit	t_tetriminos_bit;

struct	s_memtet_bit
{
	t_tetriminos_bit	ltet[26];
	t_coord				lcrds[26];
	char				l;
	char				c;
};

typedef struct s_memtet_bit	t_memtet_bit;

void	parse_input(t_memtet *memtet, int fd);
void	resolve(t_memtet *memtet);
void	resolve_bit(t_memtet_bit *memtet);
void	exit_close(int fd);
void	move_corner(t_memtet *memtet);
void	print_ltet(t_memtet *memtet);
void	print_ltet_res(t_memtet *memtet);
char	inter_tet(t_tetriminos *tet, short i, short j);
char	inter_ltet(t_memtet *memtet, short p, short x, short y);
void	ft_putchar(char c);
char	is_correct(t_memtet *memtet);
void	memtet_to_bit(t_memtet_bit *memtet_bit, t_memtet *memtet);

#endif
