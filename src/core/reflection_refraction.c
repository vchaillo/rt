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
	ray->d = normalize(ray->d);
}

int				refracted_ray(t_ray *ray)
{
	t_fresnel	f;
	t_vector	n;
	float		k;
	float		eta;

	f.etai = AIR_IOR;
	f.etat = ray->hitpoint.object->material.ior;
	f.cosi = dot_product(ray->d, ray->hitpoint.normal);
	f.cosi = fminf(fmaxf(f.cosi, -1), 1);


	n = new_vector(ray->hitpoint.normal.x, ray->hitpoint.normal.y,
		ray->hitpoint.normal.z);
	if (f.cosi < 0)
		f.cosi = -f.cosi;
	else
	{
		f.tmp = f.etai;
		f.etai = f.etat;
		f.etat = f.tmp;
		n = new_vector(-n.x, -n.y, -n.z);
	}
	eta = f.etai / f.etat;
	k = 1 - eta * eta * (1 - f.cosi * f.cosi);
	if (k < 0)
		ray->d = new_vector(0, 0, 0);
	else
		ray->d = vector_add(vector_scalar(eta, ray->d), vector_scalar(eta * f.cosi - sqrtf(k), n));
	ray->d = normalize(ray->d);
	ray->o = ray->hitpoint.pos;
	return (0);
}

void			fresnel(t_ray *ray, float *kr)
{
	t_fresnel	f;

	f.etai = AIR_IOR;
	f.etat = ray->hitpoint.object->material.ior;
	f.cosi = dot_product(ray->d, ray->hitpoint.normal);
	f.cosi = fminf(fmaxf(f.cosi, -1), 1);
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

t_color			reflection_refraction(t_env *e, t_ray *ray, int depth,
	float coef)
{
	t_ref		r;
	float		kr;
	t_color		composed_color;

	r.color = new_color(BLACK);
	r.reflect_color = new_color(BLACK);
	r.refract_color = new_color(BLACK);
	ray->t = get_ray_intersection(e->scene->objects, ray);
	if (!(ray->hitpoint.object))
		return (e->scene->background_color);
	// r.color = illuminate(e, ray);
	if (depth == MAX_DEPTH || coef < 0.02)
		return (r.color);
	r.reflect_ray = *ray;
	r.refract_ray = *ray;
	if (ray->hitpoint.object->material.property == DIFFUSE)
		r.color = illuminate(e, ray);
	else if (r.reflect_ray.hitpoint.object->material.property == REFLECTIVE)
	{
		reflected_ray(&(r.reflect_ray));
		r.color = add_color(r.color, reflection_refraction(e, &(r.reflect_ray), depth + 1,
			r.reflect_ray.hitpoint.object->material.reflexion * coef));
		r.color = add_color(scalar_color(ray->hitpoint.object->material.reflexion, r.color), scalar_color(1 - ray->hitpoint.object->material.reflexion, illuminate(e, ray)));
	}
	else if (r.refract_ray.hitpoint.object->material.property == TRANSMITIVE)
	{
		fresnel(ray, &kr);
		if (kr < 1)
		{
			if (!refracted_ray(&(r.refract_ray)))
			{
				r.refract_color = reflection_refraction(e, &(r.refract_ray), depth
				+ 1, (1 - kr) * coef);
				r.refract_color = add_color(scalar_color(ray->hitpoint.object->material.refraction, r.refract_color), scalar_color(1 - ray->hitpoint.object->material.refraction, ray->hitpoint.object->color));
			}
		}
		reflected_ray(&(r.reflect_ray));
		r.reflect_color = reflection_refraction(e, &(r.reflect_ray), depth + 1,
			kr * coef);
		composed_color = add_color(scalar_color(kr, r.reflect_color),
			scalar_color(1 - kr, r.refract_color));
		r.color = add_color(r.color, composed_color);
	}
	return (r.color);
}
