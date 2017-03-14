/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 07:55:18 by hbock             #+#    #+#             */
/*   Updated: 2017/03/14 07:55:18 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			load_scene7_objects(t_scene *scene)
{
	add_object(scene, new_object(SPHERE, new_sphere(-4, 4, 0, 7),
		new_color(0x31c486), new_material(TEST)));
	add_object(scene, new_object(PLANE, new_plane(0, 1, 0, 5, NORMAL),
		new_color(SEA_BLUE), new_material(BASIC)));
}

void			load_scene7_lights(t_scene *scene)
{
	scene->amb_intensity = 0.3;
	scene->amb_color = new_color(BLUE);
	add_light(scene, new_light(SPOT, 0.5, new_vector(20, 10, 10),
		new_color(WHITE)));
	add_light(scene, new_light(SPOT, 0.5, new_vector(20, 10, 10),
		new_color(WHITE)));
	add_light(scene, new_light(SPOT, 0.5, new_vector(20, 10, 10),
		new_color(WHITE)));
}

void			load_scene7(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_6;
	e->scene = new_scene(new_color(BLACK), new_camera(10, 15, 40));
	e->scene->camera->rot.x -= 20;
	e->scene->camera->rot.y += 15;
	load_scene7_objects(e->scene);
	load_scene7_lights(e->scene);
}
