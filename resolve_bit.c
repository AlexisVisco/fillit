/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_bit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 08:37:15 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/16 09:40:36 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline void			toggle_tet(t_tetriminos_bit *tet, t_uint16_t *map)
{
	*((t_uint64_t *)(map + tet->y)) ^= (tet->mask << tet->x);
}

static inline t_uint64_t	chek_map(t_tetriminos_bit *tet, t_uint16_t *map)
{
	return (!((*(t_uint64_t *)(map + tet->y)) & (tet->mask << tet->x)));
}

static char					resolve_bit_aux(t_memtet_bit *mtet,
	t_uint16_t *map, short p)
{
	t_tetriminos_bit	*tet;

	tet = &(mtet->ltet[p]);
	tet->y = 0;
	while (tet->y + tet->h < mtet->c)
	{
		tet->x = 0;
		while (tet->x + tet->l < mtet->c)
		{
			if (chek_map(tet, map))
			{
				toggle_tet(tet, map);
				if (p + 1 == mtet->l)
					return (1);
				else if (resolve_bit_aux(mtet, map, p + 1))
					return (1);
				toggle_tet(tet, map);
			}
			tet->x++;
		}
		tet->y++;
	}
	return (0);
}

void						resolve_bit(t_memtet_bit *mtet)
{
	t_uint16_t map[16];

	ft_bzero(map, sizeof(t_uint16_t) * 16);
	mtet->c = 2;
	while (mtet->c * mtet->c < 4 * mtet->l)
		mtet->c++;
	while (!resolve_bit_aux(mtet, map, 0) && mtet->c < 16)
	{
		ft_bzero(map, sizeof(t_uint16_t) * 16);
		mtet->c++;
	}
}
