/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:01:53 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/13 19:52:57 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
		int c, size_t n)
{
	while (n--)
	{
		*((unsigned char *)dst++) = *((unsigned char *)src);
		if (*((unsigned char *)src++) == (unsigned char)c)
			return (dst);
	}
	return (NULL);
}
