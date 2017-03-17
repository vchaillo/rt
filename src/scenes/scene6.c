/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <tlegroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 00:15:01 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/14 19:37:10 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			load_scene6_objects(t_scene *scene)
{
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 10, 0), 0, CHECK),
								 new_color(WHITE), new_material(BASIC)));
	add_object(scene, new_object(TORE, new_tore(new_vector(0, 0, 0), 5, 20),
								 new_color(ORANGE), new_material(PERLIN)));
/*	add_object(scene, new_object(BOLOID, new_boloid(new_vector(0, 0, 0), 1/(5*5), 1/(5*5), 1/(10*10)),
	new_color(BLUE), new_material(GLASS))); */
}

void			load_scene6_lights(t_scene *scene)
{
	scene->amb_intensity = 0;
	scene->amb_color = new_color(WHITE);
	add_light(scene, new_light(SPOT, 1, new_vector(0, 40, 10),
		new_color(WHITE)));
}

void			load_scene6(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_6;
	e->scene = new_scene(new_color(BLACK), new_camera(new_vector(0, 20, 100),
		new_vector(0, 0, -1)));
	load_scene6_objects(e->scene);
	load_scene6_lights(e->scene);
}
