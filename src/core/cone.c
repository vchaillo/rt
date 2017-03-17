/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:30:24 by valentin          #+#    #+#             */
/*   Updated: 2017/03/17 01:44:42 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		is_out_limit(const t_cone *cone, const t_ray *ray)
{
	t_vector	relative_pos;
	t_vector	rotated_pos;

	relative_pos = vector_sub(ray->o, cone->apex);
	rotated_pos = convert_to_rotated_coordinates(relative_pos, cone->axis);
	if ((cone->limit_max.x != 0) && (rotated_pos.x > cone->limit_max.x ||
								 rotated_pos.x < cone->limit_min.x))
		return (1);
	if ((cone->limit_max.y != 0) && (rotated_pos.y > cone->limit_max.y ||
								 rotated_pos.y < cone->limit_min.y))
		return (1);
	if ((cone->limit_max.z != 0) && (rotated_pos.z > cone->limit_max.z ||
								 rotated_pos.z < cone->limit_min.z))
		return (1);
	return (0);
}

float			hit_cone(t_cone *cone, t_ray *ray)
{
	float		abc[3];
	float		t;
	t_vector	dist;
	float		tmp[2];
	float		tangle;

	tangle = tan(cone->angle * M_PI / 180);
	dist = vector_sub(ray->o, cone->apex);
	tmp[0] = dot_product(ray->d, cone->axis);
	tmp[1] = dot_product(dist, cone->axis);
	abc[0] = dot_product(ray->d, ray->d)
		- ((1 + pow_2(tangle)) * pow_2(tmp[0]));
	abc[1] = 2 * (dot_product(ray->d, dist)
		- ((1 + pow_2(tangle)) * tmp[0] * tmp[1]));
	abc[2] = dot_product(dist, dist) - ((1 + pow_2(tangle)) * pow_2(tmp[1]));
	t = solve_deg2(abc[0], abc[1], abc[2]);
	if (!is_out_limit(cone, ray))
		return (t);
	else
		return (0);
}
