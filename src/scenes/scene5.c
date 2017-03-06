/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:12:42 by valentin          #+#    #+#             */
/*   Updated: 2017/01/28 16:37:40 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			load_scene5_objects(t_scene *scene)
{
	add_object(scene, new_object(CONE, new_cone(new_vector(0, 1, -0.5),
		new_vector(8, 4, -5), 30), new_color(LIGHT_BLUE), 100));
	add_object(scene, new_object(CYLINDER, new_cylinder(new_vector(0, 1, -0.3),
		new_vector(-10, 0, -5), 2), new_color(PASTEL_BLUE), 100));
	add_object(scene, new_object(SPHERE, new_sphere(-1, 3, 2, 2),
		new_color(BLUE), 100));
	add_object(scene, new_object(PLANE, new_plane(0, -1, 0, 0),
		new_color(DARK_GREY), 100));
}

void			load_scene5_lights(t_scene *scene)
{
	scene->amb_intensity = 0.3;
	scene->amb_color = new_color(BLUE);
	add_light(scene, new_light(SPOT, 1, new_vector(-20, 15, 10),
		new_color(WHITE)));
	add_light(scene, new_light(DIR, 0.5, new_vector(0, -1, -1),
		new_color(WHITE)));
}

void			load_scene5(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_5;
	e->scene = new_scene(new_color(BLACK), new_camera(0, 4, 20));
	load_scene5_objects(e->scene);
	load_scene5_lights(e->scene);
}
