/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_refraction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <hbock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:58:39 by hbock             #+#    #+#             */
/*   Updated: 2017/03/09 23:13:38 by valentinchaillou89###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			reflected_ray(t_ray *ray)
{
	float		c1;

	c1 = -dot_product(ray->hitpoint.normal, ray->d);
	ray->d = vector_add(ray->d, vector_scalar(2 * c1, ray->hitpoint.normal));
	ray->o = ray->hitpoint.pos;
}

int				refracted_ray(t_ray *ray)
{
	float		n;
	float		c1;
	float		c2;

	ray->o = ray->hitpoint.pos;
	// n = ray->ior / ray->past_ior;
	n = ray->past_ior / ray->ior;
	c1 = -dot_product(ray->hitpoint.normal, ray->d);
	c2 = n * n * (1 - c1 * c1);
	if (c2 > 1)
		return (1);
	c2 = sqrtf(1 - c2);
	ray->d = vector_add(vector_scalar(n, ray->d), vector_scalar(n * c1 - c2, ray->hitpoint.normal));
	return (0);
}

float			schlick(t_ray *ray)
{
	float		r0;
	float		c1;
	float		c2;
	float		c3;
	float		n;

	r0 = (ray->past_ior - ray->ior) / (ray->ior + ray->past_ior);
	// r0 = (ray->ior - ray->past_ior) / (ray->ior + ray->past_ior);
	r0 *= r0;
	c1 = -dot_product(ray->hitpoint.normal, ray->d);
	// if (ray->ior > ray->past_ior)
	// {
	// 	n = ray->ior / ray->past_ior;
	if (ray->past_ior > ray->ior)
	{
		n =  ray->past_ior / ray->ior;
		c3 = n * n * (1 - c1 * c1);
		if (c3 > 1)
			return (1);
		c1 = sqrtf(1 - c3);
	}
	c2 = 1 - c1;
	return (r0 + (1 - r0) * c2 * c2 * c2 * c2 * c2);
}

t_color			calculate_combined_color(t_color color, t_color reflect_color, t_color refract_color, t_ray *ray, float cumul_coef)
{
	float		r;
	t_color		composed_color;

	if (ray->hitpoint.object->material.reflexion != 1)
		r = schlick(ray);
	else
		r = 1;
	composed_color = add_color(scalar_color(r, reflect_color), scalar_color(1 - r, refract_color));
	color = add_color(color, scalar_color(cumul_coef, composed_color));
	return (color);
}

void			compute_ior(t_ray *ray)
{
	if (ray->is_in)
	{
		ray->ior = AIR_IOR;
		ray->past_ior = ray->hitpoint.object->material.ior;
		ray->is_in = 0;
	}
	else
	{
		ray->ior = ray->hitpoint.object->material.ior;
		ray->past_ior = AIR_IOR;
		ray->is_in = 1;
	}
}

t_color			reflection_refraction(t_env *e, t_ray *ray, int depth, float cumul_coef)
{
	t_color		color;
	t_color		reflect_color;
	t_color		refract_color;
	t_ray		reflect_ray;
	t_ray		refract_ray;

	reflect_color = new_color(BLACK);
	refract_color = new_color(BLACK);
	ray->t = get_ray_intersection(e->scene->objects, ray);
	if (!(ray->hitpoint.object))
		return (e->scene->background_color);
	compute_ior(ray);
	color = illuminate(e, ray);
	if (depth == MAX_DEPTH || cumul_coef < 0.02)
		return (color);
	reflect_ray = *ray;
	refract_ray = *ray;
	if (reflect_ray.hitpoint.object->material.reflexion)
	{
		reflected_ray(&reflect_ray);
		// printf("%d:%lf|%lf|%lf\n", depth,reflect_ray.d.x,reflect_ray.d.y,reflect_ray.d.z);
		reflect_color = reflection_refraction(e, &reflect_ray, depth + 1, cumul_coef * reflect_ray.hitpoint.object->material.reflexion);
	}
	if (refract_ray.hitpoint.object->material.refraction && refract_ray.hitpoint.object->material.reflexion != 1)
	{
		if (!refracted_ray(&refract_ray))
			refract_color = reflection_refraction(e, &refract_ray, depth + 1, cumul_coef * refract_ray.hitpoint.object->material.refraction);
	}
	// if (ray->hitpoint.object->material.reflexion == 0)
	// 	return (add_color(color, refract_color));
	// else if (ray->hitpoint.object->material.refraction == 0)
	// 	return (add_color(color, reflect_color));
	return (calculate_combined_color(color, reflect_color, refract_color, ray, cumul_coef));
}

// t_ray			reflected_ray(t_ray ray)
// {
// 	float		c1;
// 	t_ray		new_ray;
//
// 	new_ray = ray;
// 	new_ray.o = new_ray.hitpoint.pos;
// 	c1 = -dot_product(new_ray.hitpoint.normal, new_ray.d);
// 	new_ray.d = vector_add(new_ray.d, vector_scalar(2 * c1, new_ray.hitpoint.normal));
// 	return (new_ray);
// }
//
// t_ray			refracted_ray(t_ray ray)
// {
// 	float		n;
// 	float		c1;
// 	float		c2;
// 	t_ray		new_ray;
//
// 	new_ray = ray;
// 	new_ray.o = new_ray.hitpoint.pos;
// 	n = new_ray.medium_index / new_ray.hitpoint.object->material.medium_index;
// 	c1 = -dot_product(new_ray.hitpoint.normal, new_ray.d);
// 	c2 = sqrtf(1 - n * n * (1 - c1 * c1));
// 	new_ray.d = vector_add(vector_scalar(n, new_ray.d), vector_scalar(n * c1 - c2, new_ray.hitpoint.normal));
// 	return (new_ray);
// }
//
// t_color			calculate_combined_color(t_color color, t_color reflect_color, t_color refract_color, t_ray ray, float cumul_coef)
// {
// 	float		r0;
// 	float		c1;
// 	float		c2;
// 	t_color		composed_color;
//
// 	r0 = (ray.medium_index - ray.hitpoint.object->material.medium_index) / (ray.medium_index + ray.hitpoint.object->material.medium_index);
// 	r0 *= r0;
// 	c1 = -dot_product(ray.hitpoint.normal, ray.d);
// 	c2 = 1 - c1;
// 	r0 = r0 + (1 - r0) * c2 * c2 * c2 * c2 * c2;
// 	composed_color = add_color(scalar_color(r0, reflect_color), scalar_color(1 - r0, refract_color));
// 	color = add_color(color, scalar_color(cumul_coef, composed_color));
// 	return (color);
// }
//
// t_color			reflection_refraction(t_env *e, t_ray ray, int depth, float cumul_coef)
// {
// 	t_color		color;
// 	t_color		reflect_color;
// 	t_color		refract_color;
//
// 	if (depth)
// 		ray.medium_index = ray.hitpoint.object->material.medium_index;
// 	reflect_color = new_color(BLACK);
// 	refract_color = new_color(BLACK);
// 	ray.t = get_ray_intersection(e->scene->objects, &ray);
// 	if (!(ray.hitpoint.object))
// 		return (e->scene->background_color);
// 	color = illuminate(e, &ray);
// 	if (depth == MAX_DEPTH || cumul_coef < 0.02)
// 		return (color);
// 	if (ray.hitpoint.object->material.reflexion)
// 		reflect_color = reflection_refraction(e, reflected_ray(ray), depth + 1, cumul_coef * ray.hitpoint.object->material.reflexion);
// 	if (ray.hitpoint.object->material.refraction)
// 		refract_color = reflection_refraction(e, refracted_ray(ray), depth + 1, cumul_coef * ray.hitpoint.object->material.refraction);
// 	return (calculate_combined_color(color, reflect_color, refract_color, ray, cumul_coef));
// }

// void			dup_ray(t_ray *dst, t_ray *src)
// {
// 	dst->o = src->o;
// 	dst->d = src->d;
// 	dst->current_refraction = src->current_refraction;
// }
//
// t_color			recursion(t_env *e, t_ray *ray, t_ray *o_ray, int depth, t_color color, float cumul_coef)
// {
// 	t_color		reflection_col;
// 	t_color		refraction_col;
// 	int			hit;
// 	float		kt;
// 	float		kr;
//
// 	hit = 1;
// 	if (depth > 0 && cumul_coef > EPSILON)
// 	{
// 		dup_ray(o_ray, ray);
// 		ray->current_refraction = ray->hitpoint.object->material.refraction;
// 		reflected_ray(ray);
// 		ray->t = get_ray_intersection(e->scene->objects, ray);
// 		if (!(ray->hitpoint.object))
// 		{
// 			hit = 0;
// 			reflection_col = new_color(BLACK);
// 		}
// 		else
// 			reflection_col = add_color(recursion(e, ray, o_ray, depth - 1, color, cumul_coef * ray->hitpoint.object->material.reflexion), scalar_color(cumul_coef, illuminate(e, ray)));
// 		if (refracted_ray(o_ray, ray, o_ray->current_refraction, ray->current_refraction) == -1)
// 		{
// 			kr = 1;
// 			refraction_col = new_color(BLACK);
// 		}
// 		else
// 		{
// 			kr = fresnel_reflectance(o_ray, ray, o_ray->current_refraction, ray->current_refraction);
// 			if (kr < 1)
// 				refraction_col = add_color(recursion(e, ray, o_ray, depth - 1, color, cumul_coef * (1 - kr)), scalar_color(cumul_coef, illuminate(e, ray)));
// 			else
// 				refraction_col = new_color(BLACK);
// 		}
// 		kt = 1 - kr;
// 		color = add_color(color, add_color(scalar_color(kr, reflection_col), scalar_color(kt, refraction_col)));
// 		return (color);
// 	}
// 	else
// 		return (color);
// }
//
// t_color			reflection(t_env *e, t_ray *ray)
// {
// 	int			i;
// 	t_color		color;
// 	t_ray		o_ray;
// 	float		cumul_coef;
//
// 	dup_ray(&o_ray, ray);
// 	cumul_coef = ray->hitpoint.object->material.reflexion;
// 	i = -1;
// 	color = new_color(BLACK);
// 	printf("before\n");
// 	color = recursion(e, ray, &o_ray, REF_DEPTH, color, cumul_coef);
// 	printf("out\n");
// 	return (color);
// }

// t_ray				*refracted_ray(t_ray *ray)
// {
// 	float		n;
// 	float		cos_i;
// 	float		sin_t2;
// 	float		cos_t;
// 	float		tmp;
// 	t_ray		*new_ray;
//
// 	new_ray = ray;
// 	new_ray->o = new_ray->hitpoint.pos;
// 	n = new_ray->medium_index / new_ray->hitpoint.object->material.refraction;
// 	cos_i = -dot_product(new_ray->hitpoint.normal, new_ray->d);
// 	sin_t2 = n * n * (1.0 - cos_i * cos_i);
// 	if (sin_t2 > 1.0)
// 		return (-1);
// 	cos_t = sqrtf(1.0 - sin_t2);
// 	tmp = n * cos_i - cos_t;
// 	ray->d = vector_add(vector_scalar(n, o_ray->d), vector_scalar(tmp, ray->hitpoint.normal));
// 	return (0);
// }

// t_color			reflection_refraction(t_env *e, t_ray *ray)
// {
// 	int			i;
// 	t_color		color;
// 	t_ray		o_ray;
// 	float		cumul_coef;
// 	t_color		asupTmp;
//
// 	dup_ray(&o_ray, ray);
// 	// reflected_ray(o_ray, ray);
// 	cumul_coef = ray->hitpoint.object->material.reflexion;
// 	i = -1;
// 	color = new_color(BLACK);
// 	//REF_COEF should be multiply each iteration by the reflection coef of the last object hit
// 	while (++i < REF_DEPTH && cumul_coef > EPSILON)
// 	{
// 		reflected_ray(ray);
// 		ray->t = get_ray_intersection(e->scene->objects, ray);
// 		if (!(ray->hitpoint.object))
// 			break ;
// 		asupTmp = scalar_color(cumul_coef, illuminate(e, ray));
// 		color = add_color(color, asupTmp);
// 		// color = add_color(color, scalar_color(cumul_coef, illuminate(e, ray)));
// 		cumul_coef *= ray->hitpoint.object->material.reflexion;
// 		// printf("cumul:%lf\n", cumul_coef);
// 		dup_ray(&o_ray, ray);
// 	}
// 	return (color);
// }
