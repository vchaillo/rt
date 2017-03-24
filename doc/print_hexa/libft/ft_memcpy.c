/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:27:13 by tlegroux          #+#    #+#             */
/*   Updated: 2017/01/05 14:37:13 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		*ft_memcpy(void *s1, const void *s2, size_t n)
{
	void	*b;

	if (!s1 || !s2)
		return (NULL);
	b = s1;
	while (n)
	{
		--n;
		((char *)s1)[n] = ((char *)s2)[n];
	}
	return (b);
}
