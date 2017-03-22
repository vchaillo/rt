/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_camera.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:26 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/22 21:56:03 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_camera		*new_camera(t_vector pos, t_vector look_at)
{
	t_camera	*cam;
	float		angle;
	t_vector	dir;

	if (!(cam = (t_camera*)malloc(sizeof(t_camera))))
		print_error(MALLOC_ERROR);
	cam->pos = pos;
	cam->dir = new_vector(0, 0, -1);
	cam->dir_right = new_vector(1, 0, 0);
	cam->dir_up = new_vector(0, 1, 0);
	dir = normalize(vector_sub(look_at, cam->pos));
	angle = acosf(dot_product(new_vector(dir.x, 0, dir.z), cam->dir));
	angle = dir.x > 0 ? -angle : angle;
	cam->dir = vector_rot_y(cam->dir, angle * 180 / M_PI);
	cam->dir_right = vector_rot_y(cam->dir_right, angle * 180 / M_PI);
	cam->dir_up = vector_rot_y(cam->dir_up, angle * 180 / M_PI);
	angle = acosf(dot_product(cam->dir, dir)) * 180 / M_PI;
	angle = dir.y < 0 ? -angle : angle;
	cam->dir = vector_rot_axis(cam->dir, cam->dir_right, angle);
	cam->dir_up = vector_rot_axis(cam->dir_up, cam->dir_right, angle);
	cam->dir_right = vector_rot_axis(cam->dir_right, cam->dir_right, angle);
	// printf("dir(%f, %f, %f)\n", cam->dir.x, cam->dir.y, cam->dir.z);
	// printf("dir_up(%f, %f, %f)\n", cam->dir_up.x, cam->dir_up.y, cam->dir_up.z);
	// printf("dir_right(%f, %f, %f)\n\n", cam->dir_right.x, cam->dir_right.y, cam->dir_right.z);
	return (cam);
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
