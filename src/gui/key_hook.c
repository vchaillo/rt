/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 03:48:41 by valentin          #+#    #+#             */
/*   Updated: 2017/03/14 06:30:08 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				key_hook_light(int key, t_scene *scene)
{
	if (key == KEY_KP1 || key == KEY_KP1_MAC || key == KEY_NUM1_MAC)
		scene->amb = (scene->amb == ACTIVE) ? INACTIVE : ACTIVE;
	else if (key == KEY_KP2 || key == KEY_KP2_MAC || key == KEY_NUM2_MAC)
		scene->diffuse = (scene->diffuse == ACTIVE) ? INACTIVE : ACTIVE;
	else if (key == KEY_KP3 || key == KEY_KP3_MAC || key == KEY_NUM3_MAC)
		scene->specular = (scene->specular == ACTIVE) ? INACTIVE : ACTIVE;
	else if (key == KEY_KP4 || key == KEY_KP4_MAC || key == KEY_NUM4_MAC)
		scene->spot = (scene->spot == ACTIVE) ? INACTIVE : ACTIVE;
	else if (key == KEY_KP5 || key == KEY_KP5_MAC || key == KEY_NUM5_MAC)
		scene->dir = (scene->dir == ACTIVE) ? INACTIVE : ACTIVE;
	return (0);
}

int				key_hook_scene(int keycode, t_env *e)
{
	if (keycode == KEY_M || keycode == KEY_M_MAC)
	{
		e->scene->mode = e->scene->mode == EDIT_MODE ? MOVE_MODE : EDIT_MODE;
		e->scene->selected_object = NULL;
	}
	if (keycode == KEY_R || keycode == KEY_R_MAC)
		load_scene(e->scene_type, e);
	else if (keycode == KEY_P || keycode == KEY_P_MAC)
		switch_scene(KEY_LEFT, e);
	else if (keycode == KEY_N || keycode == KEY_N_MAC)
		switch_scene(KEY_RIGHT, e);
	return (0);
}

void			key_hook_effects(int keycode, t_env *e)
{
	if (keycode == KEY_KP0 || keycode == KEY_KP0_MAC || keycode == KEY_NUM0_MAC)
	{
		e->scene->aa = e->scene->aa == INACTIVE_AA ? ACTIVE_AA : INACTIVE_AA;
		e->color_array_aa = reset_color_array(e->scene->aa, e->color_array_aa);
	}
	else if (keycode == KEY_X || keycode == KEY_X_MAC)
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
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESCAPE || keycode == KEY_ESCAPE_MAC)
	{
		if (e->scene)
			delete_scene(e->scene);
		exit(0);
	}
	if (keycode == KEY_RETURN || keycode == KEY_RETURN_MAC)
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
