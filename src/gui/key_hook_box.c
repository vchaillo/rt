/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:36:21 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/30 16:42:48 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int			key_hook_box_rotation(int keycode, t_box *box)
{
	if (keycode == KEY_UP || keycode == KEY_UP_MAC)
		box->rotxyz.x -= OBJ_ROT;
	else if (keycode == KEY_DOWN || keycode == KEY_DOWN_MAC)
		box->rotxyz.x += OBJ_ROT;
	else if (keycode == KEY_LEFT || keycode == KEY_LEFT_MAC)
		box->rotxyz.y += OBJ_ROT;
	else if (keycode == KEY_RIGHT || keycode == KEY_RIGHT_MAC)
		box->rotxyz.y -= OBJ_ROT;
	else if (keycode == KEY_A || keycode == KEY_Q_MAC)
		box->rotxyz.z += OBJ_ROT;
	else if (keycode == KEY_E || keycode == KEY_E_MAC)
		box->rotxyz.z -= OBJ_ROT;
	return (0);
}

int					key_hook_box(int keycode, t_box *box)
{
	if (keycode == KEY_D || keycode == KEY_D_MAC)
		box->trans.x += OBJ_SPEED;
	else if (keycode == KEY_Q || keycode == KEY_A_MAC)
		box->trans.x -= OBJ_SPEED;
	else if (keycode == KEY_SPACE || keycode == KEY_SPACE_MAC)
		box->trans.y += OBJ_SPEED;
	else if (keycode == KEY_CONTROL || keycode == KEY_CONTROL_MAC)
		box->trans.y -= OBJ_SPEED;
	else if (keycode == KEY_S || keycode == KEY_S_MAC)
		box->trans.z += OBJ_SPEED;
	else if (keycode == KEY_Z || keycode == KEY_W_MAC)
		box->trans.z -= OBJ_SPEED;
	else if (keycode == KEY_PLUS || keycode == KEY_PLUS_MAC)
	{
		box->corner_min = vector_scalar(OBJ_PROP * 1.3, box->corner_min);
		box->corner_max = vector_scalar(-1, box->corner_min);
	}
	else if (keycode == KEY_MINUS || keycode == KEY_MINUS_MAC)
	{
		box->corner_min = vector_scalar(1 / (OBJ_PROP * 1.3), box->corner_min);
		box->corner_max = vector_scalar(-1, box->corner_min);
	}
	else
		key_hook_box_rotation(keycode, box);
	return (0);
}
