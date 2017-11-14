/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:26:38 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/14 16:02:57 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*ft_memcpy_aux(void *restrict dst, const void *restrict src,
		size_t n)
{
	char	*dst_bis;
	char	*src_bis;

	dst_bis = (char *)dst;
	src_bis = (char *)src;
	while (n > 0)
	{
		dst_bis[n - 1] = src_bis[n - 1];
		n--;
	}
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == src)
		return (dst);
	else if (dst < src)
		ft_memcpy(dst, src, len);
	else
		ft_memcpy_aux(dst, src, len);
	return (dst);
}
