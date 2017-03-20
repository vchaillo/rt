/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_disc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 07:55:18 by hbock             #+#    #+#             */
/*   Updated: 2017/03/14 07:55:18 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_disc		*new_disc(float r_max, float r_min, t_vector pos, t_vector rotxyz)
{
	t_disc	*disc;

	if (!(disc = (t_disc*)malloc(sizeof(t_disc))))
		print_error(MALLOC_ERROR);
	disc->pos = pos;
	disc->rotxyz = rotxyz;
	disc->r_max = r_max;
	disc->r_min = r_min;
	return (disc);
}

void			delete_disc(t_disc *disc)
{
	free(disc);
}
