/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_camera.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:26 by vchaillo          #+#    #+#             */
/*   Updated: 2017/01/18 16:54:08 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_camera		*new_camera(float x, float y, float z)
{
	t_camera	*camera;

	if (!(camera = (t_camera*)malloc(sizeof(t_camera))))
		print_error(MALLOC_ERROR);
	camera->pos = new_vector(x, y, z);
	camera->rot = new_vector(0, 0, 0);
	camera->dir = new_vector(0, 0, -1);
	camera->ratio = RATIO;
	camera->fov = FOV;
	camera->focale = FOCALE;
	return (camera);
}

void			delete_camera(t_camera *camera)
{
	free(camera);
}
