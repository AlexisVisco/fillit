/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_memtet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.le101.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:18:47 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/20 09:40:29 by aviscogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	init_memtet(t_memtet *memtet)
{
	short	i;

	i = 0;
	memtet->size_square = 2;
	memtet->nb_tet = 0;
	while (i < 26)
	{
		memtet->ltet[i].crds[0].x = 0;
		memtet->ltet[i].crds[0].y = 0;
		memtet->ltet[i].crds[1].x = 0;
		memtet->ltet[i].crds[1].y = 0;
		memtet->ltet[i].crds[2].x = 0;
		memtet->ltet[i].crds[2].y = 0;
		memtet->ltet[i].crds[3].x = 0;
		memtet->ltet[i].crds[3].y = 0;
		memtet->ltet[i].x = 0;
		memtet->ltet[i].y = 0;
		memtet->ltet[i].width = 0;
		memtet->ltet[i].height = 0;
		memtet->ltet[i].i_last = 0;
		i++;
	}
}
