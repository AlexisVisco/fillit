/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ltet_res.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:59:58 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/13 19:56:05 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	print_inter(t_memtet *memtet, short x, short y)
{
	short	k;

	k = 0;
	while (k < memtet->nb_tet)
	{
		if (inter_tet(&memtet->ltet[k],
			x - memtet->ltet[k].x,
			y - memtet->ltet[k].y))
		{
			ft_putchar('A' + k);
			return ;
		}
		k++;
	}
	ft_putchar('.');
}

void		print_ltet_res(t_memtet *memtet)
{
	short	xi;
	short	yi;

	yi = 0;
	while (yi < memtet->c)
	{
		xi = 0;
		while (xi < memtet->c)
		{
			print_inter(memtet, xi, yi);
			xi++;
		}
		ft_putchar('\n');
		yi++;
	}
}
