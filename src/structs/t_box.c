/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 07:55:18 by hbock             #+#    #+#             */
/*   Updated: 2017/03/14 07:55:18 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_box			*new_box(t_vector corner, t_vector translation, t_vector rotxyz)
{
	t_box		*box;

	if (!(box = (t_box*)malloc(sizeof(t_box))))
		print_error(MALLOC_ERROR);
    corner.x = (corner.x >= 0) ? corner.x : -corner.x;
    corner.y = (corner.y >= 0) ? corner.y : -corner.y;
    corner.z = (corner.z >= 0) ? corner.z : -corner.z;
    box->corner_min = corner;
    box->corner_max = vector_scalar(-1, corner);
    box->trans = translation;
    box->rotxyz = rotxyz;
	return (box);
}

void			delete_box(t_box *box)
{
	free(box);
}
