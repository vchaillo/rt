/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <tlegroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 00:15:01 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/30 16:52:04 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			load_scene8_boxes(t_scene *scene)
{
	add_object(scene, new_object(BOX, new_box(new_vector(-2.7, -0.2, -1.2),
		new_vector(-6, -5, 9), new_vector(0, 0, 0)), new_color(PASTEL_GREEN),
		new_material(BASIC)));
	add_object(scene, new_object(BOX, new_box(new_vector(-2.7, -0.2, -1.2),
		new_vector(-6, -4.1, 6.8), new_vector(0, 0, 0)),
		new_color(PASTEL_GREEN), new_material(BASIC)));
	add_object(scene, new_object(BOX, new_box(new_vector(-2.7, -0.2, -1.2),
		new_vector(-6, -3.2, 4.6), new_vector(0, 0, 0)),
		new_color(PASTEL_GREEN), new_material(BASIC)));
	add_object(scene, new_object(BOX, new_box(new_vector(-2.7, -0.2, -1.2),
		new_vector(-6, -2.3, 2.4), new_vector(0, 0, 0)),
		new_color(PASTEL_GREEN), new_material(BASIC)));
	add_object(scene, new_object(BOX, new_box(new_vector(-2.7, -0.2, -1.2),
		new_vector(-6, -1.4, 0.2), new_vector(0, 0, 0)),
		new_color(PASTEL_GREEN), new_material(BASIC)));
	add_object(scene, new_object(BOX, new_box(new_vector(-2.7, -0.2, -1.2),
		new_vector(-6, -0.5, -2), new_vector(0, 0, 0)),
		new_color(PASTEL_GREEN), new_material(BASIC)));
	add_object(scene, new_object(BOX, new_box(new_vector(-2.7, -0.2, -1.2),
		new_vector(-6, 0.4, -4.2), new_vector(0, 0, 0)),
		new_color(PASTEL_GREEN), new_material(BASIC)));
	add_object(scene, new_object(BOX, new_box(new_vector(-2.7, -0.2, -1.2),
		new_vector(-6, 1.3, -6.4), new_vector(0, 0, 0)),
		new_color(PASTEL_GREEN), new_material(BASIC)));
}

static void			load_scene8_disc(t_scene *scene)
{
	add_object(scene, new_object(DISC, new_disc(2.7, 2.5, new_vector(4, 2, -5),
		new_vector(25, 0, 15)), new_color(P_GREEN_1), new_material(BASIC)));
	load_scene8_boxes(scene);
	add_object(scene, new_object(DISC, new_disc(2.9, 2.7, new_vector(4, 2, -5),
		new_vector(25, 0, 15)), new_color(P_GREEN_2), new_material(BASIC)));
	load_scene8_boxes(scene);
	add_object(scene, new_object(DISC, new_disc(3.1, 2.9, new_vector(4, 2, -5),
		new_vector(25, 0, 15)), new_color(P_GREEN_3), new_material(BASIC)));
	load_scene8_boxes(scene);
	add_object(scene, new_object(DISC, new_disc(3.3, 3.1, new_vector(4, 2, -5),
		new_vector(25, 0, 15)), new_color(P_GREEN_4), new_material(BASIC)));
	load_scene8_boxes(scene);
	add_object(scene, new_object(DISC, new_disc(3.5, 3.3, new_vector(4, 2, -5),
		new_vector(25, 0, 15)), new_color(P_GREEN_5), new_material(BASIC)));
	load_scene8_boxes(scene);
	add_object(scene, new_object(DISC, new_disc(3.7, 3.5, new_vector(4, 2, -5),
		new_vector(25, 0, 15)), new_color(P_GREEN_6), new_material(BASIC)));
	add_object(scene, new_object(BOX, new_box(new_vector(-2.7, -0.2, -1.2),
	new_vector(-6, 2.4, -8.6), new_vector(0, 0, 0)), new_color(PASTEL_GREEN),
		new_material(BASIC)));
	load_scene8_boxes(scene);
}

static void			load_scene8_objects(t_scene *scene)
{
	t_vector		limits[2];

	limits[0] = new_vector(0, 0, 0);
	limits[1] = new_vector(0, 0, 0);
	load_scene8_disc(scene);
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(-0, -3, 0),
		1.6, new_vector(0, 1, 0), limits),
		new_color(BLACK), new_material(CHROME)));
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(4, 2, -5),
		1.8, new_vector(0, 1, 0), limits), new_color(RED),
		new_material(GLASS)));
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(-4, 2, 10),
		2.5, new_vector(0, 1, 0), limits), new_color(RED),
		new_material(GLASS)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 1, 0), 6,
		CHECK, limits), new_color(BLACK), new_material(BASIC)));
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
	scene->amb_intensity = 0;
	scene->amb_color = new_color(WHITE);
	add_light(scene, new_light(LSPOT, 0.5, new_vector(3, 5, 13),
		new_color(FAKE_WHITE)));
	add_light(scene, new_light(LSPOT, 0.5, new_vector(-4, 5, 8),
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
