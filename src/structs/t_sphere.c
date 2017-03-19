/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sphere.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:25:01 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/13 21:35:11 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_sphere		*new_sphere(t_vector pos, float r, t_vector axis,
				    t_vector limits[])
{
	t_sphere	*sphere;

	if (!(sphere = (t_sphere*)malloc(sizeof(t_sphere))))
		print_error(MALLOC_ERROR);
	sphere->axis = axis;
	sphere->limit_min = limits[0];
	sphere->limit_max = limits[1];
	sphere->pos = pos;
	sphere->r = r;
	return (sphere);
}

void			delete_sphere(t_sphere *sphere)
{
	free(sphere);
}
