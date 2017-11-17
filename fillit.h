/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:26:00 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/16 09:38:13 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef unsigned short int			t_uint16_t;
typedef unsigned long long int		t_uint64_t;
typedef unsigned long int			t_size_t;

typedef struct s_coord				t_coord;
typedef struct s_tetriminos			t_tetriminos;
typedef struct s_memtet				t_memtet;
typedef struct s_tetriminos_bit		t_tetriminos_bit;
typedef struct s_memtet_bit			t_memtet_bit;

struct	s_coord
{
	char	x;
	char	y;
};

struct	s_tetriminos
{
	t_coord	crds[4];
	char	x;
	char	y;
};

struct	s_memtet
{
	t_tetriminos	ltet[26];
	char			l;
	char			c;
};

struct	s_tetriminos_bit
{
	t_uint64_t	mask;
	char		x;
	char		y;
	char		l;
	char		h;
};

struct	s_memtet_bit
{
	t_tetriminos_bit	ltet[26];
	char				l;
	char				c;
};

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
void	ft_bzero(void *s, t_size_t n);
void	init_memtet(t_memtet *memtet);

#endif
