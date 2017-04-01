/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_disc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:19:44 by hbock             #+#    #+#             */
/*   Updated: 2017/04/01 17:19:44 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int			key_hook_disc_rotation(int keycode, t_disc *disc)
{
	if (keycode == KEY_UP || keycode == KEY_UP_MAC)
		disc->rotxyz.x -= OBJ_ROT;
	else if (keycode == KEY_DOWN || keycode == KEY_DOWN_MAC)
		disc->rotxyz.x += OBJ_ROT;
	else if (keycode == KEY_LEFT || keycode == KEY_LEFT_MAC)
		disc->rotxyz.y += OBJ_ROT;
	else if (keycode == KEY_RIGHT || keycode == KEY_RIGHT_MAC)
		disc->rotxyz.y -= OBJ_ROT;
	else if (keycode == KEY_A || keycode == KEY_Q_MAC)
		disc->rotxyz.z += OBJ_ROT;
	else if (keycode == KEY_E || keycode == KEY_E_MAC)
		disc->rotxyz.z -= OBJ_ROT;
	return (0);
}

int					key_hook_disc(int keycode, t_disc *disc)
{
	if (keycode == KEY_D || keycode == KEY_D_MAC)
		disc->pos.x += OBJ_SPEED;
	else if (keycode == KEY_Q || keycode == KEY_A_MAC)
		disc->pos.x -= OBJ_SPEED;
	else if (keycode == KEY_SPACE || keycode == KEY_SPACE_MAC)
		disc->pos.y += OBJ_SPEED;
	else if (keycode == KEY_CONTROL || keycode == KEY_CONTROL_MAC)
		disc->pos.y -= OBJ_SPEED;
	else if (keycode == KEY_S || keycode == KEY_S_MAC)
		disc->pos.z += OBJ_SPEED;
	else if (keycode == KEY_Z || keycode == KEY_W_MAC)
		disc->pos.z -= OBJ_SPEED;
	else if (keycode == KEY_PLUS || keycode == KEY_PLUS_MAC)
	{
		disc->r_min = 1.3 * OBJ_PROP * disc->r_min;
		disc->r_max = 1.3 * OBJ_PROP * disc->r_max;
	}
	else if (keycode == KEY_MINUS || keycode == KEY_MINUS_MAC)
	{
		disc->r_min = (1 / 1.3) * OBJ_PROP * disc->r_min;
		disc->r_max = (1 / 1.3) * OBJ_PROP * disc->r_max;
	}
	else
		key_hook_disc_rotation(keycode, disc);
	return (0);
}
