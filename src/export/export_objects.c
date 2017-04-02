/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 09:12:27 by vchaillo          #+#    #+#             */
/*   Updated: 2017/04/01 21:15:16 by valentinchaillou ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			print_cylinder_tofile(t_cylinder *cylinder, int fd)
{
	print_tag_tofile("cylinder", TAG_OPEN_ENDL, 3, fd);
	print_vector_tofile(cylinder->axis, "axis", 4, fd);
	print_vector_tofile(cylinder->pos, "pos", 4, fd);
	print_tag_tofile("r", TAG_OPEN, 4, fd);
	ft_putfloat_fd(cylinder->r, 1, fd);
	print_tag_tofile("r", TAG_CLOSE, 0, fd);
	print_tag_tofile("cylinder", TAG_CLOSE, 3, fd);
	print_tag_tofile("limits", TAG_OPEN_ENDL, 3, fd);
	print_vector_tofile(cylinder->limit_min, "min", 4, fd);
	print_vector_tofile(cylinder->limit_max, "max", 4, fd);
	print_tag_tofile("limits", TAG_CLOSE, 3, fd);
}

static void			print_plane_tofile(t_env *e, t_plane *plane, int fd)
{
	print_tag_tofile("plane", TAG_OPEN_ENDL, 3, fd);
	print_vector_tofile(plane->normal, "normal", 4, fd);
	print_tag_tofile("offset", TAG_OPEN, 4, fd);
	ft_putfloat_fd(plane->offset, 1, fd);
	print_tag_tofile("offset", TAG_CLOSE, 0, fd);
	print_tag_tofile("style", TAG_OPEN, 4, fd);
	ft_putstr_fd(e->macros.plane_styles[plane->type].define, fd);
	print_tag_tofile("style", TAG_CLOSE, 0, fd);
	print_tag_tofile("plane", TAG_CLOSE, 3, fd);
	print_tag_tofile("limits", TAG_OPEN_ENDL, 3, fd);
	print_vector_tofile(plane->limit_min, "min", 4, fd);
	print_vector_tofile(plane->limit_max, "max", 4, fd);
	print_tag_tofile("limits", TAG_CLOSE, 3, fd);
}

static void			print_sphere_tofile(t_sphere *sphere, int fd)
{
	print_tag_tofile("sphere", TAG_OPEN_ENDL, 3, fd);
	print_vector_tofile(sphere->pos, "pos", 4, fd);
	print_tag_tofile("r", TAG_OPEN, 4, fd);
	ft_putfloat_fd(sphere->r, 1, fd);
	print_tag_tofile("r", TAG_CLOSE, 0, fd);
	print_vector_tofile(sphere->axis, "axis", 4, fd);
	print_tag_tofile("sphere", TAG_CLOSE, 3, fd);
	print_tag_tofile("limits", TAG_OPEN_ENDL, 3, fd);
	print_vector_tofile(sphere->limit_min, "min", 4, fd);
	print_vector_tofile(sphere->limit_max, "max", 4, fd);
	print_tag_tofile("limits", TAG_CLOSE, 3, fd);
}

static void			print_object_tofile(t_env *e, t_object *object, int fd)
{
	if (object->type == SPHERE)
		print_sphere_tofile(object->object, fd);
	else if (object->type == PLANE)
		print_plane_tofile(e, object->object, fd);
	else if (object->type == CYLINDER)
		print_cylinder_tofile(object->object, fd);
	else if (object->type == CONE)
		print_cone_tofile(object->object, fd);
	else if (object->type == TORE)
		print_tore_tofile(object->object, fd);
	else if (object->type == BOLOID)
		print_boloid_tofile(object->object, fd);
	else if (object->type == BOX)
		print_box_tofile(object->object, fd);
	else if (object->type == DISC)
		print_disc_tofile(object->object, fd);
}

void				print_objects_tofile(t_env *e, int fd)
{
	t_object		*tmp;

	print_tag_tofile("objects", TAG_OPEN_ENDL, 1, fd);
	tmp = e->scene->objects;
	while (tmp != NULL)
	{
		print_tag_tofile("object", TAG_OPEN_ENDL, 2, fd);
		print_tag_tofile("type", TAG_OPEN, 3, fd);
		ft_putstr_fd(e->macros.objects[tmp->type].define, fd);
		print_tag_tofile("type", TAG_CLOSE, 0, fd);
		print_tag_tofile("color", TAG_OPEN, 3, fd);
		print_color_tofile(e, tmp->color, fd);
		print_tag_tofile("color", TAG_CLOSE, 0, fd);
		print_tag_tofile("material", TAG_OPEN, 3, fd);
		ft_putstr_fd(e->macros.materials[tmp->material.type].define, fd);
		print_tag_tofile("material", TAG_CLOSE, 0, fd);
		print_object_tofile(e, tmp, fd);
		print_tag_tofile("object", TAG_CLOSE, 2, fd);
		tmp = tmp->next;
	}
	print_tag_tofile("objects", TAG_CLOSE, 1, fd);
}
