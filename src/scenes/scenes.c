/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:53:08 by valentin          #+#    #+#             */
/*   Updated: 2017/01/10 14:35:53 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			load_scene(int scene_type, t_env *e)
{
	if (scene_type == SCENE_1)
		load_scene1(e);
	else if (scene_type == SCENE_2)
		load_scene2(e);
	else if (scene_type == SCENE_3)
		load_scene3(e);
	else if (scene_type == SCENE_4)
		load_scene4(e);
	else if (scene_type == SCENE_5)
		load_scene5(e);
}

void			switch_scene(int keycode, t_env *e)
{
	if (keycode == LEFT)
		e->scene_type--;
	else if (keycode == RIGHT)
		e->scene_type++;
	if (e->scene_type == 0)
		e->scene_type = NB_SCENES;
	else if (e->scene_type == NB_SCENES + 1)
		e->scene_type = SCENE_1;
	load_scene(e->scene_type, e);
}
