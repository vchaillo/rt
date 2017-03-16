/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 06:29:23 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/16 01:07:22 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				key_hook_move_camera(int keycode, t_camera *camera)
{
	if (keycode == KEY_D || keycode == KEY_D_MAC)
		camera->pos = vector_add(camera->pos, camera->dir_left);
	else if (keycode == KEY_Q || keycode == KEY_A_MAC)
		camera->pos = vector_sub(camera->pos, camera->dir_left);
	else if (keycode == KEY_SPACE || keycode == KEY_SPACE_MAC)
		camera->pos = vector_add(camera->pos, camera->dir_up);
	else if (keycode == KEY_CONTROL || keycode == KEY_CONTROL_MAC)
		camera->pos = vector_sub(camera->pos, camera->dir_up);
	else if (keycode == KEY_Z || keycode == KEY_W_MAC)
		camera->pos = vector_add(camera->pos, camera->dir);
	else if (keycode == KEY_S || keycode == KEY_S_MAC)
		camera->pos = vector_sub(camera->pos, camera->dir);
	return (0);
}

int				key_hook_rot_x_camera(int keycode, t_camera *camera)
{
	if (keycode == KEY_UP || keycode == KEY_UP_MAC)
	{
		camera->rot.x += 10;
		camera->dir = vector_rot_axis(camera->dir, camera->dir_left, 10);
		camera->dir_up = vector_rot_axis(camera->dir_up, camera->dir_left, 10);
	}
	else if (keycode == KEY_DOWN || keycode == KEY_DOWN_MAC)
	{
		camera->rot.x -= 10;
		camera->dir = vector_rot_axis(camera->dir, camera->dir_left, -10);
		camera->dir_up = vector_rot_axis(camera->dir_up, camera->dir_left, -10);
	}
	return (0);
}

int				key_hook_rot_y_camera(int keycode, t_camera *camera)
{
	if (keycode == KEY_LEFT || keycode == KEY_LEFT_MAC)
	{
		camera->rot.y += 10;
		camera->dir = vector_rot_axis(camera->dir, camera->dir_up, 10);
		camera->dir_left = vector_rot_axis(camera->dir_left, camera->dir_up, 10);
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_RIGHT_MAC)
	{
		camera->rot.y -= 10;
		camera->dir = vector_rot_axis(camera->dir, camera->dir_up, -10);
		camera->dir_left = vector_rot_axis(camera->dir_left, camera->dir_up, -10);
	}
	return (0);
}

int				key_hook_rot_z_camera(int keycode, t_camera *camera)
{
	if (keycode == KEY_A || keycode == KEY_Q_MAC)
	{
		camera->rot.z += 10;
		camera->dir_left = vector_rot_axis(camera->dir_left, camera->dir, -10);
		camera->dir_up = vector_rot_axis(camera->dir_up, camera->dir, -10);
	}
	else if (keycode == KEY_E || keycode == KEY_E_MAC)
	{
		camera->rot.z -= 10;
		camera->dir_left = vector_rot_axis(camera->dir_left, camera->dir, 10);
		camera->dir_up = vector_rot_axis(camera->dir_up, camera->dir, 10);
	}
	return (0);
}

int				key_hook_camera(int keycode, t_camera *camera)
{
	key_hook_move_camera(keycode, camera);
	key_hook_rot_x_camera(keycode, camera);
	key_hook_rot_y_camera(keycode, camera);
	key_hook_rot_z_camera(keycode, camera);
	return (0);
}
