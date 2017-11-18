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

static inline void			toggle_tet(t_tetriminos *tet, t_uint16_t *map)
{
	*((t_uint64_t *)(map + tet->y)) ^= (tet->mask << tet->x);
}

static inline t_uint64_t	chek_map(t_tetriminos *tet, t_uint16_t *map)
{
	return (!((*(t_uint64_t *)(map + tet->y)) & (tet->mask << tet->x)));
}

static char					resolve_aux(t_memtet *mtet,
	t_uint16_t *map, short p)
{
	t_tetriminos	*tet;

	tet = &(mtet->ltet[p]);
	tet->y = (tet->i_last >= 0 ? mtet->ltet[tet->i_last].y : 0);
	tet->x = (tet->i_last >= 0 ? mtet->ltet[tet->i_last].x + 1 : 0);
	while (tet->y + tet->h < mtet->c)
	{
		while (tet->x + tet->l < mtet->c)
		{
			if (chek_map(tet, map))
			{
				toggle_tet(tet, map);
				if (p + 1 == mtet->nb_tet)
					return (1);
				else if (resolve_aux(mtet, map, p + 1))
					return (1);
				toggle_tet(tet, map);
			}
			tet->x++;
		}
		tet->x = 0;
		tet->y++;
	}
	return (0);
}

void						resolve(t_memtet *mtet)
{
	t_uint16_t map[16];

	ft_bzero(map, sizeof(t_uint16_t) * 16);
	mtet->c = 2;
	while (mtet->c * mtet->c < 4 * mtet->nb_tet)
		mtet->c++;
	while (!resolve_aux(mtet, map, 0) && mtet->c < 16)
	{
		ft_bzero(map, sizeof(t_uint16_t) * 16);
		mtet->c++;
	}
}
