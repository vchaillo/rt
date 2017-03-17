/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <hbock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 19:52:30 by hbock             #+#    #+#             */
/*   Updated: 2017/03/14 01:53:03 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ss_average(t_env *e, int x1, int y1)
{
	int		x;
	int		y;

	e->scene->color_array[y1][x1] = new_color(BLACK);
	y = y1 * e->scene->aa;
	while (y < (y1 + 1) * e->scene->aa)
	{
		x = x1 * e->scene->aa;
		while (x < (x1 + 1) * e->scene->aa)
		{
			e->scene->color_array[y1][x1].r += e->scene->color_array_aa[y][x].r;
			e->scene->color_array[y1][x1].g += e->scene->color_array_aa[y][x].g;
			e->scene->color_array[y1][x1].b += e->scene->color_array_aa[y][x].b;
			x++;
		}
		y++;
	}
	e->scene->color_array[y1][x1].r /= e->scene->aa * e->scene->aa;
	e->scene->color_array[y1][x1].g /= e->scene->aa * e->scene->aa;
	e->scene->color_array[y1][x1].b /= e->scene->aa * e->scene->aa;
}

void		super_sampling(t_env *e)
{
	int		x;
	int		y;

		y = -1;
		while (++y < WIN_H)
		{
			x = -1;
			while (++x < WIN_W)
				ss_average(e, x, y);
		}
}
