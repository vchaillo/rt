/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:04:54 by tlegroux          #+#    #+#             */
/*   Updated: 2017/01/05 14:29:58 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*d;
	char	*r;

	if (!s || !f)
		return (NULL);
	d = ft_strdup(s);
	r = d;
	while (*d)
	{
		*d = (*f)(*d);
		d++;
	}
	return (r);
}
