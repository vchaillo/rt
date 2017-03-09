/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 03:18:42 by valentin          #+#    #+#             */
/*   Updated: 2017/03/09 18:47:53 by valentinchaillou89###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector		get_normal(t_ray *ray)
{
	t_vector	normal;

	if (ray->hitpoint.object->type == SPHERE)
		normal = normalize(vector_sub(ray->hitpoint.pos,
			((t_sphere *)ray->hitpoint.object->object)->pos));
	else if (ray->hitpoint.object->type == PLANE)
		normal = get_normal_at_plane(ray, ray->hitpoint.object->object);
	else if (ray->hitpoint.object->type == CYLINDER)
		normal = get_normal_at_cylinder(ray, ray->hitpoint.object->object);
	else
		normal = get_normal_at_cone(ray, ray->hitpoint.object->object);
	return (normalize(normal));
}

t_vector		get_normal_at_plane(t_ray *ray, t_plane *plane)
{
	t_vector	normal;
	float		wave_height;
	float		wave_width;

	wave_height = 10;
	wave_width = 1.2;
	if (((t_plane *)ray->hitpoint.object->object)->wave == TRUE)
		normal = vector_rot_z(plane->normal,
			sin(ray->hitpoint.pos.x*wave_width)*wave_height);
	else
		normal = ((t_plane *)ray->hitpoint.object->object)->normal;
	return (normal);
}


t_vector		get_normal_at_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	t_vector	normal;
	t_vector	tmp;
	t_vector	project;
	float		dot;

	tmp = vector_sub(ray->hitpoint.pos, cylinder->pos);
	dot = dot_product(tmp, cylinder->axis);
	project = vector_scalar(dot, cylinder->axis);
	normal = vector_sub(tmp, project);
	return (normal);
}

t_vector		get_normal_at_cone(t_ray *ray, t_cone *cone)
{
	t_vector	normal;
	t_vector	tmp;
	t_vector	project;
	float		dot;

	tmp = vector_sub(ray->hitpoint.pos, cone->apex);
	dot = dot_product(tmp, cone->axis);
	project = vector_scalar(dot, cone->axis);
	normal = vector_sub(tmp, project);
	return (normal);
}
