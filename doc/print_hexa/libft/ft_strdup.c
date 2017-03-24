/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/18 20:48:27 by tlegroux          #+#    #+#             */
/*   Updated: 2017/01/05 14:30:35 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *src)
{
	unsigned int	i;
	char			*dest;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	if (!(dest = malloc((i + 1) * sizeof(char))))
		return (NULL);
	while (i > 0)
	{
		dest[i] = ((char *)src)[i];
		i--;
	}
	dest[i] = ((char *)src)[i];
	return (dest);
}
