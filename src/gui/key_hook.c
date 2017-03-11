/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 03:48:41 by valentin          #+#    #+#             */
/*   Updated: 2017/03/11 04:02:09 by valentinchaillou89###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				key_hook_camera(int keycode, t_camera *camera)
{
	if (keycode == D || keycode == D_MAC)
		camera->pos.x += 1;
	else if (keycode == Q || keycode == A_MAC)
		camera->pos.x -= 1;
	else if (keycode == SPACE || keycode == SPACE_MAC)
		camera->pos.y += 1;
	else if (keycode == CONTROL || keycode == CONTROL_MAC)
		camera->pos.y -= 1;
	else if (keycode == S || keycode == S_MAC)
		camera->pos.z += 1;
	else if (keycode == Z || keycode == W_MAC)
		camera->pos.z -= 1;
	else if (keycode == UP || keycode == UP_MAC)
		camera->rot.x += 10;
	else if (keycode == DOWN || keycode == DOWN_MAC)
		camera->rot.x -= 10;
	else if (keycode == LEFT || keycode == LEFT_MAC)
		camera->rot.y += 10;
	else if (keycode == RIGHT || keycode == RIGHT_MAC)
		camera->rot.y -= 10;
	else if (keycode == A || keycode == Q_MAC)
		camera->rot.z += 10;
	else if (keycode == E || keycode == E_MAC)
		camera->rot.z -= 10;
	return (0);
}

int				key_hook_light(int keycode, t_scene *scene)
{
	if (keycode == KP1 || keycode == KP1_MAC || keycode == NUM1_MAC)
		scene->amb = (scene->amb == ACTIVE) ? INACTIVE : ACTIVE;
	else if (keycode == KP2 || keycode == KP2_MAC || keycode == NUM2_MAC)
		scene->diffuse = (scene->diffuse == ACTIVE) ? INACTIVE : ACTIVE;
	else if (keycode == KP3 || keycode == KP3_MAC || keycode == NUM3_MAC)
		scene->specular = (scene->specular == ACTIVE) ? INACTIVE : ACTIVE;
	else if (keycode == KP4 || keycode == KP4_MAC || keycode == NUM4_MAC)
		scene->spot = (scene->spot == ACTIVE) ? INACTIVE : ACTIVE;
	else if (keycode == KP5 || keycode == KP5_MAC || keycode == NUM5_MAC)
		scene->dir = (scene->dir == ACTIVE) ? INACTIVE : ACTIVE;
	return (0);
}

int				key_hook_scene(int keycode, t_env *e)
{
	if (keycode == M || keycode == M_MAC)
	{
		e->scene->mode = e->scene->mode == EDIT_MODE ? MOVE_MODE : EDIT_MODE;
		e->scene->selected_object = NULL;
	}
	if (keycode == R || keycode == R_MAC)
		load_scene(e->scene_type, e);
	else if (keycode == P || keycode == P_MAC)
		switch_scene(LEFT, e);
	else if (keycode == N || keycode == N_MAC)
		switch_scene(RIGHT, e);
	return (0);
}

int				key_hook_effects(int keycode, t_env *e)
{
	if (keycode == KP0 || keycode == KP0_MAC || keycode == NUM0_MAC)
	{
		e->scene->aa = e->scene->aa == INACTIVE_AA ? ACTIVE_AA : INACTIVE_AA;
		e->color_array_aa = reset_color_array(WIN_W * e->scene->aa,
			WIN_H * e->scene->aa, e->color_array_aa);
	}
	else if (keycode == X || keycode == X_MAC)
	{
		if (e->scene->effect == INACTIVE)
			e->scene->effect = SEPIA;
		else if (e->scene->effect == SEPIA)
			e->scene->effect = GRAYSCALE;
		else if (e->scene->effect == GRAYSCALE)
			e->scene->effect = NEGATIVE;
		else if (e->scene->effect == NEGATIVE)
		{
			e->scene->effect = CARTOON;
			e->scene->amb_intensity *= 5;
		}
		else
		{
			e->scene->effect = INACTIVE;
			e->scene->amb_intensity /= 5;
		}
	}
	return (0);
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == ESCAPE || keycode == ESCAPE_MAC)
	{
		if (e->scene)
			delete_scene(e->scene);
		exit(0);
	}
	if (keycode == RETURN || keycode == RETURN_MAC)
		export_image(e);
	else
	{
		if (e->scene->mode == MOVE_MODE)
			key_hook_camera(keycode, e->scene->camera);
		else
			key_hook_objects(keycode, e->scene);
		key_hook_light(keycode, e->scene);
		key_hook_scene(keycode, e);
		key_hook_effects(keycode, e);
		print_keyhook(keycode, e);
		update_image(e);
	}
	return (0);
}
