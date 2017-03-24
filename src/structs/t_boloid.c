/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_boloid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <tlegroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 00:09:43 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/24 03:02:40 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_boloid		*new_boloid(t_vector pos, float abc[], float sign,
					t_vector limits[])
{
	t_boloid	*boloid;

	if (!(boloid = (t_boloid*)malloc(sizeof(t_boloid))))
		print_error(MALLOC_ERROR);
	boloid->pos = pos;
	boloid->a = abc[0];
	boloid->b = abc[1];
	boloid->c = abc[2];
	boloid->limit_min = limits[0];
	boloid->limit_max = limits[1];
	boloid->sign = sign;
	return (boloid);
}

void			delete_boloid(t_boloid *boloid)
{
	free(boloid);
}
