/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 00:15:01 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/14 01:39:25 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			load_scene6_objects(t_scene *scene)
{
	add_object(scene, new_object(TORE, new_tore(new_vector(0, 2, 0), 1, 5),
	   new_color(ORANGE), new_material(BASIC)));
	add_object(scene, new_object(BOLOID, new_boloid(new_vector(0, 0, 0), 1/(1*100), 1/(1*100), 1/(2*200)),
								 new_color(BLUE), new_material(BASIC)));
	/*add_object(scene, new_object(PLANE, new_plane(new_vector(0, 1, 0), 0, CHECK),
	  new_color(WHITE), new_material(BASIC)));*/
}

void			load_scene6_lights(t_scene *scene)
{
	scene->amb_intensity = 0.3;
	scene->amb_color = new_color(WHITE);
	add_light(scene, new_light(SPOT, 1, new_vector(0, 40, 10),
		new_color(WHITE)));
}

void			load_scene6(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_6;
	e->scene = new_scene(new_color(BLACK), new_camera(0, 20, 100));
	load_scene6_objects(e->scene);
	load_scene6_lights(e->scene);
}
