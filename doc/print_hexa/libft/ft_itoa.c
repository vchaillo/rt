/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 09:25:13 by tlegroux          #+#    #+#             */
/*   Updated: 2017/01/05 14:35:39 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	int				i;
	unsigned int	nb;
	char			*s;

	i = ((n > 0) ? 0 : 1);
	nb = ((n >= 0) ? n : -n);
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	if (!(s = malloc((i + 1) * sizeof(char))))
		return (NULL);
	s[i--] = '\0';
	nb = ((n >= 0) ? 0 : 1);
	while (i + 1)
	{
		s[i] = (ABS((long int)n) % 10) + '0';
		n /= 10;
		i--;
	}
	s[0] = ((nb) ? '-' : s[0]);
	return (s);
}
