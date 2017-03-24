/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 20:49:51 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/24 01:08:04 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		is_out_limit(const t_plane *plane, const t_ray *ray,
							const float t)
{
	t_vector	relative_pos;
	t_vector	rotated_pos;

	return (0);
	relative_pos.x = (ray->o.x + ray->d.x * t) - 0;
	relative_pos.y = (ray->o.y + ray->d.y * t) - 0;
	relative_pos.z = (ray->o.z + ray->d.z * t) - plane->offset;
	rotated_pos = convert_to_rotated_coordinates(relative_pos, plane->normal);
	if ((plane->limit_max.x > 0 || plane->limit_min.x < 0)
		&& (rotated_pos.x > plane->limit_max.x ||
			rotated_pos.x < plane->limit_min.x))
		return (1);
	if ((plane->limit_max.y > 0 || plane->limit_min.y < 0)
		&& (rotated_pos.y > plane->limit_max.y ||
			rotated_pos.y < plane->limit_min.y))
		return (1);
	if ((plane->limit_max.z > 0 || plane->limit_min.z < 0)
		&& (rotated_pos.z > plane->limit_max.z ||
			rotated_pos.z < plane->limit_min.z))
		return (1);
	return (0);
}

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
	if (!is_out_limit(plane, ray, t))
		return (t);
	else
		return (0);
}

int				is_plane_illuminated(t_ray *ray, t_light *light)
{
	float		t;
	float		sign_light;
	float		sign_eye;
	t_ray		cam_light_ray;
	t_plane		*plane;

	cam_light_ray.o = ray->o;
	if (light->type == SPOT)
	{
		plane = (t_plane *)ray->hitpoint.object->object;
		sign_light = dot_product(plane->normal, light->pos) + plane->offset;
		sign_eye = dot_product(plane->normal, ray->o) + plane->offset;
		if (sign_light * sign_eye > 0)
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
	t_plane		*plane;

	plane = (t_plane *)hitpoint.object->object;
	color = hitpoint.object->color;
	if (plane->type == CHECK || plane->type == CHECK_WAVE)
	{
		if (hitpoint.pos.x < 0)
			hitpoint.pos.x--;
		if (hitpoint.pos.z < 0)
			hitpoint.pos.z--;
		if (((int)hitpoint.pos.x % 2 && (int)hitpoint.pos.z % 2)
			|| (!((int)hitpoint.pos.x % 2) && !((int)hitpoint.pos.z % 2)))
			color = negative_color(color);
	}
	return (color);
}
