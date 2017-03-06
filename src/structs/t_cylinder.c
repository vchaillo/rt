/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cylinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:04:37 by valentin          #+#    #+#             */
/*   Updated: 2017/01/12 23:00:58 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cylinder		*new_cylinder(t_vector axis, t_vector pos, float r)
{
	t_cylinder	*cylinder;

	if (!(cylinder = (t_cylinder*)malloc(sizeof(t_cylinder))))
		print_error(MALLOC_ERROR);
	cylinder->axis = normalize(axis);
	cylinder->pos = pos;
	cylinder->r = r;
	return (cylinder);
}

void			delete_cylinder(t_cylinder *cylinder)
{
	free(cylinder);
}
