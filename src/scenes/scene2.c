/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:12:42 by valentin          #+#    #+#             */
/*   Updated: 2017/03/29 00:41:21 by valentinchaillou89###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			load_scene2_objects(t_scene *scene)
{
	t_vector	limits[2];

	limits[0] = new_vector(0, 0, 0);
	limits[1] = new_vector(0, 0, 0);
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(0, 0, 0), 1,
		new_vector(0, 1, 0), limits),
		new_color(WHITE), new_material(BASIC)));
}

static void			load_scene2_lights(t_scene *scene)
{
	scene->amb_intensity = 0;
	scene->amb_color = new_color(WHITE);
	add_light(scene, new_light(LDIR, 1, new_vector(1, -1, -1),
		new_color(RED)));
	add_light(scene, new_light(LDIR, 1, new_vector(-1, -1, -1),
		new_color(BLUE)));
	add_light(scene, new_light(LDIR, 1, new_vector(0, 1, -1),
		new_color(GREEN)));
}

void				load_scene2(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_2;
	e->scene = new_scene(new_color(BLACK), new_camera(new_vector(0, 0, 4),
		new_vector(0, 0, -1)));
	load_scene2_objects(e->scene);
	load_scene2_lights(e->scene);
}
