/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_mask.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.le101.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 08:42:49 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/20 09:39:59 by aviscogl         ###   ########.fr       */
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
	it[(short)tet->crds[0].y] |= 1 << tet->crds[0].x;
	it[(short)tet->crds[1].y] |= 1 << tet->crds[1].x;
	it[(short)tet->crds[2].y] |= 1 << tet->crds[2].x;
	it[(short)tet->crds[3].y] |= 1 << tet->crds[3].x;
	return (mask);
}

static void			tet_feed_mask_lh(t_tetriminos *tet)
{
	tet->width = max(tet->crds[0].x, tet->crds[1].x);
	tet->width = max(tet->width, tet->crds[2].x);
	tet->width = max(tet->width, tet->crds[3].x);
	tet->height = max(tet->crds[0].y, tet->crds[1].y);
	tet->height = max(tet->height, tet->crds[2].y);
	tet->height = max(tet->height, tet->crds[3].y);
	tet->mask = do_mask(tet);
}

void				feed_mask(t_memtet *memtet)
{
	short i;

	i = 0;
	while (i < memtet->nb_tet)
	{
		tet_feed_mask_lh(&(memtet->ltet[i]));
		i++;
	}
}
