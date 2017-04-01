/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <hbock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 07:55:18 by hbock             #+#    #+#             */
/*   Updated: 2017/03/30 17:24:09 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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

float				norm_box1(float tmms[6], int normals[2])
{
	if (tmms[2] > tmms[3])
	{
		normals[1] = 3;
		ft_swapf(&(tmms[2]), &(tmms[3]));
	}
	if ((tmms[0] > tmms[3]) || (tmms[2] > tmms[1]))
		return (FLT_MAX);
	if (tmms[2] > tmms[0])
	{
		normals[0] = normals[1];
		tmms[0] = tmms[2];
	}
	if (tmms[3] < tmms[1])
		tmms[1] = tmms[3];
	normals[1] = 4;
	return (0);
}

float				norm_box2(float tmms[6], int normals[2])
{
	if (tmms[4] > tmms[5])
	{
		normals[1] = 5;
		ft_swapf(&(tmms[4]), &(tmms[5]));
	}
	if ((tmms[0] > tmms[5]) || (tmms[4] > tmms[1]))
		return (FLT_MAX);
	if (tmms[4] > tmms[0])
	{
		tmms[0] = tmms[4];
		normals[0] = normals[1];
	}
	if (tmms[5] < tmms[1])
		tmms[1] = tmms[5];
	return (0);
}

void				norm_box3(float tmms[6], int normals[2])
{
	if (tmms[0] > tmms[1])
	{
		normals[0] = 1;
		ft_swapf(&(tmms[0]), &(tmms[1]));
	}
}

float				hit_box(t_box *box, t_ray *ray, float t)
{
	float			tmms[6];
	int				normals[2];
	t_ray			r;

	r = ray_coord_modif(ray, box->trans, box->rotxyz);
	normals[0] = 0;
	tmms[0] = (box->corner_min.x - r.o.x) / r.d.x;
	tmms[1] = (box->corner_max.x - r.o.x) / r.d.x;
	norm_box3(tmms, normals);
	normals[1] = 2;
	tmms[2] = (box->corner_min.y - r.o.y) / r.d.y;
	tmms[3] = (box->corner_max.y - r.o.y) / r.d.y;
	if (norm_box1(tmms, normals))
		return (FLT_MAX);
	tmms[4] = (box->corner_min.z - r.o.z) / r.d.z;
	tmms[5] = (box->corner_max.z - r.o.z) / r.d.z;
	if (norm_box2(tmms, normals))
		return (FLT_MAX);
	tmms[0] = (tmms[0] <= tmms[1]) ? tmms[0] : tmms[1];
	if (t < EPSILON || tmms[0] < t)
		ray->hitpoint.normal = normal_box(box, normals[0]);
	return ((tmms[0] <= tmms[1]) ? tmms[0] : tmms[1]);
}
