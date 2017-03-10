/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_plane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:51 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/10 22:40:24 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_plane			*new_plane(float x, float y, float z, float offset, int type)
{
	t_plane		*plane;

	if (!(plane = (t_plane*)malloc(sizeof(t_plane))))
		print_error(MALLOC_ERROR);
	plane->normal = normalize(new_vector(x, y, z));
	plane->offset = offset;
	plane->type = type;
	return (plane);
}

void			delete_plane(t_plane *plane)
{
	free(plane);
}
