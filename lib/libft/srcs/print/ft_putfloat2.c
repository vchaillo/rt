/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:34:08 by valentin          #+#    #+#             */
/*   Updated: 2017/02/23 04:34:59 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putfloat2(float f)
{
	float	dec_part;

	ft_putnbr(f);
	ft_putchar('.');
	dec_part = f - (int)f;
	ft_putnbr(dec_part * 100);
}
