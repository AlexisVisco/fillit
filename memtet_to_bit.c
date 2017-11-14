/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memtet_to_bit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 08:42:49 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/14 16:30:08 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include	<stdio.h>

static char	max(char a, char b)
{
	return (a < b ? b : a);
}

static uint64_t	do_mask(t_tetriminos tet)
{
	uint64_t	mask;
	uint16_t	*it;

	mask = 0;
	it = (uint16_t *)(&mask);
	it[(short)tet.crds[0].y] |= 1L << tet.crds[0].x;
	it[(short)tet.crds[1].y] |= 1L << tet.crds[1].x;
	it[(short)tet.crds[2].y] |= 1L << tet.crds[2].x;
	it[(short)tet.crds[3].y] |= 1L << tet.crds[3].x;
	return (mask);
}

static t_tetriminos_bit	tet_to_bit(t_tetriminos tet)
{
	t_tetriminos_bit	tet_bit;

	tet_bit.l = max(tet.crds[0].x, tet.crds[1].x);
	tet_bit.l = max(tet_bit.l, tet.crds[2].x);
	tet_bit.l = max(tet_bit.l, tet.crds[3].x);

	tet_bit.h = max(tet.crds[0].y, tet.crds[1].y);
	tet_bit.h = max(tet_bit.h, tet.crds[2].y);
	tet_bit.h = max(tet_bit.h, tet.crds[3].y);

	tet_bit.mask = do_mask(tet);

	printf("%u\n", *((uint16_t *)(&tet_bit.mask)));
	printf("%u\n", *((uint16_t *)(&tet_bit.mask) + 1));
	printf("%u\n", *((uint16_t *)(&tet_bit.mask) + 2));
	printf("%u\n", *((uint16_t *)(&tet_bit.mask) + 3));
	printf("---\n");
	return (tet_bit);
}

void	memtet_to_bit(t_memtet_bit *memtet_bit, t_memtet *memtet)
{
	short i;

	i = 0;
	memtet_bit->c = memtet->c;
	memtet_bit->l = memtet->l;
	print_ltet(memtet);
	while (i < memtet->l)
	{
		memtet_bit->lcrds[i].x = memtet->lcrds[i].x;
		memtet_bit->lcrds[i].y = memtet->lcrds[i].y;
		memtet_bit->ltet[i] = tet_to_bit(memtet->ltet[i]);
		i++;
	}
}