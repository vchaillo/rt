/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 22:41:26 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/30 17:37:47 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				is_in_shadow(t_object *objects, t_ray *ray, t_object *hit_obj)
{
	float		t;
	t_object	*object;

	object = objects;
	ray->transmittance_ray = 1;
	while (object != NULL)
	{
		if (hit_obj != object)
		{
			if (ray->transmittance_ray < EPSILON_SHADOW)
				return (TRUE);
			t = get_hit_distance(object, ray, ray->t);
			if (t > EPSILON && t < ray->t && !object->material.shadow)
				return (TRUE);
			else if (t > EPSILON && t < ray->t && object->material.shadow)
				ray->transmittance_ray *= object->material.shadow;
		}
		object = object->next;
	}
	return (FALSE);
}

t_color			specular(t_ray *v_ray, t_light *spot, t_ray *l_ray)
{
	t_color		color;
	t_ray		r_ray;
	float		cos_angle;
	float		spe;
	float		dot;

	cos_angle = 2 * dot_product(v_ray->hitpoint.normal, l_ray->d);
	r_ray.d = vector_sub(vector_scalar(cos_angle, v_ray->hitpoint.normal),
		l_ray->d);
	r_ray.d = normalize(r_ray.d);
	dot = dot_product(r_ray.d, v_ray->d);
	if (dot >= 0)
		return (new_color(BLACK));
	spe = pow(dot, v_ray->hitpoint.object->material.shininess);
	spe *= v_ray->hitpoint.object->material.specular;
	color = scalar_color(spe, spot->color);
	return (color);
}

t_color			diffuse(t_env *e, t_hitpoint hitpoint, t_light *l, t_ray *ray)
{
	t_color		color;
	float		dot;

	dot = dot_product(hitpoint.normal, ray->d);
	if (hitpoint.object->type == PLANE)
		dot = fabs(dot);
	dot = cartoon(e, dot);
	if (dot <= 0)
		return (new_color(BLACK));
	color = scalar_color(dot, add_color(hitpoint.color, l->color));
	if (hitpoint.object->material.type == PERLIN)
		color = scalar_color(perlin(hitpoint.pos.x, hitpoint.pos.y, 75), color);
	return (scalar_color(hitpoint.object->material.diffuse, color));
}

t_color			phong(t_env *e, t_light *light, t_ray *vray)
{
	t_color		color;
	t_ray		lray;

	color = new_color(BLACK);
	lray.o = vray->hitpoint.pos;
	if (light->type == LSPOT)
	{
		lray.d = normalize(vector_sub(light->pos, vray->hitpoint.pos));
		lray.t = sqrt((lray.d.x * lray.d.x) + (lray.d.y * lray.d.y) +
			(lray.d.z * lray.d.z));
	}
	else
	{
		lray.d = normalize(vector_scalar(-1, light->dir));
		lray.t = MAX_DIST;
	}
	if (!(is_in_shadow(e->scene->objects, &lray, vray->hitpoint.object)))
	{
		if (e->scene->diffuse == ACTIVE
			&& vray->hitpoint.object->material.diffuse)
			color = add_color(diffuse(e, vray->hitpoint, light, &lray), color);
		if (e->scene->specular == ACTIVE && e->scene->effect != CARTOON)
			color = add_color(specular(vray, light, &lray), color);
	}
	return (scalar_color(lray.transmittance_ray, color));
}

t_color			illuminate(t_env *e, t_ray *ray)
{
	t_color		color;
	t_light		*light;
	int			lux;

	color = new_color(BLACK);
	light = e->scene->lights;
	while (light != NULL)
	{
		lux = TRUE;
		if (ray->hitpoint.object->type == PLANE)
			lux = is_plane_illuminated(ray, light);
		if (light->type == LSPOT && e->scene->spot == ACTIVE && lux)
			color = add_color(scalar_color(light->intensity,
				phong(e, light, ray)), color);
		else if (light->type == LDIR && e->scene->dir == ACTIVE && lux)
			color = add_color(scalar_color(light->intensity,
				phong(e, light, ray)), color);
		light = light->next;
	}
	if (e->scene->amb == ACTIVE && (e->scene->spot || e->scene->dir))
		color = add_color(scalar_color((e->scene->amb_intensity),
			add_color(e->scene->amb_color, scalar_color(
		ray->hitpoint.object->material.diffuse, ray->hitpoint.color))), color);
	return (color);
}
