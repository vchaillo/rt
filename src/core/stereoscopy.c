/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stereoscopy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 06:06:23 by valentin          #+#    #+#             */
/*   Updated: 2017/03/24 04:06:53 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			stereoscopy(t_env *e)
{
	t_color		color;
	int			x;
	int			y;

	if (e->scene->effect == STEREO)
	{
		y = -1;
		while (++y < WIN_H)
		{
			x = -1;
			while (++x < WIN_W)
			{
				color.r = e->scene->color_array[y][x].r;
				color.g = e->scene->color_array[y][x].g;
				color.b = e->scene->color_array[y][x].b;
				if (x < WIN_W - 10)
					color.r = e->scene->color_array[y][x + 10].r;
				fill_pixel(e, color, x, y);
			}
		}
	}
}
