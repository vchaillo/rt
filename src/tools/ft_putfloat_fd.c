/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 20:00:41 by valentin          #+#    #+#             */
/*   Updated: 2017/04/01 21:42:14 by valentinchaillou89###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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

static void		print_diff_number(int diff, int fd)
{
	int			i;

	i = -1;
	while (++i < diff)
		ft_putchar_fd('0', fd);
}

void			ft_putfloat_fd(float n, int max, int fd)
{
	int			integer_part;
	int			sign;
	int			i;
	int			dif;

	sign = (n < 0) ? -1 : 1;
	integer_part = (int)n;
	ft_putnbr_fd(integer_part, fd);
	if (max > 0)
	{
		ft_putchar_fd('.', fd);
		n -= (float)integer_part;
		n *= sign;
		i = -1;
		while (++i < max)
			n *= 10;
		integer_part = (int)n;
		ft_putnbr_fd(integer_part, fd);
		if ((dif = max - len_number(integer_part)) > 0)
			print_diff_number(dif, fd);
	}
}
