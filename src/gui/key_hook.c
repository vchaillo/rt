/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 03:48:41 by valentin          #+#    #+#             */
/*   Updated: 2017/03/07 22:27:27 by valentin         ###   ########.fr       */
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
	if (keycode == X || keycode == X_MAC)
	{
		if (!e->scene->sepia && !e->scene->grayscale && !e->scene->cartoon)
			e->scene->sepia = ACTIVE;
		else if (e->scene->sepia == ACTIVE)
		{
			e->scene->sepia = INACTIVE;
			e->scene->grayscale = ACTIVE;
		}
		else if (e->scene->grayscale == ACTIVE)
		{
			e->scene->grayscale = INACTIVE;
			e->scene->cartoon = ACTIVE;
			e->scene->cartoon = ACTIVE;
			e->scene->amb_intensity *= 5;
		}
		else
		{
			e->scene->cartoon = INACTIVE;
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
