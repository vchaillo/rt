/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:57:50 by valentin          #+#    #+#             */
/*   Updated: 2017/03/13 17:17:19 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			load_scene3_objects(t_scene *scene)
{
	add_object(scene, new_object(SPHERE, new_sphere(0, 0, 0, 30),
		new_color(RED), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 1, 0), 35, NORMAL),
		new_color(DARK_GREY), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, -1, 0), 35, NORMAL),
		new_color(DARK_GREY), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 0, 1), 35, NORMAL),
		new_color(DARK_GREY), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(1, 0, 0), 35, NORMAL),
		new_color(DARK_GREY), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(-1, 0, 0), 35, NORMAL),
		new_color(DARK_GREY), new_material(BASIC)));
}

void			load_scene3_lights(t_scene *scene)
{
	scene->amb_intensity = 0.3;
	scene->amb_color = new_color(WHITE);
	add_light(scene, new_light(SPOT, 1, new_vector(0, 0, 310),
		new_color(WHITE)));
}

void			load_scene3(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_3;
	e->scene = new_scene(new_color(BLACK), new_camera(0, 0, 310));
	load_scene3_objects(e->scene);
	load_scene3_lights(e->scene);
}
