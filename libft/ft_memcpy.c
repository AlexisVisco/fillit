/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:52:38 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/08 15:54:22 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;
	char	*dst_bis;
	char	*src_bis;

	dst_bis = (char *)dst;
	src_bis = (char *)src;
	i = 0;
	while (i < n)
	{
		dst_bis[i] = src_bis[i];
		i++;
	}
	return (dst);
}
