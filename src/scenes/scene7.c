/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <hbock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 07:55:18 by hbock             #+#    #+#             */
/*   Updated: 2017/03/24 08:18:15 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			load_scene7_objects(t_scene *scene)
{
	t_vector	limits[2];

	limits[0] = new_vector(0, 0, 0);
	limits[1] = new_vector(0, 0, 0);
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(0, 0, 0), 7,
		new_vector(0, 1, 0), limits),
		new_color(0x31c486), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 1, 0), 0,
		NORMAL, limits), new_color(RED), new_material(BASIC)));
}

static void			load_scene7_lights(t_scene *scene)
{
	scene->amb_intensity = 1;
	scene->amb_color = new_color(WHITE);
	add_light(scene, new_light(SPOT, 0.5, new_vector(20, 100, 10),
		new_color(WHITE)));
}

void				load_scene7(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_7;
	e->scene = new_scene(new_color(BLACK), new_camera(new_vector(0, 10, 50),
		new_vector(0, 10, 0)));
	load_scene7_objects(e->scene);
	load_scene7_lights(e->scene);
}
