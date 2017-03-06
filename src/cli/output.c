/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:15:39 by valentin          #+#    #+#             */
/*   Updated: 2017/01/10 14:14:05 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			print_camera_pos(t_env *e)
{
	ft_putchar('\n');
	ft_putendl_color("Camera position :", TERM_BOLD_GREY);
	ft_putstr_color("x : ", TERM_BOLD_BLACK);
	ft_putnbr_color(e->scene->camera->pos.x, TERM_BOLD_GREEN);
	ft_putstr_color(", y : ", TERM_BOLD_BLACK);
	ft_putnbr_color(e->scene->camera->pos.y, TERM_BOLD_GREEN);
	ft_putstr_color(", z : ", TERM_BOLD_BLACK);
	ft_putnbr_color(e->scene->camera->pos.z, TERM_BOLD_GREEN);
	ft_putchar('\n');
}

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
	ft_putchar('\n');
}

void			print_cli_output(t_env *e)
{
	if (e->verbose == FULL_VERBOSE || e->verbose == MIN_VERBOSE)
	{
		print_start_line();
		print_nb_rays(e);
		if (e->verbose == FULL_VERBOSE)
		{
			print_camera_pos(e);
			print_objects(e);
			print_lights(e);
		}
		print_end_line();
	}
}
