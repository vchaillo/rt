/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:48:26 by tlegroux          #+#    #+#             */
/*   Updated: 2013/11/27 09:50:01 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*s;

	if (!size)
		return (NULL);
	if (!(s = malloc((size) * sizeof(char))))
		return (NULL);
	while (size--)
		s[size] = '\0';
	return (s);
}
