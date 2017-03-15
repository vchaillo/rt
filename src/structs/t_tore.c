/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tore.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 00:06:06 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/14 00:13:05 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_tore		*new_tore(t_vector pos, float r, float big_r)
{
	t_tore	*tore;

	if (!(tore = (t_tore*)malloc(sizeof(t_tore))))
		print_error(MALLOC_ERROR);
	tore->pos = pos;
	tore->r = r;
	tore->big_r = big_r;
	return (tore);
}

void		delete_tore(t_tore *tore)
{
	free(tore);
}