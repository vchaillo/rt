/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:59:39 by hbock             #+#    #+#             */
/*   Updated: 2017/03/08 16:59:40 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		free_color_array(int hmax, t_color **colors)
{
	while (--hmax)
		free(colors[hmax]);
	free(colors);
}

t_color		**init_color_array(int wmax, int hmax)
{
	int		y;
	t_color	**colors;

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
			free_color_array(y, colors);
			print_error(MALLOC_ERROR);
			exit(0);
		}
	}
	return (colors);
}
