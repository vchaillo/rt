/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 22:26:30 by valentin          #+#    #+#             */
/*   Updated: 2017/03/17 05:41:22 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				key_hook_plane(int keycode, t_plane *plane)
{
	if (keycode == KEY_UP || keycode == KEY_UP_MAC)
		plane->normal = vector_rot_x(plane->normal, -OBJ_ROT);
	else if (keycode == KEY_DOWN || keycode == KEY_DOWN_MAC)
		plane->normal = vector_rot_x(plane->normal, OBJ_ROT);
	else if (keycode == KEY_LEFT || keycode == KEY_LEFT_MAC)
		plane->normal = vector_rot_y(plane->normal, OBJ_ROT);
	else if (keycode == KEY_RIGHT || keycode == KEY_RIGHT_MAC)
		plane->normal = vector_rot_y(plane->normal, -OBJ_ROT);
	else if (keycode == KEY_A || keycode == KEY_Q_MAC)
		plane->normal = vector_rot_z(plane->normal, OBJ_ROT);
	else if (keycode == KEY_E || keycode == KEY_E_MAC)
		plane->normal = vector_rot_z(plane->normal, -OBJ_ROT);
	else if (keycode == KEY_PLUS || keycode == KEY_PLUS_MAC)
		plane->offset -= OBJ_PROP;
	else if (keycode == KEY_MINUS || keycode == KEY_MINUS_MAC)
		plane->offset += OBJ_PROP;
	return (0);
}

int				key_hook_sphere(int keycode, t_sphere *sphere)
{
	if (keycode == KEY_D || keycode == KEY_D_MAC)
		sphere->pos.x += OBJ_SPEED;
	else if (keycode == KEY_Q || keycode == KEY_A_MAC)
		sphere->pos.x -= OBJ_SPEED;
	else if (keycode == KEY_SPACE || keycode == KEY_SPACE_MAC)
		sphere->pos.y += OBJ_SPEED;
	else if (keycode == KEY_CONTROL || keycode == KEY_CONTROL_MAC)
		sphere->pos.y -= OBJ_SPEED;
	else if (keycode == KEY_S || keycode == KEY_S_MAC)
		sphere->pos.z += OBJ_SPEED;
	else if (keycode == KEY_Z || keycode == KEY_W_MAC)
		sphere->pos.z -= OBJ_SPEED;
	else if (keycode == KEY_PLUS || keycode == KEY_PLUS_MAC)
		sphere->r += OBJ_PROP;
	else if (keycode == KEY_MINUS || keycode == KEY_MINUS_MAC)
		sphere->r -= OBJ_PROP;
	return (0);
}

int				key_hook_objects(int keycode, t_scene *scene)
{
	if (scene->selected_object)
	{
		if (scene->selected_object->type == SPHERE)
			key_hook_sphere(keycode, scene->selected_object->object);
		else if (scene->selected_object->type == PLANE)
			key_hook_plane(keycode, scene->selected_object->object);
		else if (scene->selected_object->type == CYLINDER)
			key_hook_cylinder(keycode, scene->selected_object->object);
		else if (scene->selected_object->type == CONE)
			key_hook_cone(keycode, scene->selected_object->object);
		else if (scene->selected_object->type == BOX)
			key_hook_box(keycode, scene->selected_object->object);
		else if (scene->selected_object->type == DISC)
			key_hook_disc(keycode, scene->selected_object->object);
	}
	return (0);
}
