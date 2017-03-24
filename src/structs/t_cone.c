/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:04:37 by valentin          #+#    #+#             */
/*   Updated: 2017/03/24 03:04:19 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_cone			*new_cone(t_vector axis, t_vector apex,
					float aperture, t_vector limits[])
{
	t_cone	*cone;

	if (!(cone = (t_cone*)malloc(sizeof(t_cone))))
		print_error(MALLOC_ERROR);
	cone->axis = normalize(axis);
	cone->apex = apex;
	cone->angle = aperture;
	cone->limit_min = limits[0];
	cone->limit_max = limits[1];
	return (cone);
}

void			delete_cone(t_cone *cone)
{
	free(cone);
}
