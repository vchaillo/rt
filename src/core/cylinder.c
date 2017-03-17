/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:04:11 by valentin          #+#    #+#             */
/*   Updated: 2017/03/17 01:35:20 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		is_out_limit(const t_cylinder *cylinder, const t_ray *ray)
{
	t_vector	relative_pos;
	t_vector	rotated_pos;

	relative_pos = vector_sub(ray->o, cylinder->pos);
	rotated_pos = convert_to_rotated_coordinates(relative_pos, cylinder->axis);
	if ((rotated_pos.x != 0) && (rotated_pos.x > cylinder->limit_max.x ||
								rotated_pos.x < cylinder->limit_min.x))
		return (1);
	if ((rotated_pos.y != 0) && (rotated_pos.y > cylinder->limit_max.y ||
								rotated_pos.y < cylinder->limit_min.y))
		return (1);
	if ((rotated_pos.z != 0) && (rotated_pos.z > cylinder->limit_max.z ||
								rotated_pos.z < cylinder->limit_min.z))
		return (1);
	return (0);
}

float			hit_cylinder(t_cylinder *cylinder, t_ray *ray)
{
	float		abc[3];
	float		t;
	t_vector	dist;
	float		tmp[2];

	dist = vector_sub(ray->o, cylinder->pos);
	tmp[0] = dot_product(ray->d, cylinder->axis);
	tmp[1] = dot_product(dist, cylinder->axis);
	abc[0] = dot_product(ray->d, ray->d) - pow_2(tmp[0]);
	abc[1] = 2 * (dot_product(ray->d, dist) - (tmp[0] * tmp[1]));
	abc[2] = dot_product(dist, dist) - pow_2(tmp[1]) - pow_2(cylinder->r);
	t = solve_deg2(abc[0], abc[1], abc[2]);
	if (!is_out_limit(cylinder, ray))
		return (t);
	else
		return (0);
}
