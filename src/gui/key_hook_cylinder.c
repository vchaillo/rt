/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:40:03 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/17 05:40:26 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				key_hook_cylinder_rotation(int keycode, t_cylinder *cylinder)
{
	if (keycode == KEY_UP || keycode == KEY_UP_MAC)
		cylinder->axis = vector_rot_x(cylinder->axis, -OBJ_ROT);
	else if (keycode == KEY_DOWN || keycode == KEY_DOWN_MAC)
		cylinder->axis = vector_rot_x(cylinder->axis, OBJ_ROT);
	else if (keycode == KEY_LEFT || keycode == KEY_LEFT_MAC)
		cylinder->axis = vector_rot_y(cylinder->axis, OBJ_ROT);
	else if (keycode == KEY_RIGHT || keycode == KEY_RIGHT_MAC)
		cylinder->axis = vector_rot_y(cylinder->axis, -OBJ_ROT);
	if (keycode == KEY_A || keycode == KEY_Q_MAC)
		cylinder->axis = vector_rot_z(cylinder->axis, OBJ_ROT);
	else if (keycode == KEY_E || keycode == KEY_E_MAC)
		cylinder->axis = vector_rot_z(cylinder->axis, -OBJ_ROT);
	return (0);
}

int				key_hook_cylinder(int keycode, t_cylinder *cylinder)
{
	if (keycode == KEY_D || keycode == KEY_D_MAC)
		cylinder->pos.x += OBJ_SPEED;
	else if (keycode == KEY_Q || keycode == KEY_A_MAC)
		cylinder->pos.x -= OBJ_SPEED;
	else if (keycode == KEY_SPACE || keycode == KEY_SPACE_MAC)
		cylinder->pos.y += OBJ_SPEED;
	else if (keycode == KEY_CONTROL || keycode == KEY_CONTROL_MAC)
		cylinder->pos.y -= OBJ_SPEED;
	else if (keycode == KEY_S || keycode == KEY_S_MAC)
		cylinder->pos.z += OBJ_SPEED;
	else if (keycode == KEY_Z || keycode == KEY_W_MAC)
		cylinder->pos.z -= OBJ_SPEED;
	else if (keycode == KEY_PLUS || keycode == KEY_PLUS_MAC)
		cylinder->r += OBJ_PROP;
	else if (keycode == KEY_MINUS || keycode == KEY_MINUS_MAC)
		cylinder->r -= OBJ_PROP;
	else
		key_hook_cylinder_rotation(keycode, cylinder);
	return (0);
}
