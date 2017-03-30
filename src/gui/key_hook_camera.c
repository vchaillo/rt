/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 06:29:23 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/24 08:46:43 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int				key_hook_move_camera(int keycode, t_camera *camera)
{
	if (keycode == KEY_D || keycode == KEY_D_MAC)
		camera->pos = vector_add(camera->pos, vector_scalar(CAM_SPEED,
		camera->dir_right));
	else if (keycode == KEY_Q || keycode == KEY_A_MAC)
		camera->pos = vector_sub(camera->pos, vector_scalar(CAM_SPEED,
		camera->dir_right));
	else if (keycode == KEY_SPACE || keycode == KEY_SPACE_MAC)
		camera->pos = vector_add(camera->pos, vector_scalar(CAM_SPEED,
		camera->dir_up));
	else if (keycode == KEY_CONTROL || keycode == KEY_CONTROL_MAC)
		camera->pos = vector_sub(camera->pos, vector_scalar(CAM_SPEED,
		camera->dir_up));
	else if (keycode == KEY_Z || keycode == KEY_W_MAC)
		camera->pos = vector_add(camera->pos, vector_scalar(CAM_SPEED,
		camera->dir));
	else if (keycode == KEY_S || keycode == KEY_S_MAC)
		camera->pos = vector_sub(camera->pos, vector_scalar(CAM_SPEED,
			camera->dir));
	return (0);
}

static int				key_hook_rot_x_camera(int keycode, t_camera *camera)
{
	if (keycode == KEY_UP || keycode == KEY_UP_MAC)
	{
		camera->dir = vector_rot_axis(camera->dir, camera->dir_right, CAM_ROT);
		camera->dir_up = vector_rot_axis(camera->dir_up, camera->dir_right,
			CAM_ROT);
	}
	else if (keycode == KEY_DOWN || keycode == KEY_DOWN_MAC)
	{
		camera->dir = vector_rot_axis(camera->dir, camera->dir_right, -CAM_ROT);
		camera->dir_up = vector_rot_axis(camera->dir_up, camera->dir_right,
			-CAM_ROT);
	}
	return (0);
}

static int				key_hook_rot_y_camera(int keycode, t_camera *camera)
{
	if (keycode == KEY_LEFT || keycode == KEY_LEFT_MAC)
	{
		camera->dir = vector_rot_axis(camera->dir, camera->dir_up, CAM_ROT);
		camera->dir_right = vector_rot_axis(camera->dir_right, camera->dir_up,
			CAM_ROT);
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_RIGHT_MAC)
	{
		camera->dir = vector_rot_axis(camera->dir, camera->dir_up, -CAM_ROT);
		camera->dir_right = vector_rot_axis(camera->dir_right, camera->dir_up,
			-CAM_ROT);
	}
	return (0);
}

static int				key_hook_rot_z_camera(int keycode, t_camera *camera)
{
	if (keycode == KEY_A || keycode == KEY_Q_MAC)
	{
		camera->dir_right = vector_rot_axis(camera->dir_right, camera->dir,
			-CAM_ROT);
		camera->dir_up = vector_rot_axis(camera->dir_up, camera->dir,
			-CAM_ROT);
	}
	else if (keycode == KEY_E || keycode == KEY_E_MAC)
	{
		camera->dir_right = vector_rot_axis(camera->dir_right, camera->dir,
			CAM_ROT);
		camera->dir_up = vector_rot_axis(camera->dir_up, camera->dir,
			CAM_ROT);
	}
	return (0);
}

int						key_hook_camera(int keycode, t_camera *camera)
{
	key_hook_move_camera(keycode, camera);
	key_hook_rot_x_camera(keycode, camera);
	key_hook_rot_y_camera(keycode, camera);
	key_hook_rot_z_camera(keycode, camera);
	return (0);
}
