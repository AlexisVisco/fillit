/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:13:20 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/09 15:07:28 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*to_do;

	if (!s)
		return (NULL);
	if (!(to_do = ft_strnew(len)))
		return (NULL);
	s += start;
	ft_strncpy(to_do, s, len);
	return (to_do);
}
