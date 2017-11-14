/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:11:39 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/08 18:52:26 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*to_do;
	size_t	i;

	if (!(to_do = (char *)malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		to_do[i] = 0;
		i++;
	}
	return (to_do);
}
