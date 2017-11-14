/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_resolve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:25:47 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/14 09:04:57 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
static char	can_pose(t_memtet *memtet, short p, short x, short y)
{
	short	k;
	short	xi;
	short	yi;

	k = 0;
	while (k < 4)
	{
		xi = x + memtet->ltet[p].crds[k].x;
		yi = y + memtet->ltet[p].crds[k].y;
		if (xi >= memtet->c || yi >= memtet->c)
			return (0);
		if (inter_ltet(memtet, p, xi, yi))
			return (0);
		k++;
	}
	return (1);
}

static char	resolve_aux(t_memtet *memtet, short p)
{
	short	xi;
	short	yi;

	yi = 0;
	while (yi < memtet->c)
	{
		xi = 0;
		while (xi < memtet->c)
		{
			if (can_pose(memtet, p, xi, yi))
			{
				memtet->lcrds[p].x = xi;
				memtet->lcrds[p].y = yi;
				if (p + 1 == memtet->l)
					return (1);
				else if (resolve_aux(memtet, p + 1))
					return (1);
			}
			xi++;
		}
		yi++;
	}
	return (0);
}
*/
void		resolve(t_memtet *memtet)
{
	/*
	memtet->c = 2;
	while (memtet->c * memtet->c < 4 * memtet->l)
		memtet->c++;
	while (!resolve_aux(memtet, 0))
		memtet->c++;
	*/
	size_t i;

	i = 0;
	t_memtet_bit memtet_bit;
	memtet_to_bit(&memtet_bit, memtet);
	while (i < 26)
	{
		memtet->lcrds[i].x = memtet_bit.lcrds[i].x;
		memtet->lcrds[i].y = memtet_bit.lcrds[i].y;
		i++;
	}
}
