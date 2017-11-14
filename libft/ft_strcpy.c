/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:12:02 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/08 16:21:20 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	len_src;

	len_src = ft_strlen(src);
	ft_memcpy(dest, src, len_src + 1);
	return (dest);
}
