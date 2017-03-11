/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_refraction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <hbock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:58:39 by hbock             #+#    #+#             */
/*   Updated: 2017/03/09 23:13:38 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		exposure(t_color **color_array)
{
	float	max;
	int		x;
	int		y;
	float	exposure_coef;

	max = -1;
	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			max = (color_array[y][x].r > max) ? color_array[y][x].r : max;
			max = (color_array[y][x].g > max) ? color_array[y][x].g : max;
			max = (color_array[y][x].b > max) ? color_array[y][x].b : max;
		}
	}
	if (max < 255)
		return ;
	exposure_coef = 254 / max;
	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			color_array[y][x].r *= exposure_coef;
			color_array[y][x].g *= exposure_coef;
			color_array[y][x].b *= exposure_coef;
		}
	}
}
