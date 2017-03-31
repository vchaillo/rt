/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tore.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:04:11 by valentin          #+#    #+#             */
/*   Updated: 2017/03/31 04:18:46 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	is_out_limit(const t_tore *tore, const t_ray *ray, const float t)
{
	t_vector	relative_pos;

	if (!tore->limit_min.x && !tore->limit_min.y && !tore->limit_min.z
		&& !tore->limit_max.x && !tore->limit_max.y && !tore->limit_max.z)
		return (0);
	relative_pos.x = (ray->o.x + ray->d.x * t) - tore->pos.x;
	relative_pos.y = (ray->o.y + ray->d.y * t) - tore->pos.y;
	relative_pos.z = (ray->o.z + ray->d.z * t) - tore->pos.z;
	if ((tore->limit_max.x > 0 || tore->limit_min.x < 0)
		&& (relative_pos.x > tore->limit_max.x ||
		relative_pos.x < tore->limit_min.x))
		return (1);
	if ((tore->limit_max.y > 0 || tore->limit_min.y < 0)
		&& (relative_pos.y > tore->limit_max.y
			|| relative_pos.y < tore->limit_min.y))
		return (1);
	if ((tore->limit_max.z > 0 || tore->limit_min.z < 0)
		&& (relative_pos.z > tore->limit_max.z
			|| relative_pos.z < tore->limit_min.z))
		return (1);
	return (0);
}

/*
** Ray to hit tore intersection is a 4th degree equation.
** eq4[5] is the e, d, c, b, a parameters of that equation.
*/

float		hit_tore(t_tore *tore, t_ray *ray)
{
	double		eq[5];
	double		tmp[7];
	float		t;

	tmp[6] = 4.0 * tore->big_r * tore->big_r;
	tmp[0] = ray->d.x * ray->d.x + ray->d.y * ray->d.y + ray->d.z * ray->d.z;
	tmp[1] = 2.0 * (ray->d.x * ray->o.x
					+ ray->d.y * ray->o.y + ray->d.z * ray->o.z);
	tmp[2] = ray->o.x * ray->o.x + ray->o.y * ray->o.y + ray->o.z * ray->o.z +
		tore->big_r * tore->big_r - tore->r * tore->r;
	tmp[3] = tmp[6] * (ray->d.x * ray->d.x + ray->d.z * ray->d.z);
	tmp[4] = tmp[6] * 2 * (ray->d.x * ray->o.x + ray->d.z * ray->o.z);
	tmp[5] = tmp[6] * (ray->o.x * ray->o.x + ray->o.z * ray->o.z);
	eq[4] = pow(tmp[0], 2);
	eq[3] = 2.0 * tmp[0] * tmp[1];
	eq[2] = 2.0 * tmp[0] * tmp[2] + pow(tmp[1], 2) - tmp[3];
	eq[1] = 2.0 * tmp[1] * tmp[2] - tmp[4];
	eq[0] = pow(tmp[2], 2) - tmp[5];
	eq[0] /= eq[4];
	eq[1] /= eq[4];
	eq[2] /= eq[4];
	eq[3] /= eq[4];
	eq[4] = 1;
	t = solve_deg4(eq);
	return (is_out_limit(tore, ray, t) ? 0 : t);
}
