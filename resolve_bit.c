/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_bit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 08:37:15 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/16 08:54:06 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	toggle_tet(uint64_t mask, uint16_t *map, short x, short y)
{
	*((uint64_t *)(map + y)) ^= (mask << x);
}

static uint64_t	chek_map(uint64_t mask, uint16_t *map, short x, short y)
{
	return (!((*(uint64_t *)(map + y)) & (mask << x)));
}

static char	resolve_bit_aux(t_memtet_bit *memtet, uint16_t *map, short p)
{
	short	xi;
	short	yi;
	t_tetriminos_bit tet;

	tet = memtet->ltet[p];
	yi = 0;
	while (yi + tet.h < memtet->c)
	{
		xi = 0;
		while (xi + tet.l < memtet->c)
		{
			if (chek_map(tet.mask, map, xi, yi))
			{
				memtet->lcrds[p].x = xi;
				memtet->lcrds[p].y = yi;
				toggle_tet(tet.mask, map, xi, yi);
				if (p + 1 == memtet->l)
					return (1);
				else if (resolve_bit_aux(memtet, map, p + 1))
					return (1);
				toggle_tet(tet.mask, map, xi, yi);
			}
			xi++;
		}
		yi++;
	}
	return (0);
}

void		resolve_bit(t_memtet_bit *memtet)
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
