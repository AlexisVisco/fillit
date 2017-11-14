/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_resolve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:25:47 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/14 18:56:17 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		resolve(t_memtet *memtet)
{
	short			i;
	t_memtet_bit	memtet_bit;

	i = 0;
	memtet_to_bit(&memtet_bit, memtet);
	printf("1\n");
	resolve_bit(&memtet_bit);
	printf("2\n");
	memtet->c = memtet_bit.c;
	printf("3\n");
	while (i < memtet->l)
	{
		memtet->lcrds[i].x = memtet_bit.lcrds[i].x;
		memtet->lcrds[i].y = memtet_bit.lcrds[i].y;
		i++;
	}
}
