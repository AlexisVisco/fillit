/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_resolve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:25:47 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/16 08:45:20 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		resolve(t_memtet *mtet)
{
	short			i;
	t_memtet_bit	mtet_bit;

	i = 0;
	memtet_to_bit(&mtet_bit, mtet);
	resolve_bit(&mtet_bit);
	mtet->c = mtet_bit.c;
	while (i < mtet->l)
	{
		mtet->ltet[i].x = mtet_bit.ltet[i].x;
		mtet->ltet[i].y = mtet_bit.ltet[i].y;
		i++;
	}
}
