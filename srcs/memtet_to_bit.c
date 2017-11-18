/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memtet_to_bit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 08:42:49 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/16 09:41:56 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char			max(char a, char b)
{
	return (a < b ? b : a);
}

static t_uint64_t	do_mask(t_tetriminos *tet)
{
	t_uint64_t	mask;
	t_uint16_t	*it;

	mask = 0;
	it = (t_uint16_t *)(&mask);
	it[(short)tet->crds[0].y] |= 1L << tet->crds[0].x;
	it[(short)tet->crds[1].y] |= 1L << tet->crds[1].x;
	it[(short)tet->crds[2].y] |= 1L << tet->crds[2].x;
	it[(short)tet->crds[3].y] |= 1L << tet->crds[3].x;
	return (mask);
}

static void			tet_feed_mask(t_tetriminos *tet)
{
	tet->l = max(tet->crds[0].x, tet->crds[1].x);
	tet->l = max(tet->l, tet->crds[2].x);
	tet->l = max(tet->l, tet->crds[3].x);
	tet->h = max(tet->crds[0].y, tet->crds[1].y);
	tet->h = max(tet->h, tet->crds[2].y);
	tet->h = max(tet->h, tet->crds[3].y);
	tet->mask = do_mask(tet);
}

void				feed_mask(t_memtet *memtet)
{
	short i;

	while (i < memtet->nb_tet)
	{
		tet_feed_mask(&(memtet->ltet[i]));
		i++;
	}
}
