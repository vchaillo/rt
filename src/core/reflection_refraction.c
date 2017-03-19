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
	n = AIR_IOR / ray->hitpoint.object->material.ior;;
	// n = ray->past_ior / ray->ior;
	c1 = -dot_product(ray->hitpoint.normal, ray->d);
	c2 = n * n * (1 - c1 * c1);
	if (c2 > 1)
		return (1);
	c2 = sqrtf(1 - c2);
	ray->d = vector_add(vector_scalar(n, ray->d), vector_scalar(n * c1 - c2,
		ray->hitpoint.normal));
	return (0);
}

void			fresnel(t_ray *ray, float *kr)
{
	t_fresnel	f;

	f.etai = AIR_IOR;
	f.etat = ray->hitpoint.object->material.ior;
	f.cosi = dot_product(ray->d, ray->hitpoint.normal);
	f.cosi = fminf(fmaxf(f.cosi, 1), -1);
	if (f.cosi > 0)
	{
		f.tmp = f.etai;
		f.etai = f.etat;
		f.etat = f.tmp;
	}
	f.sint = f.etai / f.etat * sqrtf(fmaxf(0.f, 1 - f.cosi * f.cosi));
	if (f.sint >= 1)
		*kr = 1;
	else
	{
		f.cost = sqrtf(fmaxf(0.f, 1 - f.sint * f.sint));
		f.cosi = fabsf(f.cosi);
		f.rs = ((f.etat * f.cosi) - (f.etai * f.cost)) / ((f.etat * f.cosi) +
			(f.etai * f.cost));
		f.rp = ((f.etai * f.cosi) - (f.etat * f.cost)) / ((f.etai * f.cosi) +
			(f.etat * f.cost));
		*kr = (f.rs * f.rs + f.rp * f.rp) / 2;
	}
}

t_color			calculate_combined_color(t_ref r, t_ray *ray, float cumul_coef)
{
	float		kr;
	t_color		composed_color;

	fresnel(ray, &kr);
	composed_color = add_color(scalar_color(kr, r.reflect_color),
		scalar_color(1 - kr, r.refract_color));
	r.color = add_color(r.color, composed_color);
	(void)cumul_coef;
	// r.color = add_color(r.color, scalar_color(cumul_coef, composed_color));
	return (r.color);
}

t_color			reflection_refraction(t_env *e, t_ray *ray, int depth,
	float coef)
{
	t_ref		r;

	r.reflect_color = new_color(BLACK);
	r.refract_color = new_color(BLACK);
	ray->t = get_ray_intersection(e->scene->objects, ray);
	if (!(ray->hitpoint.object))
		return (e->scene->background_color);
	r.color = illuminate(e, ray);
	if (depth == MAX_DEPTH || coef < 0.02)
		return (r.color);
	r.reflect_ray = *ray;
	r.refract_ray = *ray;
	if (r.reflect_ray.hitpoint.object->material.reflexion)
	{
		reflected_ray(&(r.reflect_ray));
		r.reflect_color = reflection_refraction(e, &(r.reflect_ray), depth + 1,
			coef * r.reflect_ray.hitpoint.object->material.reflexion);
	}
	if (r.refract_ray.hitpoint.object->material.refraction)
	{
		if (!refracted_ray(&(r.refract_ray)))
			r.refract_color = reflection_refraction(e, &(r.refract_ray), depth
			+ 1, coef * r.refract_ray.hitpoint.object->material.refraction);
	}
	return (calculate_combined_color(r, ray, coef));
}
