/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:53:32 by valentin          #+#    #+#             */
/*   Updated: 2017/03/14 11:17:39 by vchaillo         ###   ########.fr       */
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

t_color			stereoscopy(t_color color)
{
	t_color		red_color;
	t_color		cyan_color;
	t_color		final_color;

	// red_color.r = (color.r * 10.0) + (color.g * 0.969) + (color.b * 0.489);
	// red_color.g = (color.r * 0.449) + (color.g * 0.686) + (color.b * 0.168);
	// red_color.b = (color.r * 0.272) + (color.g * 0.534) + (color.b * 0.131);
	// cyan_color.r = (color.r * 0.493) + (color.g * 0.769) + (color.b * 0.189);
	// cyan_color.g = (color.r * 0.449) + (color.g * 0.686) + (color.b * 0.168);
	// cyan_color.b = (color.r * 0.272) + (color.g * 5.534) + (color.b * 5.131);
	red_color = grayscale(color);
	red_color = add_color(color, new_color(RED));
	cyan_color = grayscale(color);
	cyan_color = add_color(color, new_color(CYAN));
	final_color = mult_color(cyan_color, red_color);
	return ((final_color));
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
	else if (e->scene->effect == GRAYSCALE)
		color = grayscale(color);
	else if (e->scene->effect == NEGATIVE)
		color = negative_color(color);
	else if (e->scene->effect == STEREO)
		color = stereoscopy(color);
	return (color);
}
