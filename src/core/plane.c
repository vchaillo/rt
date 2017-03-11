/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 20:49:51 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/11 04:52:14 by valentinchaillou89###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float			hit_plane(t_plane *plane, t_ray *ray)
{
	float		t;
	t_vector	nor;
	t_vector	ro;
	t_vector	rd;

	nor = plane->normal;
	ro = ray->o;
	rd = ray->d;
	t = -(nor.x * ro.x + nor.y * ro.y + nor.z * ro.z + plane->offset);
	t /= (nor.x * rd.x + nor.y * rd.y + nor.z * rd.z);
	return (t);
}

int				is_plane_illuminated(t_ray *ray, t_light *light)
{
	float		t;
	t_ray		cam_light_ray;

	cam_light_ray.o = ray->o;
	if (light->type == SPOT)
	{
		cam_light_ray.d = vector_sub(light->pos, cam_light_ray.o);
		cam_light_ray.t = sqrt((cam_light_ray.d.x * cam_light_ray.d.x)
			+ (cam_light_ray.d.y * cam_light_ray.d.y)
			+ (cam_light_ray.d.z * cam_light_ray.d.z));
	}
	else
	{
		cam_light_ray.d = vector_scalar(-1, light->dir);
		cam_light_ray.t = MAX_DIST;
	}
	t = hit_plane(ray->hitpoint.object->object, &cam_light_ray);
	if (t > EPSILON && t < cam_light_ray.t)
		return (FALSE);
	return (TRUE);
}

t_color			checkerboard_plane(t_hitpoint hitpoint)
{
	t_color		color;

	color = hitpoint.object->color;
	if (hitpoint.pos.x < 0)
		hitpoint.pos.x--;
	if (hitpoint.pos.z < 0)
		hitpoint.pos.z--;
	if (((int)hitpoint.pos.x % 2 && (int)hitpoint.pos.z % 2)
		|| (!((int)hitpoint.pos.x % 2) && !((int)hitpoint.pos.z % 2)))
		color = negative_color(color);
	return (color);
}
