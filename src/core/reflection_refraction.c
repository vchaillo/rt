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
	float		cos_i;

	cos_i = -dot_product(ray->hitpoint.normal, ray->d);
	ray->d = vector_add(ray->d, vector_scalar(2 * cos_i, ray->hitpoint.normal));
	ray->o = ray->hitpoint.pos;
}

// int				refracted_ray(t_ray *o_ray, t_ray *ray, float n1, float n2)
// {
// 	float		n;
// 	float		cos_i;
// 	float		sin_t2;
// 	float		cos_t;
// 	float		tmp;
//
// 	ray->o = o_ray->hitpoint.pos;
// 	n = n1 / n2;
// 	cos_i = -dot_product(ray->hitpoint.normal, ray->d);
// 	sin_t2 = n * n * (1.0 - cos_i * cos_i);
// 	if (sin_t2 > 1.0)
// 		return (-1);
// 	cos_t = sqrtf(1.0 - sin_t2);
// 	tmp = n * cos_i - cos_t;
// 	ray->d = vector_add(vector_scalar(n, o_ray->d), vector_scalar(tmp, ray->hitpoint.normal));
// 	return (0);
// }
//
// // //maybe make a struct to avoid the recomputation of n cos_i and sin_t2
//
// float			fresnel_reflectance(t_ray *o_ray, t_ray *ray, float n1, float n2)
// {
// 	float		n;
// 	float		cos_i;
// 	float		sin_t2;
// 	float		cos_t;
// 	float		ref_ortho;
// 	float		ref_paral;
//
// 	n = n1 / n2;
// 	cos_i = -dot_product(ray->hitpoint.normal, o_ray->d);
// 	sin_t2 = n * n * (1.0 - cos_i * cos_i);
// 	if (sin_t2 > 1.0)
// 		return (1);
// 	cos_t = sqrtf(1.0 - sin_t2);
// 	ref_ortho = (n1 * cos_i - n2 * cos_t) / (n1 * cos_i + n2 * cos_t);
// 	ref_paral = (n2 * cos_i - n1 * cos_t) / (n2 * cos_i + n1 * cos_t);
// 	return ((ref_ortho * ref_ortho + ref_paral * ref_paral) / 2.0);
// }
//
void			dup_ray(t_ray *dst, t_ray *src)
{
	dst->o = src->o;
	dst->d = src->d;
	dst->current_refraction = src->current_refraction;
}
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

t_color			reflection(t_env *e, t_ray *ray)
{
	int			i;
	t_color		color;
	t_ray		o_ray;
	float		cumul_coef;
	t_color		asupTmp;

	dup_ray(&o_ray, ray);
	// reflected_ray(o_ray, ray);
	cumul_coef = ray->hitpoint.object->material.reflexion;
	i = -1;
	color = new_color(BLACK);
	//REF_COEF should be multiply each iteration by the reflection coef of the last object hit
	while (++i < REF_DEPTH && cumul_coef > EPSILON)
	{
		reflected_ray(ray);
		ray->t = get_ray_intersection(e->scene->objects, ray);
		if (!(ray->hitpoint.object))
			break ;
		asupTmp = scalar_color(cumul_coef, illuminate(e, ray));
		color = add_color(color, asupTmp);
		// color = add_color(color, scalar_color(cumul_coef, illuminate(e, ray)));
		cumul_coef *= ray->hitpoint.object->material.reflexion;
		// printf("cumul:%lf\n", cumul_coef);
		dup_ray(&o_ray, ray);
	}
	return (color);
}
