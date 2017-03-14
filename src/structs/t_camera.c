/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_camera.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:26 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/14 06:46:50 by vchaillo         ###   ########.fr       */
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
	camera->dir_left = vector_rot_y(dir, -90);
	camera->dir_up = vector_rot_x(dir, 90);
	camera->rot = new_vector(0, 0, 0);
	camera->ratio = RATIO;
	camera->fov = FOV;
	camera->focale = FOCALE;
	return (camera);
}

void			delete_camera(t_camera *camera)
{
	free(camera);
}

// 
// e->view_plane_ori = vec_add(vec_add(e->eye_pos, vec_numb(e->eye_dir,
// 		VIEW_PLANE_DIST)), vec_sub(vec_numb(e->up_vec, VIEW_PLANE_HEIGHT / 2.0)
// 		, vec_numb(e->right_vec, VIEW_PLANE_WIDTH / 2.0)));
