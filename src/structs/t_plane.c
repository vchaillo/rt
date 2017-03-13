/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_plane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:51 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/13 17:12:02 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_plane			*new_plane(t_vector vect, float offset, int type)
{
	t_plane		*plane;

	if (!(plane = (t_plane*)malloc(sizeof(t_plane))))
		print_error(MALLOC_ERROR);
	plane->normal = normalize(vect);
	plane->offset = offset;
	plane->type = type;
	return (plane);
}

void			delete_plane(t_plane *plane)
{
	free(plane);
}
