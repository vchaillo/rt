/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:06:09 by tlegroux          #+#    #+#             */
/*   Updated: 2017/01/05 14:22:37 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	register size_t	slen;

	if (!s1 || !s2)
		return (NULL);
	slen = ft_strlen(s2);
	if (!*s2)
		return ((char *)s1);
	while (*s1 && n)
	{
		if (slen > n)
			return (NULL);
		if (!ft_strncmp((char *)s1, (char *)s2, slen))
			return ((char *)s1);
		s1++;
		n--;
	}
	return (NULL);
}
