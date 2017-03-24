/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 10:53:02 by tlegroux          #+#    #+#             */
/*   Updated: 2017/01/05 14:39:29 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memset(void *b, char c, size_t len)
{
	if (!b)
		return (NULL);
	while (len)
		((char *)b)[--len] = c;
	return (b);
}
