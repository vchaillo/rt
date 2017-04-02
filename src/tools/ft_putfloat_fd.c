/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 13:49:27 by hbock             #+#    #+#             */
/*   Updated: 2017/04/02 13:49:28 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int			len_number(int n)
{
	int		len;

	len = 1;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void			print_diff_number(int diff, int fd)
{
	int		i;

	i = -1;
	while (++i < diff)
		ft_putchar_fd('0', fd);
}

static void			dec_deci(float *n, int *added, int max, int fd)
{
	int		i;

	i = -1;
	while (++i < max)
	{
		*n *= 10;
		if (*n < 1)
		{
			(*added)++;
			ft_putchar_fd('0', fd);
		}
	}
}

void				ft_putfloat_fd(float n, int max, int fd)
{
	int		integer_part;
	int		sign;
	int		dif;
	int		added;

	sign = (n < 0) ? -1 : 1;
	integer_part = (int)n;
	if (n >= -1 && n < 0)
		ft_putchar_fd('-', fd);
	ft_putnbr_fd(integer_part, fd);
	if (max > 0)
	{
		ft_putchar_fd('.', fd);
		n -= (float)integer_part;
		n *= sign;
		added = 0;
		dec_deci(&n, &added, max, fd);
		integer_part = (int)n;
		ft_putnbr_fd(integer_part, fd);
		if ((dif = max - len_number(integer_part)) > 0)
			print_diff_number(dif - added, fd);
	}
}
