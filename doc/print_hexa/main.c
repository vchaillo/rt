/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 20:20:15 by tlegroux          #+#    #+#             */
/*   Updated: 2017/02/13 15:11:27 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int ac, char **av)
{
	ft_putstr("\n---\n");
	/*
	** Demo:
	*/
	t_conversion conv;
	conv.attributes = 0;
	conv.field_width = 0;
	conv.precision = 0;
	conv.lengthmod = 0;
	conv.specifier = 'x';
	char *foo = printf_uitoa(0x123ABC16, 16, &conv);
	ft_putstr(foo);
	ft_putchar('\n');
	return (0);
}
