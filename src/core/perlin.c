/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:38:44 by valentin          #+#    #+#             */
/*   Updated: 2017/03/24 06:59:31 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float			gradient(int i, int j)
{
	float		unit;
	float		grad[8][2];

	unit = 1.0 / sqrt(2);
	grad[0][0] = unit;
	grad[0][1] = unit;
	grad[1][0] = -unit;
	grad[1][1] = unit;
	grad[2][0] = unit;
	grad[2][1] = -unit;
	grad[3][0] = -unit;
	grad[3][1] = -unit;
	grad[4][0] = 1;
	grad[4][1] = 0;
	grad[5][0] = -1;
	grad[5][1] = 0;
	grad[6][0] = 0;
	grad[6][1] = 1;
	grad[7][0] = 0;
	grad[7][1] = -1;
	return (grad[i][j]);
}

float			fade(float nb)
{
	float		t;

	t = nb - (int)nb;
	return (t * t * t * (t * (t * 6 - 15) + 10));
}

float			noise(float x, float y, float res)
{
	int			i;
	int			j;
	int			grad[4];
	float		stuv[4];
	float		smooth[2];

	x /= res;
	y /= res;
	i = (int)x & 255;
	j = (int)y & 255;
	grad[0] = permutation(i + permutation(j)) % 8;
	grad[1] = permutation(i + 1 + permutation(j)) % 8;
	grad[2] = permutation(i + permutation(j + 1)) % 8;
	grad[3] = permutation(i + 1 + permutation(j + 1)) % 8;
	stuv[0] = gradient(grad[0], 0) * (x - (int)x)
		+ gradient(grad[0], 1) * (y - (int)y);
	stuv[1] = gradient(grad[1], 0) * (x - ((int)x + 1))
		+ gradient(grad[1], 1) * (y - (int)y);
	stuv[2] = gradient(grad[2], 0) * (x - (int)x)
		+ gradient(grad[2], 1) * (y - ((int)y + 1));
	stuv[3] = gradient(grad[3], 0) * (x - ((int)x + 1))
		+ gradient(grad[3], 1) * (y - ((int)y + 1));
	smooth[0] = stuv[0] + fade(x) * (stuv[1] - stuv[0]);
	smooth[1] = stuv[2] + fade(x) * (stuv[3] - stuv[2]);
	return (smooth[0] + fade(y) * (smooth[1] - smooth[0]));
}

float			perlin(float x, float y, int resolution)
{
	float	nb;

	nb = (noise(fabs(x * 100), fabs(y * 100),
		resolution) + 1);
	return (nb);
}
