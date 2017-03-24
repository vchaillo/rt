/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_lights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 09:12:27 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/24 04:44:48 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			print_spotlight_tofile(t_light *light, int fd)
{
	print_tag_tofile("light", TAG_OPEN_ENDL, 2, fd);
	print_tag_tofile("type", TAG_OPEN, 3, fd);
	ft_putnbr_fd(light->type, fd);
	print_tag_tofile("type", TAG_CLOSE, 0, fd);
	print_tag_tofile("intensity", TAG_OPEN, 3, fd);
	dprintf(fd, "%.1f", light->intensity);
	print_tag_tofile("intensity", TAG_CLOSE, 0, fd);
	print_color_tofile(light->color, "color", 3, fd);
	print_tag_tofile("spot", TAG_OPEN_ENDL, 3, fd);
	print_vector_tofile(light->pos, "pos", 4, fd);
	print_tag_tofile("spot", TAG_CLOSE, 3, fd);
	print_tag_tofile("light", TAG_CLOSE, 2, fd);
}

static void			print_dirlight_tofile(t_light *light, int fd)
{
	print_tag_tofile("light", TAG_OPEN_ENDL, 2, fd);
	print_tag_tofile("type", TAG_OPEN, 3, fd);
	ft_putnbr_fd(light->type, fd);
	print_tag_tofile("type", TAG_CLOSE, 0, fd);
	print_tag_tofile("intensity", TAG_OPEN, 3, fd);
	dprintf(fd, "%.1f", light->intensity);
	print_tag_tofile("intensity", TAG_CLOSE, 0, fd);
	print_color_tofile(light->color, "color", 3, fd);
	print_tag_tofile("dir", TAG_OPEN_ENDL, 3, fd);
	print_vector_tofile(light->dir, "dir", 4, fd);
	print_tag_tofile("dir", TAG_CLOSE, 3, fd);
	print_tag_tofile("light", TAG_CLOSE, 2, fd);
}

void				print_lights_tofile(t_env *e, t_light *lights, int fd)
{
	t_light	*tmp;

	if (e->scene->nb_lights > 0 && (e->scene->dir || e->scene->spot))
	{
		print_tag_tofile("lights", TAG_OPEN_ENDL, 1, fd);
		tmp = lights;
		while (tmp != NULL)
		{
			if (tmp->type == DIR && e->scene->dir == ACTIVE)
				print_dirlight_tofile(tmp, fd);
			else if (tmp->type == SPOT && e->scene->spot == ACTIVE)
				print_spotlight_tofile(tmp, fd);
			tmp = tmp->next;
		}
		print_tag_tofile("lights", TAG_CLOSE, 1, fd);
	}
}
