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

int			main(int argc, const char *argv[])
{
	t_memtet	memtet;
	int			fd;

	init_memtet(&memtet);
	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) < 0)
	{
		write(2, "error\n", 6);
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
