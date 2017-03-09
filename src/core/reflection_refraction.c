/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:58:39 by hbock             #+#    #+#             */
/*   Updated: 2017/03/08 14:58:39 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vector	reflected_dir(t_ray *ray)
{
	float		tmp;
	t_vector	normal;
	t_vector	new_dir;

	normal = get_normal(ray);
	tmp = 2 * dot_product(ray->d, normal);
	new_dir = vector_scalar(tmp, normal);
	new_dir = vector_sub(ray->d, new_dir);
	return (new_dir);
}

void			reflected_ray(t_ray *ray)
{
	ray->o = ray->hitpoint.pos;
	ray->d = reflected_dir(ray);
}

t_color			reflection(t_env *e, t_ray *ray)
{
	int			i;
	t_color		color;

	i = -1;
	//create a function to initialize a colore
	color.r = 0;
	color.g = 0;
	color.b = 0;
	//REF_COEF should be multiply each iteration by the reflection coef of the last object hit
	while (++i < REF_DEPTH && REF_COEF > EPSILON)
	{
		ray->hitpoint.object = NULL;
		ray->t = get_ray_intersection(e->scene->objects, ray);
		if (!(ray->hitpoint.object))
			break ;
		color = add_color(color, scalar_color(REF_COEF, illuminate(e, ray)));
	}
	return (color);
}
