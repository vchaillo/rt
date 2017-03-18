/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 09:48:14 by tlegroux          #+#    #+#             */
/*   Updated: 2017/01/05 14:33:17 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rputnbr(unsigned int n)
{
	if (n > 9)
		ft_rputnbr(n / 10);
	ft_putchar('0' + (n % 10));
}

void		ft_putnbr(int n)
{
	unsigned int	n2;

	if (n < 0)
	{
		ft_putchar('-');
		n2 = -n;
	}
	else
		n2 = n;
	ft_rputnbr(n2);
}
