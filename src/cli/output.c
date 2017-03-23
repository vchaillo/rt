/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:15:39 by valentin          #+#    #+#             */
/*   Updated: 2017/03/22 21:57:08 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			print_nb_rays(t_env *e)
{
	ft_putendl_color("Rays informations :", TERM_BOLD_GREY);
	ft_putstr_color("Camera rays : ", TERM_BOLD_BLACK);
	ft_putnbr_color(e->nb_cam_rays, TERM_BOLD_GREEN);
	ft_putchar('\n');
	ft_putstr_color("Light rays : ", TERM_BOLD_BLACK);
	ft_putnbr_color(e->nb_light_rays, TERM_BOLD_GREEN);
	ft_putchar('\n');
	ft_putstr_color("Total rays : ", TERM_BOLD_BLACK);
	ft_putnbr_color(e->nb_rays, TERM_BOLD_GREEN);
	ft_putendl("\n");
}

void			print_frame_time(t_env *e)
{
	ft_putstr_color("\n", TERM_BOLD_GREY);
	ft_putstr_color("Frame time : ", TERM_BOLD_GREY);
	ft_putfloat2(e->frame_time);
	ft_putendl_color(" s\n", TERM_BOLD_GREY);
}

void			print_cli_output(t_env *e)
{
	if (e->verbose == VERBOSE)
	{
		ft_putendl_color("\n***********************", TERM_BOLD_GREEN);
		print_frame_time(e);
		print_nb_rays(e);
	}
}
