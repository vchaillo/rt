/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:25:05 by tlegroux          #+#    #+#             */
/*   Updated: 2017/01/05 14:24:23 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*dest;
	size_t	len;

	if (!src || !n)
		return (NULL);
	len = ft_strlen(src);
	if (n < len)
		len = n;
	if (!(dest = malloc((len + 1) * sizeof(char))))
		return (NULL);
	dest[len] = '\0';
	ft_memcpy(dest, src, len);
	return (dest);
}
