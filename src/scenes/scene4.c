/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:12:42 by valentin          #+#    #+#             */
/*   Updated: 2017/01/28 16:56:49 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			load_scene4_objects(t_scene *scene)
{
	int			i;

	i = 0;
	while (i > -100)
	{
		add_object(scene, new_object(CYLINDER, new_cylinder(new_vector(0, 1, 0),
			new_vector(10, 0, i), 1), new_color(PASTEL_BLUE), 100));
		add_object(scene, new_object(CYLINDER, new_cylinder(new_vector(0, 1, 0),
			new_vector(-10, 0, i), 1), new_color(PASTEL_BLUE), 100));
		i -= 4;
	}
	add_object(scene, new_object(SPHERE, new_sphere(0, 10, -100, 10),
		new_color(ORANGE), 100));
	add_object(scene, new_object(SPHERE, new_sphere(0, 30, -100, 10),
		new_color(RED), 100));
	add_object(scene, new_object(PLANE, new_plane(0, 1, 0, 0),
		new_color(LIGHT_GREY), 100));
}

void			load_scene4_lights(t_scene *scene)
{
	scene->amb_intensity = 0.5;
	scene->amb_color = new_color(DARK_GREY);
	add_light(scene, new_light(SPOT, 1, new_vector(0, 10, 10),
		new_color(WHITE)));
}

void			load_scene4(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_4;
	e->scene = new_scene(new_color(BLACK), new_camera(0, 8, 0));
	load_scene4_objects(e->scene);
	load_scene4_lights(e->scene);
}
