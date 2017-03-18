/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:41:40 by tlegroux          #+#    #+#             */
/*   Updated: 2017/02/03 13:23:36 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	estimate_size(uintmax_t n, const char base, t_conversion *c)
{
	size_t size;

	size = 0;
	while (n)
	{
		n = n / base;
		size++;
	}
	if (size < (size_t)(c->precision))
		size = c->precision;
	if ((size < 1) && (c->specifier == 'o'))
		size = 1;
	if (base == 10 && (c->attributes & THOUSANDS_GROUP))
		size += size / 3;
	return (size);
}

char			*printf_uitoa(uintmax_t n, const char base, t_conversion *c)
{
	char		*sbase;
	char		*ret;
	size_t		size;
	short		s;

	sbase = "0123456789ABCDEF";
	size = estimate_size(n, base, c);
	if (!(ret = malloc((size + 1) * sizeof(char))))
		return (NULL);
	ft_memset(ret, '0', size);
	ret[size--] = '\0';
	s = 0;
	while (n)
	{
		if ((c->attributes & THOUSANDS_GROUP) && s == 3)
		{
			ret[size--] = '.';
			s = 0;
			break ;
		}
		ret[size--] = (c->specifier == 'o' || c->specifier == 'x') ?
			ft_tolower(sbase[n % base]) : sbase[n % base];
		n = n / base;
	}
	return (ret);
}
