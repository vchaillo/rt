/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fog.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 02:24:45 by valentin          #+#    #+#             */
/*   Updated: 2017/03/22 06:05:11 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color				fog(t_env *e, t_ray *ray, t_color color)
{
	float			t;
	float			p;

	p = 1.0 / FOG_DENSITY;
	t = 1 - exp(-pow_2(p * ray->t));
	color = add_color(
		scalar_color((1 - t), color),
		scalar_color(t, e->scene->background_color));
	return (color);
}
