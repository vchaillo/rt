/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:09:25 by tlegroux          #+#    #+#             */
/*   Updated: 2017/01/05 14:26:53 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*d;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	d = ft_strdup(s);
	i = 0;
	while (*d)
	{
		*d = (*f)(i, *d);
		i++;
		d++;
	}
	return (d - i);
}
