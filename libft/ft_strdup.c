/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:52:29 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/09 10:07:48 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*to_do;

	len = ft_strlen(s1);
	if (!(to_do = ft_strnew(len)))
		return (NULL);
	ft_strcpy(to_do, s1);
	return (to_do);
}
