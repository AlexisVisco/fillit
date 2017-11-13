/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_correct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:26:38 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/13 21:17:16 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	cal_nbv_2(t_tetriminos *tet, short x, short y)
{
	short	nbv;

	nbv = 0;
	nbv += (inter_tet(tet, x + 1, y) && inter_tet(tet, x + 2, y));
	nbv += (inter_tet(tet, x + 1, y) && inter_tet(tet, x + 1, y + 1));
	nbv += (inter_tet(tet, x + 1, y) && inter_tet(tet, x + 1, y - 1));
	nbv += (inter_tet(tet, x - 1, y) && inter_tet(tet, x - 2, y));
	nbv += (inter_tet(tet, x - 1, y) && inter_tet(tet, x - 1, y + 1));
	nbv += (inter_tet(tet, x - 1, y) && inter_tet(tet, x - 1, y - 1));
	nbv += (inter_tet(tet, x, y + 1) && inter_tet(tet, x, y + 2));
	nbv += (inter_tet(tet, x, y + 1) && inter_tet(tet, x + 1, y + 1));
	nbv += (inter_tet(tet, x, y + 1) && inter_tet(tet, x - 1, y + 1));
	nbv += (inter_tet(tet, x, y - 1) && inter_tet(tet, x, y - 2));
	nbv += (inter_tet(tet, x, y - 1) && inter_tet(tet, x + 1, y - 1));
	nbv += (inter_tet(tet, x, y - 1) && inter_tet(tet, x - 1, y - 1));
	return (nbv);
}

static char	is_not_tow(t_tetriminos *tet)
{
	short	k;
	char	x;
	char	y;
	short	nbv;

	k = 0;
	while (k < 4)
	{
		x = tet->crds[k].x;
		y = tet->crds[k].y;
		nbv = inter_tet(tet, x + 1, y) + inter_tet(tet, x, y + 1);
		nbv += inter_tet(tet, x - 1, y) + inter_tet(tet, x, y - 1);
		if (nbv >= 2)
			return (1);
		nbv = cal_nbv_2(tet, x, y);
		if (!nbv)
			return (0);
		k++;
	}
	return (1);
}

static char	is_not_alone(t_tetriminos *tet)
{
	short	k;
	short	it;

	k = 0;
	while (k < 4)
	{
		it = 0;
		it += inter_tet(tet, tet->crds[k].x + 1, tet->crds[k].y);
		it += inter_tet(tet, tet->crds[k].x, tet->crds[k].y + 1);
		it += inter_tet(tet, tet->crds[k].x - 1, tet->crds[k].y);
		it += inter_tet(tet, tet->crds[k].x, tet->crds[k].y - 1);
		if (!it)
			return (0);
		k++;
	}
	return (1);
}

char		is_correct(t_memtet *memtet)
{
	short	k;

	k = 0;
	while (k < memtet->l)
	{
		if (!is_not_alone(&memtet->ltet[k]))
			return (0);
		if (!is_not_tow(&memtet->ltet[k]))
			return (0);
		k++;
	}
	return (1);
}
