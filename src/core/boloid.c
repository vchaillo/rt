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

	a = (boloid->a * pow(ray->d.x, 2)) +
		(boloid->b * pow(ray->d.y, 2)) +
		(boloid->c * pow(ray->d.z, 2));
	b = 2 * ((boloid->a * ray->d.x) +
			 (boloid->b * ray->d.y) +
			 (boloid->c * ray->d.z));
	c = boloid->a * pow(ray->o.x, 2) +
		boloid->b * pow(ray->o.y, 2) +
 		boloid->c * pow(ray->o.z, 2) - 1; 
	t = solve_deg2(a, b, c);
	return (t);
}

t_vector		get_normal_at_boloid(t_ray *ray, t_boloid *boloid)
{
	t_vector	hit;
	t_vector	normal;

	hit = ray->hitpoint.pos;
	normal.x = 2*boloid->a*hit.x;
	normal.y = 2*boloid->b*hit.y;
	normal.z = 2*boloid->c*hit.z;
	return (normal);
}
