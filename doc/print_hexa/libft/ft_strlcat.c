/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 09:22:49 by tlegroux          #+#    #+#             */
/*   Updated: 2013/11/26 16:25:43 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ld;
	size_t	i;

	if (!dst || !src)
		return (0);
	ld = 0;
	while (*dst && ld < size)
	{
		dst++;
		ld++;
	}
	if (ld == size)
		return (ld + ft_strlen(src));
	i = 0;
	while (*src && i < (size - ld - 1))
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (ld + ft_strlen(src - i));
}
