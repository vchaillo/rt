/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boloid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:04:11 by valentin          #+#    #+#             */
/*   Updated: 2017/03/24 05:24:58 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		is_out_limit(const t_boloid *boloid, const t_ray *ray,
							const float t)
{
	t_vector	relative_pos;

	relative_pos.x = (ray->o.x + ray->d.x * t) - boloid->pos.x;
	relative_pos.y = (ray->o.y + ray->d.y * t) - boloid->pos.y;
	relative_pos.z = (ray->o.z + ray->d.z * t) - boloid->pos.z;
	if ((boloid->limit_max.x > 0 || boloid->limit_min.x < 0)
		&& (relative_pos.x > boloid->limit_max.x ||
			relative_pos.x < boloid->limit_min.x))
		return (1);
	if ((boloid->limit_max.y > 0 || boloid->limit_min.y < 0)
		&& (relative_pos.y > boloid->limit_max.y ||
			relative_pos.y < boloid->limit_min.y))
		return (1);
	if ((boloid->limit_max.z > 0 || boloid->limit_min.z < 0)
		&& (relative_pos.z > boloid->limit_max.z ||
			relative_pos.z < boloid->limit_min.z))
		return (1);
	return (0);
}

float			hit_boloid(t_boloid *boloid, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	double		t;

	a = (pow(ray->d.z, 2) / pow(boloid->b, 2))
		+ (boloid->sign * pow(ray->d.x, 2));
	b = (2 * ray->d.z * (ray->o.z - boloid->pos.z))
		+ (boloid->sign * 2 * ray->d.x * (ray->o.x - boloid->pos.x))
		- ray->d.y;
	c = pow((ray->o.z - boloid->pos.z), 2) / pow(boloid->b, 2)
		+ boloid->sign * pow((ray->o.x - boloid->pos.x), 2)
		- (ray->o.y - boloid->pos.y);
	t = solve_deg2(a, b, c);
	if (!is_out_limit(boloid, ray, t))
		return (t);
	else
		return (0);
}

t_vector		get_normal_at_boloid(t_ray *ray, t_boloid *boloid)
{
	t_vector	hit;
	t_vector	normal;

	hit = ray->hitpoint.pos;
	normal.x = 2 * (hit.x - boloid->pos.x) * boloid->sign
		* (1 / pow(boloid->a, 2));
	normal.z = 2 * (hit.z - boloid->pos.z) * (1 / pow(boloid->b, 2));
	normal.y = -1 * ((hit.y - boloid->pos.y) / fabs((hit.y - boloid->pos.y)));
	return (normal);
}
