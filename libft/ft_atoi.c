/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:08:02 by cepalle           #+#    #+#             */
/*   Updated: 2017/11/08 18:13:23 by cepalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		is_blank(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' ||
			c == '\v' || c == '\f' || c == '\r');
}

static	size_t	nb_space_strat(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && is_blank(str[i]))
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	int	tot;
	int	signe;

	signe = 1;
	tot = 0;
	str += nb_space_strat(str);
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		signe = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		tot *= 10;
		tot += *str - '0';
		str++;
	}
	return (tot * signe);
}
