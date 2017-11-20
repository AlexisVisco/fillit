/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.le101.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:26:00 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/20 09:34:44 by aviscogl         ###   ########.fr       */
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

struct	s_coord
{
	char	x;
	char	y;
};

struct	s_tetriminos
{
	t_coord		crds[4];
	t_uint64_t	mask;
	char		x;
	char		y;
	char		width;
	char		height;
	short		i_last;
};

struct	s_memtet
{
	t_tetriminos	ltet[26];
	char			nb_tet;
	char			size_square;
};

void	ft_putchar(char c);
void	ft_bzero(void *s, t_size_t n);
void	exit_close(int fd);

void	init_memtet(t_memtet *memtet);
void	parse_input(t_memtet *memtet, int fd);
void	move_corner(t_memtet *memtet);
void	feed_mask(t_memtet *memtet);
void	double_handler(t_memtet *mtet);
char	is_correct(t_memtet *memtet);
void	resolve(t_memtet *memtet);

void	print_ltet(t_memtet *memtet);
void	print_ltet_res(t_memtet *memtet);

char	inter_tet(t_tetriminos *tet, short i, short j);
char	inter_ltet(t_memtet *memtet, short p, short x, short y);

#endif
