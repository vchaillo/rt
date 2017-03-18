/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 09:12:27 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/17 10:10:42 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			print_cone_tofile(t_cone *cone, int fd)
{
	print_tag_tofile("cone", TAG_OPEN_ENDL, 3, fd);
	print_vector_tofile(cone->axis, "axis", 4, fd);
	print_vector_tofile(cone->apex, "apex", 4, fd);
	print_tag_tofile("angle", TAG_OPEN, 4, fd);
	dprintf(fd, "%.1f", cone->angle);
	print_tag_tofile("angle", TAG_CLOSE, 0, fd);
	print_tag_tofile("cone", TAG_CLOSE, 3, fd);
}


static void			print_cylinder_tofile(t_cylinder *cylinder, int fd)
{
	print_tag_tofile("cylinder", TAG_OPEN_ENDL, 3, fd);
	print_vector_tofile(cylinder->axis, "axis", 4, fd);
	print_vector_tofile(cylinder->pos, "pos", 4, fd);
	print_tag_tofile("r", TAG_OPEN, 4, fd);
	dprintf(fd, "%.1f", cylinder->r);
	print_tag_tofile("r", TAG_CLOSE, 0, fd);
	print_tag_tofile("cylinder", TAG_CLOSE, 3, fd);
}


static void			print_plane_tofile(t_plane *plane, int fd)
{
	print_tag_tofile("plane", TAG_OPEN_ENDL, 3, fd);
	print_vector_tofile(plane->normal, "normal", 4, fd);
	print_tag_tofile("offset", TAG_OPEN, 4, fd);
	dprintf(fd, "%.1f", plane->offset);
	print_tag_tofile("offset", TAG_CLOSE, 0, fd);
	print_tag_tofile("plane", TAG_CLOSE, 3, fd);
}

static void			print_sphere_tofile(t_sphere *sphere, int fd)
{
	print_tag_tofile("sphere", TAG_OPEN_ENDL, 3, fd);
	print_vector_tofile(sphere->pos, "pos", 4, fd);
	print_tag_tofile("r", TAG_OPEN, 4, fd);
	dprintf(fd, "%.1f", sphere->r);
	print_tag_tofile("r", TAG_CLOSE, 0, fd);
	print_tag_tofile("sphere", TAG_CLOSE, 3, fd);
}

void			print_objects_tofile(t_object *objects, int fd)
{
	t_object	*tmp;

	print_tag_tofile("objects", TAG_OPEN_ENDL, 1, fd);
	tmp = objects;
	while (tmp != NULL)
	{
		print_tag_tofile("object", TAG_OPEN_ENDL, 2, fd);
		print_tag_tofile("type", TAG_OPEN, 3, fd);
		ft_putnbr_fd(tmp->type, fd);
		print_tag_tofile("type", TAG_CLOSE, 0, fd);
		print_color_tofile(tmp->color, "color", 3, fd);
		print_tag_tofile("material", TAG_OPEN, 3, fd);
		ft_putnbr_fd(tmp->material.type, fd);
		print_tag_tofile("material", TAG_CLOSE, 0, fd);
		if (tmp->type == SPHERE)
			print_sphere_tofile(tmp->object, fd);
		else if (tmp->type == PLANE)
			print_plane_tofile(tmp->object, fd);
		else if (tmp->type == CYLINDER)
			print_cylinder_tofile(tmp->object, fd);
		else if (tmp->type == CONE)
			print_cone_tofile(tmp->object, fd);
		print_tag_tofile("object", TAG_CLOSE, 2, fd);
		tmp = tmp->next;
	}
	print_tag_tofile("objects", TAG_CLOSE, 1, fd);
}