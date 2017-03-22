/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 21:44:49 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/22 02:15:38 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			load_scene1_objects(t_scene *scene)
{
  	t_vector	limits[2];

	limits[0] = new_vector(0, 0, 0);
	limits[1] = new_vector(0, 0, 0);
	add_object(scene, new_object(SPHERE,
				     new_sphere(new_vector(0, 10, 0), 10,
						new_vector(0, 1, 0),  limits),
				     new_color(ORANGE), new_material(PERLIN)));
	add_object(scene, new_object(PLANE,
				     new_plane(new_vector(0, 1, 0), 0, CHECK, limits),
				     new_color(WHITE), new_material(BASIC)));
}

void			load_scene1_lights(t_scene *scene)
{
	scene->amb_intensity = 0.3;
	scene->amb_color = new_color(WHITE);
	add_light(scene, new_light(SPOT, 1, new_vector(-50, 25, 100),
		new_color(WHITE)));
}

void			load_scene1(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_1;
	e->scene = new_scene(new_color(BLACK), new_camera(new_vector(0, 2, 65),
		new_vector(0, 0, -1)));
	load_scene1_objects(e->scene);
	load_scene1_lights(e->scene);
}
