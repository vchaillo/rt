/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_lights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 09:12:27 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/30 17:10:30 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			print_light_tofile(t_env *e, t_light *light, int fd)
{
	print_tag_tofile("light", TAG_OPEN_ENDL, 2, fd);
	print_tag_tofile("type", TAG_OPEN, 3, fd);
	ft_putstr_fd(e->macros.lights[light->type].define, fd);
	print_tag_tofile("type", TAG_CLOSE, 0, fd);
	print_tag_tofile("intensity", TAG_OPEN, 3, fd);
	dprintf(fd, "%.1f", light->intensity);
	print_tag_tofile("intensity", TAG_CLOSE, 0, fd);
	print_tag_tofile("color", TAG_OPEN, 3, fd);
	print_color_tofile(e, light->color, fd);
	print_tag_tofile("color", TAG_CLOSE, 0, fd);
	if (light->type == LDIR)
		print_vector_tofile(light->dir, "vector", 3, fd);
	else
		print_vector_tofile(light->pos, "vector", 3, fd);
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
			if (tmp->type == LDIR && e->scene->dir == ACTIVE)
				print_light_tofile(e, tmp, fd);
			else if (tmp->type == LSPOT && e->scene->spot == ACTIVE)
				print_light_tofile(e, tmp, fd);
			tmp = tmp->next;
		}
		print_tag_tofile("lights", TAG_CLOSE, 1, fd);
	}
}
