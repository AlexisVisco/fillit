/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_correct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.le101.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:26:38 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/20 10:08:58 by aviscogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	has_two_neighbour(t_tetriminos *tet, short x, short y)
{
	short	nbv;

	nbv = 0;
	nbv += (touch_tet(tet, x + 1, y) && touch_tet(tet, x + 2, y));
	nbv += (touch_tet(tet, x + 1, y) && touch_tet(tet, x + 1, y + 1));
	nbv += (touch_tet(tet, x + 1, y) && touch_tet(tet, x + 1, y - 1));
	nbv += (touch_tet(tet, x - 1, y) && touch_tet(tet, x - 2, y));
	nbv += (touch_tet(tet, x - 1, y) && touch_tet(tet, x - 1, y + 1));
	nbv += (touch_tet(tet, x - 1, y) && touch_tet(tet, x - 1, y - 1));
	nbv += (touch_tet(tet, x, y + 1) && touch_tet(tet, x, y + 2));
	nbv += (touch_tet(tet, x, y + 1) && touch_tet(tet, x + 1, y + 1));
	nbv += (touch_tet(tet, x, y + 1) && touch_tet(tet, x - 1, y + 1));
	nbv += (touch_tet(tet, x, y - 1) && touch_tet(tet, x, y - 2));
	nbv += (touch_tet(tet, x, y - 1) && touch_tet(tet, x + 1, y - 1));
	nbv += (touch_tet(tet, x, y - 1) && touch_tet(tet, x - 1, y - 1));
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
		nbv = touch_tet(tet, x + 1, y) + touch_tet(tet, x, y + 1);
		nbv += touch_tet(tet, x - 1, y) + touch_tet(tet, x, y - 1);
		if (nbv >= 2)
			return (1);
		nbv = has_two_neighbour(tet, x, y);
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
		it += touch_tet(tet, tet->crds[k].x + 1, tet->crds[k].y);
		it += touch_tet(tet, tet->crds[k].x, tet->crds[k].y + 1);
		it += touch_tet(tet, tet->crds[k].x - 1, tet->crds[k].y);
		it += touch_tet(tet, tet->crds[k].x, tet->crds[k].y - 1);
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
	while (k < memtet->nb_tet)
	{
		if (!is_not_alone(&memtet->ltet[k]))
			return (0);
		if (!is_not_tow(&memtet->ltet[k]))
			return (0);
		k++;
	}
	return (1);
}
