/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:57:50 by valentin          #+#    #+#             */
/*   Updated: 2017/01/28 16:19:46 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			load_scene3_objects(t_scene *scene)
{
	int i;

	i = 2;
	while (i < 40)
	{
		add_object(scene, new_object(CYLINDER, new_cylinder(new_vector(0, 1, 0),
			new_vector(i, 0, -i), 1), new_color(RED), 100));
		add_object(scene, new_object(CYLINDER, new_cylinder(new_vector(0, 1, 0),
			new_vector(-i, 0, -i), 1), new_color(RED), 100));
		i += 3;
	}
	i = 1;
	while (i < 100)
	{
		add_object(scene, new_object(SPHERE, new_sphere(0, i, 0, 2),
			new_color(SEA_BLUE), 50));
		i += 4;
	}
	add_object(scene, new_object(PLANE, new_plane(0, 1, 0, 0),
		new_color(DARK_GREY), 1000));
}

void			load_scene3_lights(t_scene *scene)
{
	scene->amb_intensity = 0.3;
	scene->amb_color = new_color(WHITE);
	add_light(scene, new_light(SPOT, 1, new_vector(-15, 100, 20),
		new_color(WHITE)));
}

void			load_scene3(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_3;
	e->scene = new_scene(new_color(BLACK), new_camera(0, 0, 10));
	e->scene->camera->rot.x = 60;
	load_scene3_objects(e->scene);
	load_scene3_lights(e->scene);
}
