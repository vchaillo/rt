/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_cone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:40:03 by vchaillo          #+#    #+#             */
/*   Updated: 2017/01/19 03:42:39 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				key_hook_cone_rotation(int keycode, t_cone *cone)
{
	if (keycode == UP || keycode == UP_MAC)
		cone->axis = vector_rot_x(cone->axis, -10);
	else if (keycode == DOWN || keycode == DOWN_MAC)
		cone->axis = vector_rot_x(cone->axis, 10);
	else if (keycode == LEFT || keycode == LEFT_MAC)
		cone->axis = vector_rot_y(cone->axis, 10);
	else if (keycode == RIGHT || keycode == RIGHT_MAC)
		cone->axis = vector_rot_y(cone->axis, -10);
	else if (keycode == A || keycode == Q_MAC)
		cone->axis = vector_rot_z(cone->axis, 10);
	else if (keycode == E || keycode == E_MAC)
		cone->axis = vector_rot_z(cone->axis, -10);
	return (0);
}

int				key_hook_cone(int keycode, t_cone *cone)
{
	if (keycode == D || keycode == D_MAC)
		cone->apex.x += 1;
	else if (keycode == Q || keycode == A_MAC)
		cone->apex.x -= 1;
	else if (keycode == SPACE || keycode == SPACE_MAC)
		cone->apex.y += 1;
	else if (keycode == CONTROL || keycode == CONTROL_MAC)
		cone->apex.y -= 1;
	else if (keycode == S || keycode == S_MAC)
		cone->apex.z += 1;
	else if (keycode == Z || keycode == W_MAC)
		cone->apex.z -= 1;
	else if (keycode == PLUS || keycode == PLUS_MAC)
		cone->angle += 1;
	else if (keycode == MINUS || keycode == MINUS_MAC)
		cone->angle -= 1;
	else
		key_hook_cone_rotation(keycode, cone);
	return (0);
}
