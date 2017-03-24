/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <tlegroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 00:15:01 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/24 08:23:20 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			load_scene8_boxes(t_scene *scene)
{
	add_object(scene, new_object(BOX, new_box(new_vector(-2, -0.7, -1.3),
		new_vector(-6, -4.6, 4), new_vector(0, 0, 0)), new_color(GREEN),
		new_material(BASIC)));
	add_object(scene, new_object(BOX, new_box(new_vector(-2, -0.7, -1.3),
		new_vector(-6, -3.2, 1.4), new_vector(0, 0, 0)), new_color(GREEN),
		new_material(BASIC)));
	add_object(scene, new_object(BOX, new_box(new_vector(-2, -0.7, -1.3),
		new_vector(-6, -1.8, -1.2), new_vector(0, 0, 0)), new_color(GREEN),
		new_material(BASIC)));
	add_object(scene, new_object(BOX, new_box(new_vector(-2, -0.7, -1.3),
		new_vector(-6, -0.4, -3.8), new_vector(0, 0, 0)), new_color(GREEN),
		new_material(BASIC)));
	add_object(scene, new_object(BOX, new_box(new_vector(-2, -0.7, -1.3),
		new_vector(-6, 1, -6.4), new_vector(0, 0, 0)), new_color(GREEN),
		new_material(BASIC)));
	add_object(scene, new_object(BOX, new_box(new_vector(-2, -0.7, -1.3),
		new_vector(-6, 2.4, -9), new_vector(0, 0, 0)), new_color(GREEN),
		new_material(BASIC)));
	add_object(scene, new_object(BOX, new_box(new_vector(-2, -0.7, -1.3),
		new_vector(-6, 3.8, -11.6), new_vector(0, 0, 0)), new_color(GREEN),
		new_material(BASIC)));
	add_object(scene, new_object(BOX, new_box(new_vector(-2, -0.7, -1.3),
		new_vector(-6, 5.2, -14.2), new_vector(0, 0, 0)), new_color(GREEN),
		new_material(BASIC)));
}

static void			load_scene8_objects(t_scene *scene)
{
	t_vector		limits[2];

	limits[0] = new_vector(0, 0, 0);
	limits[1] = new_vector(0, 0, 0);
	load_scene8_boxes(scene);
	add_object(scene, new_object(DISC, new_disc(2, 1, new_vector(-2, -2, 0),
		new_vector(45, 0, 0)), new_color(YELLOW), new_material(BASIC)));
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(-3.2, -3.2, -5),
		2.6, new_vector(0, 1, 0), limits),
		new_color(RED), new_material(CHROME)));
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(3.2, -3.2, 0),
		2.6, new_vector(0, 1, 0), limits), new_color(RED),
		new_material(GLASS)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 1, 0), 6,
		NORMAL, limits), new_color(GREY), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 1, 0), -6,
		NORMAL, limits), new_color(GREY), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 0, 1), 14,
		NORMAL, limits), new_color(GREY), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(-1, 0, 0), -8,
		NORMAL, limits), new_color(RED), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(1, 0, 0), -8,
		NORMAL, limits), new_color(BLUE), new_material(BASIC)));
}

static void			load_scene8_lights(t_scene *scene)
{
	scene->amb_intensity = 0.3;
	scene->amb_color = new_color(WHITE);
	add_light(scene, new_light(SPOT, 0.5, new_vector(0, 5, 2),
		new_color(FAKE_WHITE)));
}

void				load_scene8(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_8;
	e->scene = new_scene(new_color(FAKE_BLACK), new_camera(new_vector(0, 0, 25),
		new_vector(0, 0, -1)));
	load_scene8_objects(e->scene);
	load_scene8_lights(e->scene);
}
