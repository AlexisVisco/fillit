/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_bit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 08:37:15 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/16 09:34:28 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		toggle_tet(uint64_t mask, uint16_t *map, short x, short y)
{
	*((uint64_t *)(map + y)) ^= (mask << x);
}

static uint64_t	chek_map(uint64_t mask, uint16_t *map, short x, short y)
{
	return (!((*(uint64_t *)(map + y)) & (mask << x)));
}

static char		resolve_bit_aux(t_memtet_bit *mtet, uint16_t *map, short p)
{
	mtet->lcrds[p].y = 0;
	while (mtet->lcrds[p].y + mtet->ltet[p].h < mtet->c)
	{
		mtet->lcrds[p].x = 0;
		while (mtet->lcrds[p].x + mtet->ltet[p].l < mtet->c)
		{
			if (chek_map(mtet->ltet[p].mask, map, mtet->lcrds[p].x,
						mtet->lcrds[p].y))
			{
				toggle_tet(mtet->ltet[p].mask, map, mtet->lcrds[p].x,
						mtet->lcrds[p].y);
				if (p + 1 == mtet->l)
					return (1);
				else if (resolve_bit_aux(mtet, map, p + 1))
					return (1);
				toggle_tet(mtet->ltet[p].mask, map, mtet->lcrds[p].y,
						mtet->lcrds[p].y);
			}
			mtet->lcrds[p].x++;
		}
		mtet->lcrds[p].y++;
	}
	return (0);
}

void			resolve_bit(t_memtet_bit *memtet)
{
	uint16_t map[16];

	ft_bzero(map, sizeof(uint16_t) * 16);
	memtet->c = 2;
	while (memtet->c * memtet->c < 4 * memtet->l)
		memtet->c++;
	while (!resolve_bit_aux(memtet, map, 0) && memtet->c < 16)
	{
		ft_bzero(map, sizeof(uint16_t) * 16);
		memtet->c++;
	}
}
