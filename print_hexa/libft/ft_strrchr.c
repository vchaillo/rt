/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 09:41:37 by tlegroux          #+#    #+#             */
/*   Updated: 2017/01/05 14:20:41 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	register char	*r;

	if (!s)
		return (NULL);
	r = NULL;
	while (*s)
	{
		r = ((*s == (char)c) ? (char*)s : r);
		s++;
	}
	r = ((!c) ? (char*)s : r);
	return (r);
}
