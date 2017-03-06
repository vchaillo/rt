/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_object.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:46 by vchaillo          #+#    #+#             */
/*   Updated: 2017/01/10 14:36:33 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object		*new_object(int type, void *object, t_color color, int mat)
{
	t_object	*new_object;

	if (!(new_object = (t_object*)malloc(sizeof(t_object))))
		print_error(MALLOC_ERROR);
	new_object->type = type;
	new_object->object = object;
	new_object->color = color;
	new_object->material = mat;
	return (new_object);
}

void			add_object(t_scene *scene, t_object *new)
{
	if (scene->objects == NULL)
	{
		scene->objects = new;
		scene->objects->next = NULL;
	}
	else
	{
		new->next = scene->objects;
		scene->objects = new;
	}
	scene->nb_objects++;
}

void			delete_objects(t_object *objects)
{
	t_object	*tmp;

	while (objects != NULL)
	{
		tmp = objects->next;
		if (objects->type == SPHERE)
			delete_sphere(objects->object);
		else if (objects->type == PLANE)
			delete_plane(objects->object);
		else if (objects->type == CYLINDER)
			delete_cylinder(objects->object);
		else if (objects->type == CONE)
			delete_cone(objects->object);
		objects->next = NULL;
		free(objects);
		objects = tmp;
	}
}
