/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ltet_res.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.le101.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:59:58 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/20 10:09:09 by aviscogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	print_inter(t_memtet *memtet, short x, short y)
{
	short	k;

	k = 0;
	while (k < memtet->nb_tet)
	{
		if (touch_tet(&memtet->ltet[k],
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
	while (yi < memtet->size_square)
	{
		xi = 0;
		while (xi < memtet->size_square)
		{
			print_inter(memtet, xi, yi);
			xi++;
		}
		ft_putchar('\n');
		yi++;
	}
}
