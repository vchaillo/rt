/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 07:55:18 by hbock             #+#    #+#             */
/*   Updated: 2017/03/14 07:55:18 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			normal_disc(t_disc *disc, int normal)
{
	t_vector	n;

	n = new_vector(0, -1, 0);
	if (normal == 0)
		n = new_vector(0, 1, 0);
	n = vector_rot_x(n, disc->rotxyz.x);
	n = vector_rot_y(n, disc->rotxyz.y);
	n = vector_rot_z(n, disc->rotxyz.z);
	disc->normal_hit = normalize(n);
}

float           hit_disc(t_disc *disc, t_ray *ray)
{
	float		t;
    t_ray		r;
	t_plane		*plane;
	t_vector	limits[2];
	t_vector	hitpos;
	float		d_from_o;

	limits[0] = new_vector(0, 0, 0);
	limits[1] = new_vector(0, 0, 0);
    r = ray_coord_modif(ray, disc->pos, disc->rotxyz);
	plane = new_plane(new_vector(0, 1, 0), 0, NORMAL, limits);
	t = hit_plane(plane, &r);
	if (t)
	{
		hitpos = vector_add(r.o, vector_scalar(t, r.d));
		d_from_o = sqrtf(hitpos.x * hitpos.x + hitpos.z * hitpos.z);
		if (d_from_o > disc->r_max || d_from_o < disc->r_min)
			return (0);
		if (dot_product(new_vector(0, -1, 0), r.d) > 0)
			normal_disc(disc, 0);
		else
			normal_disc(disc, 1);
		ray->hitpoint.normal = disc->normal_hit;
	}
	return (t);
}