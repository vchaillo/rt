/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 09:46:19 by tlegroux          #+#    #+#             */
/*   Updated: 2017/01/05 14:32:42 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rputnbr(unsigned int n, int fd)
{
	if (n > 9)
		ft_rputnbr(n / 10, fd);
	ft_putchar_fd('0' + (n % 10), fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	n2;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n2 = -n;
	}
	else
		n2 = n;
	ft_rputnbr(n2, fd);
}
