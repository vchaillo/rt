/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_plane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:51 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/09 18:33:36 by valentinchaillou89###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_plane			*new_plane(float x, float y, float z, float offset, int wave)
{
	t_plane		*plane;

	if (!(plane = (t_plane*)malloc(sizeof(t_plane))))
		print_error(MALLOC_ERROR);
	plane->normal = normalize(new_vector(x, y, z));
	plane->offset = offset;
	plane->wave = wave;
	return (plane);
}

void			delete_plane(t_plane *plane)
{
	free(plane);
}
