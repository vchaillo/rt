/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <tlegroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 00:15:01 by tlegroux          #+#    #+#             */
/*   Updated: 2017/04/02 16:35:55 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			load_scene6_objects(t_scene *scene)
{
	t_vector	limits[2];

	limits[0] = new_vector(0, 0, 0);
	limits[1] = new_vector(0, 0, 0);
	add_object(scene, new_object(TORE, new_tore(new_vector(0, 0, 0), 5, 31,
		limits), new_color(BLUE), new_material(BASIC)));
	add_object(scene, new_object(TORE, new_tore(new_vector(0, 0, 0), 5, 10,
		limits), new_color(BLUE), new_material(CHROME)));
	add_object(scene, new_object(BOLOID, new_boloid(new_vector(0, -50, 0),
		new_vector(1, 1, 1), 1, limits), new_color(RED), new_material(PERLIN)));
}

static void			load_scene6_lights(t_scene *scene)
{
	scene->amb_intensity = 0.1;
	scene->amb_color = new_color(WHITE);
	add_light(scene, new_light(LSPOT, 1, new_vector(30, 30, 30),
		new_color(WHITE)));
	add_light(scene, new_light(LSPOT, 1, new_vector(0, -100, 0),
		new_color(WHITE)));
}

void				load_scene6(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_6;
	e->scene = new_scene(new_color(BLACK), new_camera(new_vector(0, 20, 100),
		new_vector(0, 0, -1)));
	load_scene6_objects(e->scene);
	load_scene6_lights(e->scene);
}
