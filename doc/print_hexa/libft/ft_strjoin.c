/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:29:32 by tlegroux          #+#    #+#             */
/*   Updated: 2017/01/28 20:15:34 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	size_t	l1;
	size_t	l2;

	l1 = ((s1) ? ft_strlen(s1) : 0);
	l2 = ((s2) ? ft_strlen(s2) : 0);
	if (!(d = malloc(l1 + l2 + 1)))
		return (NULL);
	if (s1)
		ft_strcpy(d, s1);
	if (s2)
		ft_strcpy(d + l1, s2);
	return (d);
}
