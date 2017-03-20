/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_camera.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:26 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/20 03:45:50 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_camera		*new_camera(t_vector pos, t_vector dir)
{
	t_camera	*camera;
	t_vector	axis;
	float		angle;
	float		dot;

	if (!(camera = (t_camera*)malloc(sizeof(t_camera))))
		print_error(MALLOC_ERROR);
	camera->pos = pos;
	camera->dir = normalize(dir);
	dot = dot_product(new_vector(0, 0, -1), camera->dir);
	printf("dot = %f\n", dot);
	angle = 0;
	axis = new_vector(0, 1, 0);
	if (dot != 1 && dot != -1)
	{
		axis = cross_product(camera->dir, new_vector(0, 0, -1));
		angle = acos(dot_product(camera->dir, new_vector(0, 0, -1)));
	}
	printf("axis = %f, %f, %f\n", axis.x, axis.y, axis.z);
	printf("angle = %f\n", angle);
	camera->dir = vector_rot_axis(dir, axis, angle);
	camera->dir_right = vector_rot_axis(camera->dir, axis, -90);
	camera->dir_up = vector_rot_axis(dir, camera->dir_right, 90);
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
