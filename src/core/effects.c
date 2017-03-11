/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:53:32 by valentin          #+#    #+#             */
/*   Updated: 2017/03/11 04:00:56 by valentinchaillou89###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color			sepia(t_color color)
{
	t_color		output_color;

	output_color.r = (color.r * 0.493) + (color.g * 0.769) + (color.b * 0.189);
	output_color.g = (color.r * 0.449) + (color.g * 0.686) + (color.b * 0.168);
	output_color.b = (color.r * 0.272) + (color.g * 0.534) + (color.b * 0.131);
	return (limit_color(output_color));
}

t_color			grayscale(t_color color)
{
	int			gray;

	gray = (color.r + color.g + color.b) / 3;
	color.r = gray;
	color.g = gray;
	color.b = gray;
	return (color);
}

float			cartoon(t_env *e, float dot)
{
	if (e->scene->effect == CARTOON)
	{
		if (dot < 0.2)
			dot = 0;
		else if (dot < 0.4)
			dot = 0.2;
		else if (dot < 0.5)
			dot = 0.4;
		else
			dot = 1;
	}
	return (dot);
}

t_color			apply_effects(t_env *e, t_color color)
{
	if (e->scene->effect == SEPIA)
		color = sepia(color);
	if (e->scene->effect == GRAYSCALE)
		color = grayscale(color);
	if (e->scene->effect == NEGATIVE)
		color = negative_color(color);
	return (color);
}
