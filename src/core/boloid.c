/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tore.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:04:11 by valentin          #+#    #+#             */
/*   Updated: 2017/03/14 01:33:02 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float			hit_boloid(t_boloid *boloid, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	double		t;

	a = (pow(ray->d.y, 2) / pow(boloid->b, 2))
	  + (boloid->sign * pow(ray->d.x, 2));
	b = (2 * ray->d.y * ray->o.y)
	  + (boloid->sign * 2 * ray->d.x * ray->o.x)
	  - ray->d.z;
	c = pow(ray->o.y, 2) / pow(boloid->b, 2)
	  + boloid->sign * pow(ray->o.x, 2)
	  - ray->o.z;
	t = solve_deg2(a, b, c);
	return (t);
}

t_vector		get_normal_at_boloid(t_ray *ray, t_boloid *boloid)
{
	t_vector	hit;
	t_vector	normal;

	hit = ray->hitpoint.pos;
	normal.x = 2 * hit.x * boloid->sign * (1 / pow(boloid->a, 2));
	normal.y = 2 * hit.y * (1 / pow(boloid->b, 2));
	normal.z = -1 * (hit.z / ABS(hit.z));
	return (normal);
}
