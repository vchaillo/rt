/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:12:42 by valentin          #+#    #+#             */
/*   Updated: 2017/03/30 16:51:47 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			load_scene4_objects(t_scene *scene)
{
	int			i;
	t_vector	limits[2];

	limits[0] = new_vector(0, 0, 0);
	limits[1] = new_vector(0, 0, 0);
	i = 0;
	while (i > -100)
	{
		add_object(scene, new_object(CYLINDER, new_cylinder(new_vector(0, 1, 0),
			new_vector(10, 0, i), 1, limits), new_color(PASTEL_BLUE),
			new_material(BASIC)));
		add_object(scene, new_object(CYLINDER, new_cylinder(new_vector(0, 1, 0),
			new_vector(-10, 0, i), 1, limits), new_color(PASTEL_BLUE),
			new_material(BASIC)));
		i -= 4;
	}
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(0, 10, -100),
		10, new_vector(0, 1, 0), limits),
		new_color(ORANGE), new_material(BASIC)));
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(0, 30, -100),
		10, new_vector(0, 1, 0), limits),
		new_color(RED), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 1, 0), 0,
		NORMAL, limits), new_color(LIGHT_GREY), new_material(BASIC)));
}

static void			load_scene4_lights(t_scene *scene)
{
	scene->amb_intensity = 0.5;
	scene->amb_color = new_color(DARK_GREY);
	add_light(scene, new_light(LSPOT, 1, new_vector(0, 10, 10),
		new_color(WHITE)));
}

void				load_scene4(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_4;
	e->scene = new_scene(new_color(BLACK), new_camera(new_vector(0, 8, 0),
		new_vector(0, 10, -100)));
	load_scene4_objects(e->scene);
	load_scene4_lights(e->scene);
}
