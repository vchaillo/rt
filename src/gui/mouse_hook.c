/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 03:48:37 by valentin          #+#    #+#             */
/*   Updated: 2017/03/14 03:07:15 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			select_object(int x, int y, t_env *e)
{
	t_ray		ray;

	ray.o = e->scene->camera->pos;
	ray.d = get_camray_dir(e->scene->camera, x, y, e->scene->aa);
	ray.t = get_ray_intersection(e->scene->objects, &ray);
	if (ray.hitpoint.object)
	{
		e->scene->selected_object = ray.hitpoint.object;
		e->scene->mode = EDIT_MODE;
	}
	else
	{
		e->scene->selected_object = NULL;
		e->scene->mode = MOVE_MODE;
	}
}

int				mouse_hook(int button, int x, int y, t_env *e)
{
	print_mousehook(button, x, y, e);
	if (button == 1 && y >= 0)
	{
		select_object(x, y, e);
		update_image(e);
	}
	return (0);
}
