/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_scene.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:57 by vchaillo          #+#    #+#             */
/*   Updated: 2017/01/10 14:36:36 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_scene			*new_scene(t_color background_color, t_camera *camera)
{
	t_scene		*scene;

	if (!(scene = (t_scene*)malloc(sizeof(t_scene))))
		print_error(MALLOC_ERROR);
	scene->background_color = background_color;
	scene->selected_object = NULL;
	scene->nb_objects = 0;
	scene->nb_lights = 0;
	scene->camera = camera;
	scene->objects = NULL;
	scene->lights = NULL;
	scene->amb = ACTIVE;
	scene->diffuse = ACTIVE;
	scene->specular = ACTIVE;
	scene->dir = ACTIVE;
	scene->spot = ACTIVE;
	scene->mode = MOVE_MODE;
	return (scene);
}

void			delete_scene(t_scene *scene)
{
	if (scene)
	{
		delete_camera(scene->camera);
		delete_objects(scene->objects);
		scene->nb_objects = 0;
		delete_lights(scene->lights);
		scene->nb_lights = 0;
		free(scene);
	}
}
