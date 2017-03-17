/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <tlegroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 00:15:01 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/14 19:37:10 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			load_scene8_objects(t_scene *scene)
{
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(-11, 0, -8), 3),
		new_color(BLACK), new_material(WATER)));
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(-2, 8, -17), 5),
		new_color(BLACK), new_material(WATER)));
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(-1, 6, -20), 2),
		new_color(BLUE), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 1, 0), 8,
		WAVE), new_color(CYAN), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 1, 0), -20,
		NORMAL), new_color(CYAN), new_material(BASIC)));
	// add_object(scene, new_object(PLANE, new_plane(new_vector(0, -1, 0), 5,
		// NORMAL), new_color(CYAN), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 0, 1), 20,
		NORMAL), new_color(PINK), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(-1, 0, 0), -20,
		NORMAL), new_color(YELLOW), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 0, -1), 45,
		NORMAL), new_color(ORANGE), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(1, 0, 0), -40,
		NORMAL), new_color(RED), new_material(BASIC)));
	// add_object(scene, new_object(CONE, new_cone(new_vector(-1, 1, 0),
	// 	new_vector(-8, 10, -20), 15), new_color(GREEN),	new_material(BASIC)));
	add_object(scene, new_object(CYLINDER, new_cylinder(new_vector(0, 1, -0.3),
		new_vector(-10, 0, -5), 2), new_color(PASTEL_BLUE),
		new_material(GLASS)));
	// add_object(scene, new_object(PLANE, new_plane(new_vector(-1, 0, 0), 5,
		// NORMAL), new_color(PURPLE), new_material(BASIC)));
}

void			load_scene8_lights(t_scene *scene)
{
	scene->amb_intensity = 0.3;
	scene->amb_color = new_color(BLUE);
	// add_light(scene, new_light(SPOT, 1, new_vector(-20, 15, 10),
	// 	new_color(WHITE)));
	add_light(scene, new_light(SPOT, 0.5, new_vector(20, 10, 10),
		new_color(WHITE)));
}

void			load_scene8(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_8;
	e->scene = new_scene(new_color(BLACK), new_camera(new_vector(10, 15, 20),
		new_vector(0, 0, -1)));
	load_scene8_objects(e->scene);
	load_scene8_lights(e->scene);
}
