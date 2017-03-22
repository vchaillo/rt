/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fog.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 02:24:45 by valentin          #+#    #+#             */
/*   Updated: 2017/03/22 03:47:22 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color				interpolate(t_color color1, t_color color2, int coeff)
{
	t_color			color;

	color.r = coeff * (color2.r - color1.r) + color1.r;
	color.g = coeff * (color2.g - color1.g) + color1.g;
	color.b = coeff * (color2.b - color1.b) + color1.b;
	return (color);
}

t_color				fog(t_env *e, t_ray *ray, t_color color)
{
	float			coeff;
	float			dist;

	dist = 0;
	if (ray->t != MAX_DIST)
		dist = ray->t;
	coeff = exp(-dist * 1);
	coeff = 1;
	color = interpolate(e->scene->background_color, color, coeff);
	return (color);
}
