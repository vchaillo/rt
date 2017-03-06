/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 20:50:01 by vchaillo          #+#    #+#             */
/*   Updated: 2016/11/26 16:07:23 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float			hit_sphere(t_sphere *sphere, t_ray *ray)
{
	float		t;
	double		a;
	double		b;
	double		c;

	a = dot_product(ray->d, ray->d);
	b = 2 * ray->d.x * (ray->o.x - sphere->pos.x);
	b += 2 * ray->d.y * (ray->o.y - sphere->pos.y);
	b += 2 * ray->d.z * (ray->o.z - sphere->pos.z);
	c = (ray->o.x - sphere->pos.x) * (ray->o.x - sphere->pos.x);
	c += (ray->o.y - sphere->pos.y) * (ray->o.y - sphere->pos.y);
	c += (ray->o.z - sphere->pos.z) * (ray->o.z - sphere->pos.z);
	c -= sphere->r * sphere->r;
	t = solve_deg2(a, b, c);
	return (t);
}
