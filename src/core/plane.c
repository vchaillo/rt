/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 20:49:51 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/10 23:10:54 by vchaillo         ###   ########.fr       */
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
	float		sign_light;
	float		sign_eye;
	t_plane		*plane;

	cam_light_ray.o = ray->o;
	if (light->type == SPOT)
	{
		plane = (t_plane *)ray->hitpoint.object->object;
		sign_light = dot_product(plane->normal, light->pos) + plane->offset;
		sign_eye = dot_product(plane->normal, ray->o) + plane->offset;
		if (sign_light * sign_eye >= 0)
			return (TRUE);
		return (FALSE);
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
	int			tmp_x;
	int			tmp_y;

	(void)tmp_y;
	tmp_x = (int)hitpoint.pos.x;
	color = hitpoint.object->color;
	if (tmp_x < 0)
	{
		if ((tmp_x + 1) % 2)
			color = new_color(BLUE);
	}
	else
	{
		if (tmp_x % 2)
			color = new_color(BLUE);
	}
	return (color);
}
