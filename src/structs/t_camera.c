/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_camera.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:26 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/21 04:52:17 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// t_camera		*new_camera(t_vector pos, t_vector look_at)
// {
// 	t_camera	*camera;
// 	float		angle;
// 	float		dot;
//
// 	if (!(camera = (t_camera *)malloc(sizeof(t_camera))))
// 		print_error(MALLOC_ERROR);
// 	camera->pos = pos;
// 	camera->dir = new_vector(0, 0, -1);
// 	camera->dir_right = new_vector(1, 0, 0);
// 	camera->dir_up = new_vector(0, 1, 0);
// 	look_at = normalize(look_at);
// 	dot = dot_product(new_vector(look_at.x, 0, look_at.z), camera->dir);
// 	angle = acosl(dot) * 180 / M_PI;
// 	angle = look_at.x > 0 ? -angle : angle;
// 	camera->dir = vector_rot_y(camera->dir, angle);
// 	camera->dir_right = vector_rot_y(camera->dir_right, angle);
// 	camera->dir_up = vector_rot_y(camera->dir_up, angle);
// 	dot = dot_product(camera->dir, look_at);
// 	angle = acosl(dot) * 180 / M_PI;
// 	angle = look_at.y < 0 ? -angle : angle;
// 	camera->dir = vector_rot_axis(camera->dir, camera->dir_right, angle);
// 	camera->dir_up = vector_rot_axis(camera->dir_up, camera->dir_right, angle);
// 	camera->dir_right = vector_rot_axis(camera->dir_right, camera->dir_right,
// 		angle);
// 	return (camera);
// }

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
	printf("dir : (%f, %f, %f)\n", dir.x, dir.y, dir.z);
	angle = acosl(dot_product(new_vector(dir.x, 0, dir.z), cam->dir));
	angle = dir.x > 0 ? -angle : angle;
	cam->dir = vector_rot_y(cam->dir, angle * 180 / M_PI);
	cam->dir_right = vector_rot_y(cam->dir_right, angle * 180 / M_PI);
	cam->dir_up = vector_rot_y(cam->dir_up, angle * 180 / M_PI);
	angle = acosl(dot_product(cam->dir, dir)) * 180 / M_PI;
	angle = dir.y < 0 ? -angle : angle;
	cam->dir = vector_rot_axis(cam->dir, cam->dir_right, angle);
	cam->dir_up = vector_rot_axis(cam->dir_up, cam->dir_right, angle);
	cam->dir_right = vector_rot_axis(cam->dir_right, cam->dir_right, angle);
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
