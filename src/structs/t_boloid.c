/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_boloid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 00:09:43 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/14 00:18:03 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_boloid		*new_boloid(t_vector pos, float a, float b, float c)
{
	t_boloid	*boloid;

	if (!(boloid = (t_boloid*)malloc(sizeof(t_boloid))))
		print_error(MALLOC_ERROR);
	boloid->pos = pos;
	boloid->a = a;
	boloid->b = b;
	boloid->c = c;
	return (boloid);
}

void			delete_boloid(t_boloid *boloid)
{
	free(boloid);
}
