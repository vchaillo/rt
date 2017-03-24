/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_refraction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <hbock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:58:39 by hbock             #+#    #+#             */
/*   Updated: 2017/03/24 04:05:27 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		gamma_correction(t_color *color)
{
	float	inv_gamma;

	inv_gamma = INV_GAMMA;
	color->r = 255 * powf(color->r / 255, inv_gamma);
	color->g = 255 * powf(color->g / 255, inv_gamma);
	color->b = 255 * powf(color->b / 255, inv_gamma);
}

void		manual_expose(t_color **color_array)
{
	float	exposure;
	int		x;
	int		y;

	exposure = EXPOSURE;
	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			color_array[y][x].r = (1 - expf(color_array[y][x].r
											/ 255 * exposure)) * 255;
			color_array[y][x].g = (1 - expf(color_array[y][x].g
											/ 255 * exposure)) * 255;
			color_array[y][x].b = (1 - expf(color_array[y][x].b
											/ 255 * exposure)) * 255;
			if (DO_GAMMA)
				gamma_correction(&(color_array[y][x]));
		}
	}
}

/*
*** Need to implement a UI to manualy manage exposure and gamma
*/

static void	get_max_exposure(float *pmax, t_color **color_array)
{
	float	max;
	int		x;
	int		y;

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
	*pmax = max;
}

void		exposure(t_color **color_array)
{
	float	max;
	int		x;
	int		y;
	float	exposure_coef;

	if (EXPOSE_TYPE == 1)
		manual_expose(color_array);
	else if (EXPOSE_TYPE == 2)
	{
		get_max_exposure(&max, color_array);
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
}
