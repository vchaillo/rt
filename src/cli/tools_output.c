/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 20:07:24 by valentin          #+#    #+#             */
/*   Updated: 2017/01/10 14:14:17 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			print_color(t_color color)
{
	ft_putchar('(');
	ft_putnbr(color.r);
	ft_putstr(", ");
	ft_putnbr(color.g);
	ft_putstr(", ");
	ft_putnbr(color.b);
	ft_putchar(')');
}

void			print_vector(t_vector vector)
{
	ft_putchar('(');
	ft_putnbr(vector.x);
	ft_putstr(", ");
	ft_putnbr(vector.y);
	ft_putstr(", ");
	ft_putnbr(vector.z);
	ft_putchar(')');
}

void			print_start_line(void)
{
	ft_putstr(TERM_BOLD_BLUE);
	ft_putstr("======");
	ft_putstr(TERM_BOLD_YELLOW);
	ft_putstr(" DRAW NEW IMAGE ");
	ft_putstr(TERM_BOLD_BLUE);
	ft_putendl("=======\n");
}

void			print_end_line(void)
{
	ft_putstr(TERM_BOLD_BLUE);
	ft_putendl("\n======================\n");
	ft_putstr(TERM_END);
}
