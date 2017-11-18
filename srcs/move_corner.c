/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_corner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:39:58 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/13 19:55:43 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	move_corner_aux(t_tetriminos *tet)
{
	while (tet->crds[0].x && tet->crds[1].x &&
			tet->crds[2].x && tet->crds[3].x)
	{
		tet->crds[0].x--;
		tet->crds[1].x--;
		tet->crds[2].x--;
		tet->crds[3].x--;
	}
	while (tet->crds[0].y && tet->crds[1].y &&
			tet->crds[2].y && tet->crds[3].y)
	{
		tet->crds[0].y--;
		tet->crds[1].y--;
		tet->crds[2].y--;
		tet->crds[3].y--;
	}
}

void		move_corner(t_memtet *memtet)
{
	short	i;

	i = 0;
	while (i < memtet->nb_tet)
	{
		move_corner_aux(&(memtet->ltet[i]));
		i++;
	}
}
