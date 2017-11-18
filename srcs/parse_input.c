/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_parse_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:25:33 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/13 20:00:29 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <unistd.h>

static int			feed_tet(t_coord *crd, short p, char c, int fd)
{
	if (p % 5 == 4 && c != '\n')
		exit_close(fd);
	if (p % 5 == 4)
		return (0);
	if (c == '#')
	{
		crd->x = p % 5;
		crd->y = p / 5;
		return (1);
	}
	if (c != '.')
		exit_close(fd);
	return (0);
}

static t_tetriminos	string_to_tet(char *str, int fd)
{
	short			xi;
	short			yi;
	short			k;
	t_tetriminos	tet;

	yi = 0;
	k = 0;
	while (yi < 4)
	{
		xi = 0;
		while (xi < 5)
		{
			k += feed_tet(&(tet.crds[k]), yi * 5 + xi, str[yi * 5 + xi], fd);
			xi++;
		}
		yi++;
	}
	if (k != 4)
		exit_close(fd);
	return (tet);
}

static void			parse_tet(t_memtet *mtet, int fd)
{
	char	buff[21];
	int		len_read;

	if ((len_read = read(fd, buff, 20)) == -1)
		exit_close(fd);
	buff[len_read] = '\0';
	if (len_read != 20)
		exit_close(fd);
	mtet->ltet[(short)mtet->nb_tet] = string_to_tet(buff, fd);
	mtet->nb_tet++;
}

void				parse_input(t_memtet *mtet, int fd)
{
	char	c;
	int		len_read;

	parse_tet(mtet, fd);
	if ((len_read = read(fd, &c, 1)) == -1)
		exit_close(fd);
	if (!len_read)
		exit_close(fd);
	while (len_read)
	{
		if (c != '\n')
			exit_close(fd);
		parse_tet(mtet, fd);
		if ((len_read = read(fd, &c, 1)) == -1)
			exit_close(fd);
	}
	move_corner(mtet);
	feed_mask(mtet);
	double_handler(mtet);
	if (!is_correct(mtet))
		exit_close(fd);
}
