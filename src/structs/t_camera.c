/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_camera.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:26 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/20 01:22:47 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_camera		*new_camera(t_vector pos, t_vector dir)
{
	t_camera	*camera;

	if (!(camera = (t_camera*)malloc(sizeof(t_camera))))
		print_error(MALLOC_ERROR);
	camera->pos = pos;
	camera->dir = normalize(dir);
	camera->dir_right = vector_rot_y(dir, -90);
	camera->dir_up = vector_rot_axis(dir, camera->dir_right, 90);
	// camera->dir_up = vector_rot_x(dir, 90);
	return (camera);
}

void			delete_camera(t_camera *camera)
{
	free(camera);
}

void			get_viewplane_pos(t_camera *camera)
{
	camera->viewplane_pos = vector_add(
		vector_add(
			camera->pos,
			vector_scalar(FOCALE, camera->dir)),
		vector_sub(
			vector_scalar(FOV / 2.0, camera->dir_up),
			vector_scalar(RATIO * FOV / 2.0, camera->dir_right)));
}
