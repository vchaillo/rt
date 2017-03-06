/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 15:47:58 by vchaillo          #+#    #+#             */
/*   Updated: 2014/11/22 07:55:14 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	get_n_len(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		len++;
		n = n / 10;
	}
	len++;
	return (len);
}

char			*ft_itoa(int n)
{
	size_t		n_len;
	char		*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_len = get_n_len(n);
	if (!(str = (char *)malloc(sizeof(*str) * (n_len + 1))))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[n_len] = '\0';
	while (n / 10 != 0)
	{
		str[n_len - 1] = n % 10 + '0';
		n = n / 10;
		n_len--;
	}
	str[n_len - 1] = n + '0';
	return (str);
}
