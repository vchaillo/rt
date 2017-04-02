/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <hbock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 07:55:18 by hbock             #+#    #+#             */
/*   Updated: 2017/04/02 16:57:45 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			load_scene7_objects(t_scene *scene)
{
	t_vector	limits[2];

	limits[0] = new_vector(0, 0, 0);
	limits[1] = new_vector(0, 0, 0);
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(-50, 10, 0), 10,
		new_vector(0, 1, 0), limits),
		new_color(ORANGE), new_material(TIGER)));
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(-25, 10, 0), 10,
		new_vector(0, 1, 0), limits),
		new_color(BLUE), new_material(PLASTIC)));
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(0, 10, 0), 10,
		new_vector(0, 1, 0), limits),
		new_color(YELLOW), new_material(BASIC)));
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(25, 10, 0), 10,
		new_vector(0, 1, 0), limits),
		new_color(GREEN), new_material(PLASTIC)));
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(50, 10, 0), 10,
		new_vector(0, 1, 0), limits),
		new_color(RED), new_material(PERLIN)));
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(0, 100, -100),
		100, new_vector(0, 1, 0), limits),
		new_color(RED), new_material(CHROME)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 1, 0), 0,
		NORMAL, limits), new_color(WHITE), new_material(BIT_REF)));
}

static void			load_scene7_lights(t_scene *scene)
{
	scene->amb_intensity = 0.05;
	scene->amb_color = new_color(WHITE);
	add_light(scene, new_light(LSPOT, 0.5, new_vector(20, 100, 100),
		new_color(WHITE)));
}

void				load_scene7(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_7;
	e->scene = new_scene(new_color(BLACK), new_camera(new_vector(0, 10, 100),
		new_vector(0, 10, 0)));
	load_scene7_objects(e->scene);
	load_scene7_lights(e->scene);
}
