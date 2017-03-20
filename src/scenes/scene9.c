/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <hbock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:58:39 by hbock             #+#    #+#             */
/*   Updated: 2017/03/09 23:13:38 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			load_scene9_objects(t_scene *scene)
{
	t_vector	limits[2];

	limits[0] = new_vector(0, 0, 0);
	limits[1] = new_vector(0, 0, 0);
	// add_object(scene, new_object(BOX, new_box(new_vector(-2,-1,-1.3), new_vector(-3, -5, 4),
	// 	new_vector(0, 0, 0)), new_color(YELLOW), new_material(BASIC)));
	// add_object(scene, new_object(DISC, new_disc(3, 1, new_vector(0, -1, 0), new_vector(0, 0, 0)),
	// 			     new_color(GREEN), new_material(BASIC)));
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(0, -3.2, 0), 2.6,
							new_vector(0, 1, 0), limits),
				     new_color(YELLOW), new_material(BASIC)));
	// add_object(scene, new_object(SPHERE, new_sphere(new_vector(3.2, -3.2, 0), 2.6,
	// 						new_vector(0, 1, 0), limits),
	// 			     new_color(RED), new_material(GLASS)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 1, 0), 6,
		NORMAL, limits), new_color(GREEN), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 1, 0), -6,
		NORMAL, limits), new_color(GREY), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 0, 1), 14,
		NORMAL, limits), new_color(GREY), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(-1, 0, 0), -8,
		NORMAL, limits), new_color(RED), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(1, 0, 0), -8,
		NORMAL, limits), new_color(BLUE), new_material(BASIC)));
}

void			load_scene9_lights(t_scene *scene)
{
	scene->amb_intensity = 0.3;
	scene->amb_color = new_color(BLUE);
	add_light(scene, new_light(SPOT, 0.5, new_vector(0, 2, 11),
		new_color(FAKE_WHITE)));
}

void			load_scene9(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_8;
	e->scene = new_scene(new_color(FAKE_BLACK), new_camera(new_vector(0, 0, 25),
		new_vector(0, 0, -1)));
	load_scene9_objects(e->scene);
	load_scene9_lights(e->scene);
}
