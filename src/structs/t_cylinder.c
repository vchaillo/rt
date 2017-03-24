/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cylinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:04:37 by valentin          #+#    #+#             */
/*   Updated: 2017/03/24 03:05:43 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_cylinder		*new_cylinder(t_vector axis, t_vector pos, float r,
					t_vector limits[])
{
	t_cylinder	*cylinder;

	if (!(cylinder = (t_cylinder*)malloc(sizeof(t_cylinder))))
		print_error(MALLOC_ERROR);
	cylinder->axis = normalize(axis);
	cylinder->pos = pos;
	cylinder->r = r;
	cylinder->limit_min = limits[0];
	cylinder->limit_max = limits[1];
	return (cylinder);
}

void			delete_cylinder(t_cylinder *cylinder)
{
	free(cylinder);
}
