/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 01:34:14 by hbock             #+#    #+#             */
/*   Updated: 2017/03/11 01:34:15 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			load_scene6_objects(t_scene *scene)
{
	add_object(scene, new_object(SPHERE, new_sphere(0, 1.8, 0, 2),
		new_color(BLUE), new_material(BIT_REF)));
	add_object(scene, new_object(SPHERE, new_sphere(0, -1.8, 0, 2),
		new_color(RED), new_material(BIT_REF)));
	add_object(scene, new_object(SPHERE, new_sphere(3, 0, 0, 2),
		new_color(GREEN), new_material(BIT_REF)));
}

void			load_scene6_lights(t_scene *scene)
{
	scene->amb_intensity = 0.3;
	scene->amb_color = new_color(BLUE);
	// add_light(scene, new_light(SPOT, 1, new_vector(-20, 15, 10),
	// 	new_color(WHITE)));
	add_light(scene, new_light(DIR, 0.5, new_vector(0, 0, -1),
		new_color(WHITE)));
}

void			load_scene6(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_6;
	e->scene = new_scene(new_color(BLACK), new_camera(0, 0, 20));
	load_scene6_objects(e->scene);
	load_scene6_lights(e->scene);
}
