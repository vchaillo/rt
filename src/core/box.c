/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <hbock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 07:55:18 by hbock             #+#    #+#             */
/*   Updated: 2017/03/30 16:58:38 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray				ray_coord_modif(t_ray *ray, t_vector trans, t_vector rotxyz)
{
	t_ray			new;

	new.o = vector_sub(ray->o, trans);
	new.d = vector_rot_x(ray->d, -rotxyz.x);
	new.d = vector_rot_y(new.d, -rotxyz.y);
	new.d = vector_rot_z(new.d, -rotxyz.z);
	new.o = vector_rot_x(new.o, -rotxyz.x);
	new.o = vector_rot_y(new.o, -rotxyz.y);
	new.o = vector_rot_z(new.o, -rotxyz.z);
	return (new);
}

t_vector			normal_box(t_box *box, int normal)
{
	t_vector		real_normal;

	if (normal == 0)
		real_normal = new_vector(1, 0, 0);
	else if (normal == 1)
		real_normal = new_vector(-1, 0, 0);
	else if (normal == 2)
		real_normal = new_vector(0, 1, 0);
	else if (normal == 3)
		real_normal = new_vector(0, -1, 0);
	else if (normal == 4)
		real_normal = new_vector(0, 0, 1);
	else
		real_normal = new_vector(0, 0, -1);
	real_normal = vector_rot_x(real_normal, box->rotxyz.x);
	real_normal = vector_rot_y(real_normal, box->rotxyz.y);
	real_normal = vector_rot_z(real_normal, box->rotxyz.z);
	return (normalize(real_normal));
}

float				hit_box(t_box *box, t_ray *ray)
{
	float			tmin;
	float			tmax;
	float			tymin;
	float			tymax;
	float			tzmin;
	float			tzmax;
	int				normal;
	int				tmp_normal;
	t_ray			r;

	r = ray_coord_modif(ray, box->trans, box->rotxyz);
	normal = 0;
	tmin = (box->corner_min.x - r.o.x) / r.d.x;
	tmax = (box->corner_max.x - r.o.x) / r.d.x;

	if (tmin > tmax)
	{
		normal = 1;
		ft_swapf(&tmin, &tmax);
	}

	tmp_normal = 2;
	tymin = (box->corner_min.y - r.o.y) / r.d.y;
	tymax = (box->corner_max.y - r.o.y) / r.d.y;

	if (tymin > tymax)
	{
		tmp_normal = 3;
		ft_swapf(&tymin, &tymax);
	}

	if ((tmin > tymax) || (tymin > tmax))
	return FLT_MAX;

	if (tymin > tmin)
	{
		normal = tmp_normal;
		tmin = tymin;
	}

	if (tymax < tmax)
	tmax = tymax;

	tmp_normal = 4;
	tzmin = (box->corner_min.z - r.o.z) / r.d.z;
	tzmax = (box->corner_max.z - r.o.z) / r.d.z;

	if (tzmin > tzmax)
	{
		tmp_normal = 5;
		ft_swapf(&tzmin, &tzmax);
	}

	if ((tmin > tzmax) || (tzmin > tmax))
	return FLT_MAX;

	if (tzmin > tmin)
	{
		tmin = tzmin;
		normal = tmp_normal;
	}

	if (tzmax < tmax)
	tmax = tzmax;
	if (tmin > tmax)
	normal = 5;
	ray->hitpoint.normal = normal_box(box, normal);
	return ((tmin <= tmax) ? tmin : tmax);
}
