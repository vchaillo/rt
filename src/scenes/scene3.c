/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:57:50 by valentin          #+#    #+#             */
/*   Updated: 2017/03/24 08:19:41 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			load_scene3_objects(t_scene *scene)
{
	t_vector	limits[2];

	limits[0] = new_vector(0, 0, 0);
	limits[1] = new_vector(0, 0, 0);
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(0, 1.5, 0), 3,
		new_vector(0, 1, 0), limits),
		new_color(RED), new_material(BIT_REF)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 1, 0), 0,
		NORMAL, limits), new_color(BLUE), new_material(BIT_REF)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, -1, 0), 10,
		NORMAL, limits), new_color(BLUE), new_material(BIT_REF)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 0, 1), 5,
		NORMAL, limits), new_color(BLUE), new_material(BIT_REF)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 0, 1), -32,
		NORMAL, limits), new_color(BLUE), new_material(BIT_REF)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(1, 0, 0), 5,
		NORMAL, limits), new_color(BLUE), new_material(BIT_REF)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(-1, 0, 0), 5,
		NORMAL, limits), new_color(BLUE), new_material(BIT_REF)));
}

static void			load_scene3_lights(t_scene *scene)
{
	scene->amb_intensity = 0.3;
	scene->amb_color = new_color(WHITE);
	add_light(scene, new_light(SPOT, 1, new_vector(0, 9, 30),
		new_color(WHITE)));
}

void				load_scene3(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_3;
	e->scene = new_scene(new_color(BLACK), new_camera(new_vector(0, 1.5, 20),
		new_vector(0, 2, 0)));
	load_scene3_objects(e->scene);
	load_scene3_lights(e->scene);
}
