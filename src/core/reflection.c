/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 02:57:58 by hbock             #+#    #+#             */
/*   Updated: 2017/03/24 02:57:58 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			reflected_ray(t_ray *ray)
{
	float		c1;

	c1 = -dot_product(ray->hitpoint.normal, ray->d);
	ray->d = vector_add(ray->d, vector_scalar(2 * c1, ray->hitpoint.normal));
	ray->o = ray->hitpoint.pos;
	ray->d = normalize(ray->d);
}

t_color			reflection(t_env *e, t_ray *ray, t_ref r, float coef)
{
	reflected_ray(&(r.reflect_ray));
	r.color = add_color(r.color, depth_compute(e, &(r.reflect_ray), r.depth + 1,
		r.reflect_ray.hitpoint.object->material.reflexion * coef));
	return (add_color(scalar_color(ray->hitpoint.object->material.reflexion,
		r.color), scalar_color(1 - ray->hitpoint.object->material.reflexion,
			illuminate(e, ray))));
}
