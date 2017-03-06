/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:34:52 by valentin          #+#    #+#             */
/*   Updated: 2017/01/10 14:13:25 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			print_amb_light(t_env *e)
{
	ft_putendl(" Ambient light ->");
	ft_putstr("      intensity : ");
	ft_putfloat2(e->scene->amb_intensity);
	ft_putstr("\n      color : ");
	print_color(e->scene->amb_color);
	ft_putendl(TERM_END);
}

void			print_dir_light(t_light *light)
{
	ft_putendl(" Directional light ->");
	ft_putstr("      intensity : ");
	ft_putfloat2(light->intensity);
	ft_putstr("\n      color : ");
	print_color(light->color);
	ft_putstr("\n      direction : ");
	print_vector(light->dir);
}

void			print_spot_light(t_light *light)
{
	ft_putendl(" Spot light -> ");
	ft_putstr("      intensity : ");
	ft_putfloat2(light->intensity);
	ft_putstr("\n      color : ");
	print_color(light->color);
	ft_putstr("\n      position : ");
	print_vector(light->pos);
}

void			print_lights(t_env *e)
{
	t_light		*tmp;

	ft_putchar('\n');
	ft_putendl_color("Lights informations :", TERM_BOLD_GREY);
	ft_putstr(TERM_BOLD_BLACK);
	if (e->scene->amb == ACTIVE)
		print_amb_light(e);
	ft_putnbr_color(e->scene->nb_lights, TERM_BOLD_GREEN);
	ft_putendl_color(" lights in scene", TERM_BOLD_GREEN);
	tmp = e->scene->lights;
	while (tmp != NULL)
	{
		ft_putstr(TERM_BOLD_BLACK);
		if (tmp->type == DIR && e->scene->dir == ACTIVE)
			print_dir_light(tmp);
		else if (tmp->type == SPOT && e->scene->spot == ACTIVE)
			print_spot_light(tmp);
		ft_putendl(TERM_END);
		tmp = tmp->next;
	}
}
