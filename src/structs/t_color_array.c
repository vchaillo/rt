/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_color_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 01:17:40 by valentin          #+#    #+#             */
/*   Updated: 2017/03/10 01:39:58 by valentinchaillou89###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color			**new_color_array(int wmax, int hmax)
{
	int			y;
	t_color		**colors;

	if (!(colors = malloc(sizeof(t_color*) * hmax)))
	{
		print_error(MALLOC_ERROR);
		exit(0);
	}
	y = -1;
	while (++y < hmax)
	{
		if (!(colors[y] = malloc(sizeof(t_color) * wmax)))
		{
			delete_color_array(y, colors);
			print_error(MALLOC_ERROR);
			exit(0);
		}
	}
	return (colors);
}

void			delete_color_array(int hmax, t_color **colors)
{
	while (--hmax)
		free(colors[hmax]);
	free(colors);
}

t_color			**reset_color_array(int wmax, int hmax, t_color **colors)
{
	(void)colors;
	// delete_color_array(wmax, colors);
	return (new_color_array(wmax, hmax));
}
