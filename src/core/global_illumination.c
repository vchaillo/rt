/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_illumination.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 00:42:30 by hbock             #+#    #+#             */
/*   Updated: 2017/03/24 00:42:31 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			hitpoint_coordinate_system(t_vector n, t_vector *nt,
					t_vector *nb)
{
	if (fabs(n.x) > fabs(n.y))
	{
		*nt = new_vector(n.z, 0, -n.x);
		*nt = vector_scalar((1 / sqrtf(n.x * n.x + n.z * n.z)), *nt);
	}
	else
	{
		*nt = new_vector(0, -n.z, n.y);
		*nt = vector_scalar((1 / sqrtf(n.y * n.y + n.z * n.z)), *nt);
	}
	*nb = cross_product(n, *nt);
}

t_vector		unoriented_sample(float *r1, float *r2)
{
	float		sin_teta;
	float		phi;
	float		x;
	float		z;

	*r1 = (1.0 / RAND_MAX) * rand();
	*r2 = (1.0 / RAND_MAX) * rand();
	sin_teta = sqrtf(1 - *r1 * *r1);
	phi = 2 * M_PI * *r2;
	x = sin_teta * cosf(phi);
	z = sin_teta * sinf(phi);
	return (new_vector(x, *r1, z));
}

float			indirect_light_dist_power(float t)
{
	return (1 / expf(t / 6));
}

t_color			global_illumination(t_env *e, t_ray *ray)
{
	t_gi		g;

	g.indirect_light = new_color(BLACK);
	hitpoint_coordinate_system(ray->hitpoint.normal, &(g.nt), &(g.nb));
	g.pdf = 1 / (2 * M_PI);
	g.i = -1;
	while (++g.i < SAMPLE_PER_PIX)
	{
		g.sample = unoriented_sample(&(g.r1), &(g.r2));
		g.sample_world = new_vector(g.sample.x * g.nb.x + g.sample.y *
		ray->hitpoint.normal.x + g.sample.z * g.nt.x, g.sample.x * g.nb.y +
		g.sample.y * ray->hitpoint.normal.y + g.sample.z * g.nt.y, g.sample.x *
		g.nb.z + g.sample.y * ray->hitpoint.normal.z + g.sample.z * g.nt.z);
		g.sample_world = normalize(g.sample_world);
		g.tmp = *ray;
		g.tmp.o = ray->hitpoint.pos;
		g.tmp.d = g.sample_world;
		g.tmp.t = get_ray_intersection(e->scene->objects, &(g.tmp));
		if (g.tmp.hitpoint.object)
			g.indirect_light = add_color(g.indirect_light, scalar_color(g.r1 *
				indirect_light_dist_power(g.tmp.t), illuminate(e, &(g.tmp))));
	}
	g.indirect_light = scalar_color(GI_POWER / (SAMPLE_PER_PIX * g.pdf),
	g.indirect_light);
	return (g.indirect_light);
}
