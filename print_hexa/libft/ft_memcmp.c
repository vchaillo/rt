/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:20:06 by tlegroux          #+#    #+#             */
/*   Updated: 2017/01/05 14:39:04 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *s;
	const unsigned char *d;

	if (!s1 || !s2 || !n)
		return (0);
	s = (unsigned char *)s2;
	d = (unsigned char *)s1;
	if (!n)
		return (0);
	while (n--)
	{
		if (*s != *d)
			return (*d - *s);
		s++;
		d++;
	}
	return (0);
}
