/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 17:09:57 by tlegroux          #+#    #+#             */
/*   Updated: 2017/01/14 18:52:36 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t n)
{
	void *new;

	new = malloc(n);
	if (ptr)
	{
		if (new)
		{
			ft_memcpy(new, ptr, n);
		}
		free(ptr);
	}
	return (new);
}
