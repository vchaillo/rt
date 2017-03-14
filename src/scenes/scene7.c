/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 07:55:18 by hbock             #+#    #+#             */
/*   Updated: 2017/03/14 07:55:18 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			load_scene7_objects(t_scene *scene)
{
	add_object(scene, new_object(SPHERE, new_sphere(-11, 0, -8, 3),
		new_color(BLACK), new_material(WATER)));
	add_object(scene, new_object(SPHERE, new_sphere(-2, 8, -17, 5),
		new_color(BLACK), new_material(WATER)));
	add_object(scene, new_object(SPHERE, new_sphere(-1, 6, -20, 2),
		new_color(BLUE), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(0, 1, 0, 4, WAVE),
		new_color(BLACK), new_material(WATER)));
	add_object(scene, new_object(PLANE, new_plane(0, 1, 0, 20, WAVE),
		new_color(SEA_BLUE), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(0, 1, 0, -20, NORMAL),
		new_color(LIGHT_BLUE), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(0, 0, 1, 20, NORMAL),
		new_color(PINK), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(-1, 0, 0, -20, NORMAL),
		new_color(YELLOW), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(0, 0, -1, 45, NORMAL),
		new_color(ORANGE), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(1, 0, 0, -40, NORMAL),
		new_color(RED), new_material(BASIC)));
	add_object(scene, new_object(CONE, new_cone(new_vector(-1, 1, 0),
		new_vector(-8, 10, -20), 15), new_color(GREEN),
			new_material(BASIC)));
	add_object(scene, new_object(CYLINDER, new_cylinder(new_vector(0, 1, -0.3),
		new_vector(-10, 0, -5), 2), new_color(PASTEL_BLUE),
			new_material(GLASS)));
}

void			load_scene7_lights(t_scene *scene)
{
	scene->amb_intensity = 0.3;
	scene->amb_color = new_color(BLUE);
	add_light(scene, new_light(SPOT, 0.5, new_vector(20, 10, 10),
		new_color(WHITE)));
}

void			load_scene7(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_6;
	e->scene = new_scene(new_color(BLACK), new_camera(10, 15, 40));
	e->scene->camera->rot.x -= 20;
	e->scene->camera->rot.y += 15;
	load_scene7_objects(e->scene);
	load_scene7_lights(e->scene);
}
