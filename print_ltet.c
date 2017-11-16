/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ltet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:05:05 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/16 08:47:41 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

void		put_tetriminos(t_tetriminos tet)
{
	short	xi;
	short	yi;

	yi = 0;
	while (yi < 4)
	{
		xi = 0;
		while (xi < 4)
		{
			if (inter_tet(&tet, xi, yi))
				ft_putchar('#');
			else
				ft_putchar('.');
			xi++;
		}
		ft_putchar('\n');
		yi++;
	}
}

void		print_ltet(t_memtet *memtet)
{
	short	k;

	k = 0;
	while (k < memtet->l)
	{
		put_tetriminos(memtet->ltet[k]);
		ft_putchar('\n');
		k++;
	}
}
