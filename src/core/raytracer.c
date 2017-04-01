/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:21:38 by vchaillo          #+#    #+#             */
/*   Updated: 2017/04/01 19:45:44 by valentin         ###   ########.fr       */
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

float			get_hit_distance(t_object *object, t_ray *ray, float tn)
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
	else if (object->type == BOX)
		t = hit_box(object->object, ray, tn);
	else if (object->type == DISC)
		t = hit_disc(object->object, ray);
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

	t = 0;
	t_min = MAX_DIST;
	hit_object = NULL;
	ray->hitpoint.object = NULL;
	object = objects;
	while (object != NULL)
	{
		t = get_hit_distance(object, ray, t);
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
	float		x_indent;
	float		y_indent;

	x_indent = RATIO * FOV / WIN_W / aa;
	y_indent = FOV / WIN_H / aa;
	dir = vector_add(
		camera->viewplane_pos,
		vector_sub(
			vector_scalar(x_indent * x, camera->dir_right),
			vector_scalar(y_indent * y, camera->dir_up)));
	dir = vector_sub(dir, camera->pos);
	return (normalize(dir));
}

t_color			raytracer(t_env *e, int x, int y)
{
	t_ray		ray;
	t_color		color;

	get_viewplane_pos(e->scene->camera);
	ray.o = e->scene->camera->pos;
	ray.d = get_camray_dir(e->scene->camera, x, y, e->scene->aa);
	ray.ior = AIR_IOR;
	ray.is_in = 0;
	color = depth_compute(e, &ray, 0, 1);
	color = fog(e, &ray, color);
	return (color);
}
