/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 04:25:52 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/30 17:17:19 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			print_camera_tofile(t_camera *camera, int fd)
{
	print_tag_tofile("camera", TAG_OPEN_ENDL, 1, fd);
	print_vector_tofile(camera->pos, "pos", 2, fd);
	print_vector_tofile(camera->dir, "look_at", 2, fd);
	print_tag_tofile("camera", TAG_CLOSE, 1, fd);
}

static void			print_scene_tofile(t_env *e, t_scene *scene, int fd)
{
	print_tag_tofile("background", TAG_OPEN, 1, fd);
	print_color_tofile(e, scene->background_color, fd);
	print_tag_tofile("background", TAG_CLOSE, 0, fd);
	print_tag_tofile("amb_color", TAG_OPEN, 1, fd);
	print_color_tofile(e, scene->amb_color, fd);
	print_tag_tofile("amb_color", TAG_CLOSE, 0, fd);
	print_tag_tofile("amb_intensity", TAG_OPEN, 1, fd);
	dprintf(fd, "%.1f", scene->amb == ACTIVE ? scene->amb_intensity : 0);
	print_tag_tofile("amb_intensity", TAG_CLOSE, 0, fd);
	print_tag_tofile("antialiasing", TAG_OPEN, 1, fd);
	scene->aa == INACTIVE_AA ? ft_putstr_fd("INACTIVE_AA", fd) :
		ft_putstr_fd("ACTIVE_AA", fd);
	print_tag_tofile("antialiasing", TAG_CLOSE, 0, fd);
	print_tag_tofile("effect", TAG_OPEN, 1, fd);
	if (scene->effect == INACTIVE)
		ft_putstr_fd("INACTIVE", fd);
	else if (scene->effect == SEPIA)
		ft_putstr_fd("SEPIA", fd);
	else if (scene->effect == GRAYSCALE)
		ft_putstr_fd("GRAYSCALE", fd);
	else if (scene->effect == CARTOON)
		ft_putstr_fd("CARTOON", fd);
	else if (scene->effect == NEGATIVE)
		ft_putstr_fd("NEGATIVE", fd);
	else if (scene->effect == STEREO)
		ft_putstr_fd("STEREO", fd);
	print_tag_tofile("effect", TAG_CLOSE, 0, fd);
}

void				export_scene(t_env *e)
{
	int				fd;

	ft_putendl_color("Saving scene file...", TERM_BOLD_BLACK);
	fd = create_file(e, SCENE);
	print_tag_tofile("scene", TAG_OPEN_ENDL, 0, fd);
	print_camera_tofile(e->scene->camera, fd);
	print_scene_tofile(e, e->scene, fd);
	print_objects_tofile(e, fd);
	print_lights_tofile(e, e->scene->lights, fd);
	print_tag_tofile("scene", TAG_CLOSE, 0, fd);
	ft_putendl_color(ft_strcat(get_file_name(e, SCENE),
		" saved !\n"), TERM_BOLD_GREEN);
	close(fd);
}
