/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch_tet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.le101.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:26:20 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/20 10:09:20 by aviscogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	touch_tet(t_tetriminos *tet, short x, short y)
{
	short	k;

	k = 0;
	while (k < 4)
	{
		if (tet->crds[k].x == x && tet->crds[k].y == y)
			return (1);
		k++;
	}
	return (0);
}
