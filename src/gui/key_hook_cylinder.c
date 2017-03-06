/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:40:03 by vchaillo          #+#    #+#             */
/*   Updated: 2017/01/19 03:46:31 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				key_hook_cylinder_rotation(int keycode, t_cylinder *cylinder)
{
	if (keycode == UP || keycode == UP_MAC)
		cylinder->axis = vector_rot_x(cylinder->axis, -10);
	else if (keycode == DOWN || keycode == DOWN_MAC)
		cylinder->axis = vector_rot_x(cylinder->axis, 10);
	else if (keycode == LEFT || keycode == LEFT_MAC)
		cylinder->axis = vector_rot_y(cylinder->axis, 10);
	else if (keycode == RIGHT || keycode == RIGHT_MAC)
		cylinder->axis = vector_rot_y(cylinder->axis, -10);
	if (keycode == A || keycode == Q_MAC)
		cylinder->axis = vector_rot_z(cylinder->axis, 10);
	else if (keycode == E || keycode == E_MAC)
		cylinder->axis = vector_rot_z(cylinder->axis, -10);
	return (0);
}

int				key_hook_cylinder(int keycode, t_cylinder *cylinder)
{
	if (keycode == D || keycode == D_MAC)
		cylinder->pos.x += 1;
	else if (keycode == Q || keycode == A_MAC)
		cylinder->pos.x -= 1;
	else if (keycode == SPACE || keycode == SPACE_MAC)
		cylinder->pos.y += 1;
	else if (keycode == CONTROL || keycode == CONTROL_MAC)
		cylinder->pos.y -= 1;
	else if (keycode == S || keycode == S_MAC)
		cylinder->pos.z += 1;
	else if (keycode == Z || keycode == W_MAC)
		cylinder->pos.z -= 1;
	else if (keycode == PLUS || keycode == PLUS_MAC)
		cylinder->r += 1;
	else if (keycode == MINUS || keycode == MINUS_MAC)
		cylinder->r -= 1;
	else
		key_hook_cylinder_rotation(keycode, cylinder);
	return (0);
}
