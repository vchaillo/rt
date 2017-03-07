/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:53:32 by valentin          #+#    #+#             */
/*   Updated: 2017/03/07 16:36:22 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color			sepia(t_color color)
{
	t_color		output_color;

	output_color.r = (color.r * 0.393) + (color.g * 0.769) + (color.b * 0.189);
	output_color.g = (color.r * 0.349) + (color.g * 0.686) + (color.b * 0.168);
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

t_color			apply_effects(t_env *e, t_color color)
{
	if (e->scene->sepia == ACTIVE)
		color = sepia(color);
	if (e->scene->grayscale == ACTIVE)
		color = grayscale(color);
	return (color);
}
