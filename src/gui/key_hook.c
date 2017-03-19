/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 03:48:41 by valentin          #+#    #+#             */
/*   Updated: 2017/03/19 15:58:50 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int			check_if_update_image(int k)
{
	if (k == KEY_UP || k == KEY_DOWN || k == KEY_LEFT || k == KEY_RIGHT
		|| k == KEY_PLUS || k == KEY_MINUS || k == KEY_Z || k == KEY_Q
		|| k == KEY_S || k == KEY_D || k == KEY_A || k == KEY_E || k == KEY_N
		|| k == KEY_P || k == KEY_SPACE || k == KEY_CONTROL	|| k == KEY_R
		|| k == KEY_X || k == KEY_KP0 || k == KEY_KP1 || k == KEY_KP2
		|| k == KEY_M || k == KEY_KP3 || k == KEY_KP4 || k == KEY_KP5
		|| k == KEY_UP_MAC || k == KEY_DOWN_MAC || k == KEY_LEFT_MAC
		|| k == KEY_RIGHT_MAC || k == KEY_PLUS_MAC || k == KEY_MINUS_MAC
		|| k == KEY_W_MAC || k == KEY_M_MAC || k == KEY_A_MAC || k == KEY_S_MAC
		|| k == KEY_D_MAC || k == KEY_Q_MAC || k == KEY_E_MAC || k == KEY_N_MAC
		|| k == KEY_P_MAC || k == KEY_SPACE_MAC || k == KEY_CONTROL_MAC
		|| k == KEY_R_MAC || k == KEY_X_MAC || k == KEY_KP0_MAC
		|| k == KEY_KP1_MAC || k == KEY_KP2_MAC	|| k == KEY_KP3_MAC
		|| k == KEY_KP4_MAC || k == KEY_KP5_MAC || k == KEY_NUM0_MAC
		|| k == KEY_NUM1_MAC || k == KEY_NUM2_MAC || k == KEY_NUM3_MAC
		|| k == KEY_NUM4_MAC || k == KEY_NUM5_MAC)
		return (TRUE);
	return (FALSE);
}

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
		e->scene->color_array_aa = reset_color_array(e->scene->aa, e->scene->color_array_aa);
	}
	else if (keycode == KEY_X || keycode == KEY_X_MAC)
	{
		e->scene->effect++;
		if (e->scene->effect == 6)
			e->scene->effect = 0;
		else if (e->scene->effect == CARTOON)
			e->scene->amb_intensity *= 5;
		else if (e->scene->effect == CARTOON + 1)
			e->scene->amb_intensity /= 5;
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
	else if (keycode == KEY_DELETE || keycode == KEY_DELETE_MAC)
		export_scene(e);
	else
	{
		if (check_if_update_image(keycode) == TRUE)
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
	}
	return (0);
}
