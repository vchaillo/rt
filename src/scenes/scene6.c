/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <tlegroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 00:15:01 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/22 02:53:51 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			load_scene6_objects(t_scene *scene)
{
      	t_vector	limits[2];
	float		abc[3];

	abc[0] = 1;
	abc[1] = 1;
	abc[2] = 1;
	limits[0] = new_vector(0, 0, 0);
	limits[1] = new_vector(0, 0, 0);
	(void)limits;
	add_object(scene, new_object(TORE, new_tore(new_vector(0, 0, 0), 5, 30),
				     new_color(ORANGE), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, -10, 0), 0, CHECK, limits),
				     new_color(BLUE), new_material(PERLIN)));
	add_object(scene, new_object(BOLOID, new_boloid(new_vector(0, 0, 0), abc, -1),
				     new_color(RED), new_material(GLASS)));
}

void			load_scene6_lights(t_scene *scene)
{
	scene->amb_intensity = 0.1;
	scene->amb_color = new_color(WHITE);
	add_light(scene, new_light(SPOT, 1, new_vector(0, 30, 0),
		new_color(WHITE)));
}

void			load_scene6(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_6;
	e->scene = new_scene(new_color(BLACK), new_camera(new_vector(0, 30, 100),
		new_vector(0, 0, -1)));
	load_scene6_objects(e->scene);
	load_scene6_lights(e->scene);
}
