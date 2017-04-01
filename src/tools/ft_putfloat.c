/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 20:00:41 by valentin          #+#    #+#             */
/*   Updated: 2017/04/01 20:59:38 by valentinchaillou89###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len_number(int n)
{
	int			len;

	len = 1;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void		print_diff_number(int diff)
{
	int			i;

	i = -1;
	while (++i < diff)
		ft_putchar('0');
}

void			ft_putfloat(float n, int max)
{
	int			integer_part;
	int			sign;
	int			i;
	int			dif;

	sign = (n < 0) ? -1 : 1;
	integer_part = (int)n;
	ft_putnbr(integer_part);
	if (max > 0)
	{
		ft_putchar('.');
		n -= (float)integer_part;
		n *= sign;
		i = -1;
		while (++i < max)
			n *= 10;
		integer_part = (int)n;
		ft_putnbr(integer_part);
		if ((dif = max - len_number(integer_part)) > 0)
			print_diff_number(dif);
	}
}
