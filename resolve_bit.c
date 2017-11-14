/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_bit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 08:37:15 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/14 08:39:09 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		resolve_bit(t_memtet_bit *memtet)
{
	memtet->c = 2;
	while (memtet->c * memtet->c < 4 * memtet->l)
		memtet->c++;
	while (!resolve_aux(memtet, 0))
		memtet->c++;
}
