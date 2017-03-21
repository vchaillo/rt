/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <mmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 09:35:04 by mmorice           #+#    #+#             */
/*   Updated: 2017/03/21 09:39:49 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float				ft_atof(char *c)
{
	float			f;
	unsigned char	dec;

	f = 0;
	while (*c >= '0' && *c <= '9')
	{
		f = (f * 10) + (*c - '0');
		c++;
	}
	dec = 1;
	if (*c++ == '.')
	{
		while (*c >= '0' && *c <= '9')
		{
			f += (*c - '0') * pow(10, -(dec++));
			c++;
		}
	}
	return (f);
}
