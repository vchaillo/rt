/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 20:50:01 by vchaillo          #+#    #+#             */
/*   Updated: 2016/11/26 16:07:23 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		is_out_limit(const t_sphere *sphere, const t_ray *ray, const float t)
{
	t_vector	relative_pos;
	t_vector	rotated_pos;

	relative_pos.x = (ray->o.x + ray->d.x * t) - sphere->pos.x;
	relative_pos.y = (ray->o.y + ray->d.y * t) - sphere->pos.y;
	relative_pos.z = (ray->o.z + ray->d.z * t) - sphere->pos.z;
	rotated_pos = convert_to_rotated_coordinates(relative_pos, sphere->axis);
	if ((sphere->limit_max.x > 0 || sphere->limit_min.x < 0)
	    && (rotated_pos.x > sphere->limit_max.x ||
		rotated_pos.x < sphere->limit_min.x))
		return (1);
	if ((sphere->limit_max.y > 0 || sphere->limit_min.y < 0)
	    && (rotated_pos.y > sphere->limit_max.y ||
		rotated_pos.y < sphere->limit_min.y))
		return (1);
	if ((sphere->limit_max.z > 0 || sphere->limit_min.z < 0)
	    && (rotated_pos.z > sphere->limit_max.z ||
		rotated_pos.z < sphere->limit_min.z))
		return (1);
	return (0);
}

float			hit_sphere(t_sphere *sphere, t_ray *ray)
{
	float		t;
	double		a;
	double		b;
	double		c;

	a = dot_product(ray->d, ray->d);
	b = 2 * ray->d.x * (ray->o.x - sphere->pos.x);
	b += 2 * ray->d.y * (ray->o.y - sphere->pos.y);
	b += 2 * ray->d.z * (ray->o.z - sphere->pos.z);
	c = (ray->o.x - sphere->pos.x) * (ray->o.x - sphere->pos.x);
	c += (ray->o.y - sphere->pos.y) * (ray->o.y - sphere->pos.y);
	c += (ray->o.z - sphere->pos.z) * (ray->o.z - sphere->pos.z);
	c -= sphere->r * sphere->r;
	t = solve_deg2(a, b, c);
	if (!is_out_limit(sphere, ray, t))
	  return (t);
	else
	  return (0);
}
