/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:27:13 by tlegroux          #+#    #+#             */
/*   Updated: 2013/11/25 15:12:59 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*b;

	if (!s1 || !s2 || !n)
		return (NULL);
	if (!(b = malloc(n)))
		return (NULL);
	ft_memcpy(b, s2, n);
	ft_memcpy(s1, b, n);
	free(b);
	return (s1);
}
