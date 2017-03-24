/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/12 10:09:05 by tlegroux          #+#    #+#             */
/*   Updated: 2017/01/28 20:11:27 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *cstr)
{
	int				i;
	unsigned int	n;
	int				neg;
	char			*str;

	neg = 1;
	n = 0;
	i = 0;
	if (!(str = ft_strtrim(cstr)))
		return (0);
	while (str[i] && !(str[i] >= '0' && str[i] <= '9'))
	{
		neg *= ((str[i] == '-') ? -1 : 1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((n * 10) > 2147483647 || ((n * 10 > 2147483648) && (neg == -1)))
			return (0);
		n *= 10;
		n += (str[i] - '0');
		i++;
	}
	free(str);
	return (n * neg);
}
