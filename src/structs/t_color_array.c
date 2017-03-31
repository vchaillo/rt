/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_color_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 01:17:40 by valentin          #+#    #+#             */
/*   Updated: 2017/03/31 02:23:19 by valentin         ###   ########.fr       */
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
	int			i;

	i = 0;
	while (i < hmax)
	{
		free(colors[i]);
		i++;
	}
	free(colors);
}

t_color			**reset_color_array(int aa, t_color **colors)
{
	int			old_aa;

	old_aa = aa == ACTIVE_AA ? INACTIVE_AA : ACTIVE_AA;
	delete_color_array(old_aa * WIN_H, colors);
	return (new_color_array(WIN_W * aa, WIN_W * aa));
}
