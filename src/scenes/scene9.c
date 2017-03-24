/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <hbock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:58:39 by hbock             #+#    #+#             */
/*   Updated: 2017/03/24 08:24:51 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		load_scene9_objects(t_scene *scene)
{
	t_vector	limits[2];

	limits[0] = new_vector(0, 0, 0);
	limits[1] = new_vector(0, 0, 0);
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(-4, -3.2, 0),
		2.6, new_vector(0, 1, 0), limits), new_color(BLACK),
		new_material(GLASS)));
	add_object(scene, new_object(BOX, new_box(new_vector(-2, -2, -2),
		new_vector(4.5, -4, -2), new_vector(0, 15, 0)), new_color(0x87E1FF),
		new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 1, 0), 6,
		NORMAL, limits), new_color(GREEN), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, -1, 0), 6,
		NORMAL, limits), new_color(GREY), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 0, 1), 14,
		NORMAL, limits), new_color(GREY), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(1, 0, 0), 8,
		NORMAL, limits), new_color(RED), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(-1, 0, 0), 8,
		NORMAL, limits), new_color(BLUE), new_material(BASIC)));
}

static void		load_scene9_lights(t_scene *scene)
{
	scene->amb_intensity = 0.3;
	scene->amb_color = new_color(WHITE);
	add_light(scene, new_light(SPOT, 0.5, new_vector(0, 2, 16),
		new_color(FAKE_WHITE)));
}

void			load_scene9(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_9;
	e->scene = new_scene(new_color(FAKE_BLACK), new_camera(new_vector(0, 0, 25),
		new_vector(0, 0, -1)));
	load_scene9_objects(e->scene);
	load_scene9_lights(e->scene);
}
