/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 02:57:45 by hbock             #+#    #+#             */
/*   Updated: 2017/03/24 02:57:45 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			refracted_ray_for_the_norm(t_fresnel *f, t_vector *n)
{
	if (f->cosi < 0)
		f->cosi = -f->cosi;
	else
	{
		f->tmp = f->etai;
		f->etai = f->etat;
		f->etat = f->tmp;
		*n = new_vector(-n->x, -n->y, -n->z);
	}
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
	refracted_ray_for_the_norm(&f, &n);
	eta = f.etai / f.etat;
	k = 1 - eta * eta * (1 - f.cosi * f.cosi);
	if (k < 0)
		ray->d = new_vector(0, 0, 0);
	else
		ray->d = vector_add(vector_scalar(eta, ray->d),
		vector_scalar(eta * f.cosi - sqrtf(k), n));
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

t_color			refraction(t_env *e, t_ray *ray, t_ref r, float coef)
{
	float		kr;
	t_color		composed_color;

	fresnel(ray, &kr);
	if (kr < 1)
	{
		if (!refracted_ray(&(r.refract_ray)))
		{
			r.refract_color = depth_compute(e, &(r.refract_ray), r.depth
			+ 1, (1 - kr) * coef);
			r.refract_color = add_color(
				scalar_color(ray->hitpoint.object->material.refraction,
				r.refract_color),
				scalar_color(1 - ray->hitpoint.object->material.refraction,
					ray->hitpoint.object->color));
		}
	}
	reflected_ray(&(r.reflect_ray));
	r.reflect_color = depth_compute(e, &(r.reflect_ray), r.depth + 1,
		kr * coef);
	composed_color = add_color(scalar_color(kr, r.reflect_color),
		scalar_color(1 - kr, r.refract_color));
	return (add_color(r.color, composed_color));
}
