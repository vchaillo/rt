/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tore.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:04:11 by valentin          #+#    #+#             */
/*   Updated: 2017/03/13 19:56:59 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Ray to hit tore intersection is a 4th degree equation.
** eq4[5] is the e, d, c, b, a parameters of that equation.
*/

float			hit_tore(t_tore *tore, t_ray *ray)
{
	double		dir[3];
	double		pos[3];
	double		eq[5];
	double		tmp[7];
	float		t;

	dir[0] = ray->d.x;
	dir[1] = ray->d.y;
	dir[2] = ray->d.z;
	pos[0] = ray->o.x;
	pos[1] = ray->o.y;
	pos[2] = ray->o.z;
	tmp[6] = 4.0 * tore->big_r * tore->big_r;
	tmp[0] = dir[0] * dir[0] + dir[1] * dir[1] + dir[2] * dir[2];
	tmp[1] = 2.0 * (dir[0] * pos[0] + dir[1] * pos[1] + dir[2] * pos[2]);
	tmp[2] = pos[0] * pos[0] + pos[1] * pos[1] + pos[2] * pos[2] +
	       	 tore->big_r * tore->big_r - tore->r * tore->r;
	tmp[3] = tmp[6] * (dir[0] * dir[0] + dir[2] * dir[2]);
	tmp[4] = tmp[6] * 2 * (dir[0] * pos[0] + dir[2] * pos[2]);
	tmp[5] = tmp[6] * (pos[0] * pos[0] + pos[2] * pos[2]);
	
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
	if (t != INFINITY && t > EPSILON)
	{
	  //printf("%.18lf*x^4 + %.18lf*x^3 + %.18lf*x^2 + %.18lf*x + %.18lf = 0\nx = %lf\n", eq4[4], eq4[3] , eq4[2] , eq4[1] , eq4[0] , t);
	}
	// printf("t: %lf\n", t);
	return (t);
}
