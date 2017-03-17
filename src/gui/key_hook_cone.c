/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_cone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:40:03 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/17 05:40:17 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				key_hook_cone_rotation(int keycode, t_cone *cone)
{
	if (keycode == KEY_UP || keycode == KEY_UP_MAC)
		cone->axis = vector_rot_x(cone->axis, -OBJ_ROT);
	else if (keycode == KEY_DOWN || keycode == KEY_DOWN_MAC)
		cone->axis = vector_rot_x(cone->axis, OBJ_ROT);
	else if (keycode == KEY_LEFT || keycode == KEY_LEFT_MAC)
		cone->axis = vector_rot_y(cone->axis, OBJ_ROT);
	else if (keycode == KEY_RIGHT || keycode == KEY_RIGHT_MAC)
		cone->axis = vector_rot_y(cone->axis, -OBJ_ROT);
	else if (keycode == KEY_A || keycode == KEY_Q_MAC)
		cone->axis = vector_rot_z(cone->axis, OBJ_ROT);
	else if (keycode == KEY_E || keycode == KEY_E_MAC)
		cone->axis = vector_rot_z(cone->axis, -OBJ_ROT);
	return (0);
}

int				key_hook_cone(int keycode, t_cone *cone)
{
	if (keycode == KEY_D || keycode == KEY_D_MAC)
		cone->apex.x += OBJ_SPEED;
	else if (keycode == KEY_Q || keycode == KEY_A_MAC)
		cone->apex.x -= OBJ_SPEED;
	else if (keycode == KEY_SPACE || keycode == KEY_SPACE_MAC)
		cone->apex.y += OBJ_SPEED;
	else if (keycode == KEY_CONTROL || keycode == KEY_CONTROL_MAC)
		cone->apex.y -= OBJ_SPEED;
	else if (keycode == KEY_S || keycode == KEY_S_MAC)
		cone->apex.z += OBJ_SPEED;
	else if (keycode == KEY_Z || keycode == KEY_W_MAC)
		cone->apex.z -= OBJ_SPEED;
	else if (keycode == KEY_PLUS || keycode == KEY_PLUS_MAC)
		cone->angle += OBJ_EXPAND;
	else if (keycode == KEY_MINUS || keycode == KEY_MINUS_MAC)
		cone->angle -= OBJ_EXPAND;
	else
		key_hook_cone_rotation(keycode, cone);
	return (0);
}
