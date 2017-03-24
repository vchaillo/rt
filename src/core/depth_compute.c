/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_refraction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <hbock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:58:39 by hbock             #+#    #+#             */
/*   Updated: 2017/03/09 23:13:38 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color			depth_compute(t_env *e, t_ray *ray, int depth, float coef)
{
	t_ref		r;

	r.color = new_color(BLACK);
	r.reflect_color = new_color(BLACK);
	r.refract_color = new_color(BLACK);
	ray->t = get_ray_intersection(e->scene->objects, ray);
	if (!(ray->hitpoint.object))
		return (e->scene->background_color);
	if (depth == MAX_DEPTH || coef < 0.02)
		return (r.color);
	r.reflect_ray = *ray;
	r.refract_ray = *ray;
	r.depth = depth;
	if (ray->hitpoint.object->material.property == DIFFUSE ||
		(ray->hitpoint.object->material.property == REFLECTIVE && depth == 0) ||
		(ray->hitpoint.object->material.property == TRANSMITIVE && depth == 0))
		r.color = illuminate(e, ray);
	if (r.reflect_ray.hitpoint.object->material.property == REFLECTIVE)
		r.color = reflection(e, ray, r, coef);
	else if (r.refract_ray.hitpoint.object->material.property == TRANSMITIVE)
		r.color = refraction(e, ray, r, coef);
	if (GI && depth == 0)
		r.color = add_color(r.color, global_illumination(e, ray));
	return (r.color);
}
