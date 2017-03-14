/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:21:38 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/14 01:27:51 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			get_hitpoint(t_object *object, t_ray *ray, float t_min)
{
	ray->hitpoint.object = object;
	ray->hitpoint.pos = vector_add(ray->o, vector_scalar(t_min, ray->d));
	ray->hitpoint.normal = get_normal(ray);
	if (ray->hitpoint.object->type == PLANE)
		ray->hitpoint.color = checkerboard_plane(ray->hitpoint);
	else
		ray->hitpoint.color = object->color;
}

float			get_hit_distance(t_object *object, t_ray *ray)
{
	float		t;

	if (object->type == SPHERE)
		t = hit_sphere(object->object, ray);
	else if (object->type == PLANE)
		t = hit_plane(object->object, ray);
	else if (object->type == CYLINDER)
		t = hit_cylinder(object->object, ray);
	else if (object->type == CONE)
		t = hit_cone(object->object, ray);
	else if (object->type == TORE)
		t = hit_tore(object->object, ray);
	else if (object->type == BOLOID)
		t = hit_boloid(object->object, ray);
	else
		t = EPSILON;
	return (t);
}

int				get_ray_intersection(t_object *objects, t_ray *ray)
{
	float		t;
	float		t_min;
	t_object	*object;
	t_object	*hit_object;

	t_min = MAX_DIST;
	hit_object = NULL;
	ray->hitpoint.object = NULL;
	object = objects;
	while (object != NULL)
	{
		t = get_hit_distance(object, ray);
		if (t > EPSILON && t < t_min)
		{
			t_min = t;
			hit_object = object;
		}
		object = object->next;
	}
	if (hit_object)
		get_hitpoint(hit_object, ray, t_min);
	return (t_min);
}

t_vector		get_camray_dir(t_camera *camera, int x, int y, int aa)
{
	t_vector	dir;
	float		dir_x;
	float		dir_y;
	float		dir_z;

	dir_x = (2.0 * ((x + 0.5) / WIN_W / aa) - 1.0) *
			camera->ratio * camera->fov;
	dir_y = (1.0 - 2.0 * ((y + 0.5) / WIN_H / aa)) * camera->fov;
	dir_z = camera->focale;
	dir = new_vector(dir_x, dir_y, dir_z);
	dir = vector_rot_x(dir, camera->rot.x);
	dir = vector_rot_y(dir, camera->rot.y);
	dir = vector_rot_z(dir, camera->rot.z);
	return (normalize(dir));
}

t_color			raytracer(t_env *e, int x, int y)
{
	t_ray		ray;
	t_color		color;

	ray.o = e->scene->camera->pos;
	ray.d = get_camray_dir(e->scene->camera, x, y, e->scene->aa);
	ray.t = get_ray_intersection(e->scene->objects, &ray);
	if (ray.hitpoint.object)
	{
		color = illuminate(e, &ray);
		reflected_ray(&ray);
		color = add_color(color, reflection(e, &ray));
	}
	else
		color = (e->scene->background_color);
	return (color);
}
