/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:35:44 by valentin          #+#    #+#             */
/*   Updated: 2017/01/10 14:13:22 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			print_exposehook(t_env *e)
{
	if (e->verbose == FULL_VERBOSE || e->verbose == MIN_VERBOSE)
	{
		ft_putendl_color("Expose event detected !", TERM_BOLD_RED);
		ft_putchar('\n');
	}
}

void			print_keyhook(int keycode, t_env *e)
{
	if (e->verbose == FULL_VERBOSE || e->verbose == MIN_VERBOSE)
	{
		ft_putendl_color("Key event detected !", TERM_BOLD_RED);
		ft_putstr_color("Keycode : ", TERM_BOLD_BLACK);
		ft_putnbr_color(keycode, TERM_BOLD_GREEN);
		ft_putendl("\n");
	}
}

void			print_mousehook(int button, int x, int y, t_env *e)
{
	if (e->verbose == FULL_VERBOSE || e->verbose == MIN_VERBOSE)
	{
		ft_putendl_color("Mouse event detected !", TERM_BOLD_RED);
		ft_putstr_color("Mouse button : ", TERM_BOLD_BLACK);
		ft_putnbr_color(button, TERM_BOLD_GREEN);
		ft_putstr_color(", x : ", TERM_BOLD_BLACK);
		ft_putnbr_color(x, TERM_BOLD_GREEN);
		ft_putstr_color(", y : ", TERM_BOLD_BLACK);
		ft_putnbr_color(y, TERM_BOLD_GREEN);
		ft_putendl("\n");
	}
}
