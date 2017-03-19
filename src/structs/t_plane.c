/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_plane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:51 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/13 21:34:52 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// t_limit			new_limits(int is_limited, t_vector mins, t_vector maxs)
// {
// 	t_limit		l;
//
// 	l.is_limited = is_limited;
// 	l.mins = mins;
// 	l.maxs = maxs;
// 	return (l);
// }
//
// void			init_plane_limits(t_plane *plane, t_limit l, t_vector n)
// {
// 	t_vector	tmp1;
// 	t_vector	tmp2;
//
// 	plane->mins = l.mins;
// 	plane->maxs = l.maxs;
// 	tmp1 = new_vector(min.x, 0, 0);
// 	tmp2 = new_vector(max.x, 0, 0);
// 	vector_rot_axis(tmp1, t_vector axis, float angle);
// }
//
// t_plane			*new_plane(t_vector normal, float offset, int type, t_limit l)
// {
// 	t_plane		*plane;
//
// 	if (!(plane = (t_plane*)malloc(sizeof(t_plane))))
// 		print_error(MALLOC_ERROR);
// 	plane->normal = normalize(normal);
// 	plane->offset = offset;
// 	plane->type = type;
// 	plane->is_limited = l.is_limited;
// 	if (l.is_limited)
// 		init_plane_limits(plane, l, normal);
// 	return (plane);
// }

t_plane			*new_plane(t_vector normal, float offset, int type,
				   t_vector limits[])
{
	t_plane		*plane;

	if (!(plane = (t_plane*)malloc(sizeof(t_plane))))
		print_error(MALLOC_ERROR);
	plane->normal = normalize(normal);
	plane->offset = offset;
	plane->type = type;
	plane->limit_min = limits[0];
	plane->limit_max = limits[1];
	return (plane);
}

void			delete_plane(t_plane *plane)
{
	free(plane);
}
