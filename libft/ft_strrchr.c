/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:25:46 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/09 19:07:38 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			sup;
	unsigned char	cc;

	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	cc = (unsigned char)c;
	sup = ft_strlen(s);
	while (sup + 1 > 0)
	{
		if (s[sup] == cc)
			return ((char *)(s + sup));
		sup--;
	}
	return (NULL);
}
