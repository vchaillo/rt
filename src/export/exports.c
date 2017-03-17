/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exports.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 06:02:21 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/17 06:16:57 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char			*get_file_name(t_env *e, int type)
{
	time_t		seconds;
	struct tm	current_time;
	char		*str_time;

	if (!(str_time = (char *)malloc(sizeof(char) * 128)))
	{
		print_error(MALLOC_ERROR);
		if (e->scene)
			delete_scene(e->scene);
		exit(0);
	}
	time(&seconds);
	current_time = *localtime(&seconds);
	if (type == IMAGE)
		strftime(str_time, 128, "doc/screenshots/%Y%m%d_%H%M%S.bmp",
			&current_time);
	else
		strftime(str_time, 128, "doc/scenes/%Y%m%d_%H%M%S.xml",
			&current_time);
	return (str_time);
}

int				create_file(t_env *e, int type)
{
	int			fd;

	if ((fd = open(get_file_name(e, type),
		O_CREAT | O_TRUNC | O_WRONLY, 0666)) < 0)
	{
		print_error(OPEN_ERROR);
		if (e->scene)
			delete_scene(e->scene);
		exit(0);
	}
	return (fd);
}
