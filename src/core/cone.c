/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:30:24 by valentin          #+#    #+#             */
/*   Updated: 2017/01/30 23:03:51 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
	return (t);
}
