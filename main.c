/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:08:16 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/13 19:57:25 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>

static void	init_memtet(t_memtet *memtet)
{
	short	i;

	i = 0;
	memtet->c = 2;
	memtet->l = 0;
	while (i < 26)
	{
		memtet->ltet[i].crds[0].x = 0;
		memtet->ltet[i].crds[0].y = 0;
		memtet->ltet[i].crds[1].x = 0;
		memtet->ltet[i].crds[1].y = 0;
		memtet->ltet[i].crds[2].x = 0;
		memtet->ltet[i].crds[2].y = 0;
		memtet->ltet[i].crds[3].x = 0;
		memtet->ltet[i].crds[3].y = 0;
		memtet->lcrds[i].x = 0;
		memtet->lcrds[i].y = 0;
		i++;
	}
}

int			main(int argc, const char *argv[])
{
	t_memtet	memtet;
	int			fd;
	int			lw;

	init_memtet(&memtet);
	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) < 0)
	{
		lw = write(2, "error\n", 6);
		(void)lw;
		return (2);
	}
	parse_input(&memtet, fd);
	move_corner(&memtet);
	if (!is_correct(&memtet))
		exit_close(fd);
	resolve(&memtet);
	print_ltet_res(&memtet);
	close(fd);
	return (0);
}
