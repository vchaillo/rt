/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 19:52:30 by hbock             #+#    #+#             */
/*   Updated: 2017/03/08 19:52:30 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ss_average(t_color **src, t_color **dst, int x1, int y1)
{
	int		x;
	int		y;

	dst[y1][x1].r = 0;
	dst[y1][x1].g = 0;
	dst[y1][x1].b = 0;
	y = y1 * AA;
	while (y < (y1 + 1) * AA)
	{
		x = x1 * AA;
		while (x < (x1 + 1) * AA)
		{
			dst[y1][x1].r += src[y][x].r;
			dst[y1][x1].g += src[y][x].g;
			dst[y1][x1].b += src[y][x].b;
			x++;
		}
		y++;
	}
	dst[y1][x1].r /= AA * AA;
	dst[y1][x1].g /= AA * AA;
	dst[y1][x1].b /= AA * AA;
}

t_color		**super_sampling(t_color **colors)
{
	int		x;
	int		y;
	t_color	**final_colors;

	final_colors = init_color_array(WIN_W, WIN_H);
	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
			ss_average(colors, final_colors, x, y);
	}
	free_color_array(WIN_H * AA, colors);
	return (final_colors);
}
