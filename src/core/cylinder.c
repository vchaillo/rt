/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:04:11 by valentin          #+#    #+#             */
/*   Updated: 2017/01/30 23:02:58 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
	return (t);
}
