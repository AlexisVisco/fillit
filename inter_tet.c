/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_tet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:26:20 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/13 19:55:26 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	inter_ltet(t_memtet *memtet, short p, short x, short y)
{
	short	k;

	k = 0;
	while (k < p)
	{
		if (inter_tet(&memtet->ltet[k],
			x - memtet->ltet[k].x,
			y - memtet->ltet[k].y))
			return (1);
		k++;
	}
	return (0);
}

char	inter_tet(t_tetriminos *tet, short x, short y)
{
	short	k;

	k = 0;
	while (k < 4)
	{
		if (tet->crds[k].x == x && tet->crds[k].y == y)
			return (1);
		k++;
	}
	return (0);
}
