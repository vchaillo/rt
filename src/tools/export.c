/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:36:20 by valentin          #+#    #+#             */
/*   Updated: 2017/03/07 22:26:30 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char			*get_file_name(t_env *e, int type)
{
	time_t		seconds;
	struct tm	current_time;
	char 		*str_time;

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
		strftime(str_time, 128, "doc/screenshots/%Y%m%d_%H%M%S.jpg",
			&current_time);
	else
		strftime(str_time, 128, "doc/scenes/%Y%m%d_%H%M%S.scene",
			&current_time);
	return (str_time);
}

int				create_file(t_env *e)
{
	int			fd;

	if ((fd = open(get_file_name(e, IMAGE),
		O_CREAT | O_TRUNC | O_WRONLY, 0666)) < 0)
	{
		print_error(OPEN_ERROR);
		if (e->scene)
			delete_scene(e->scene);
		exit(0);
	}
	return (fd);
}

void			put_file_header(int fd)
{
	int				data[3];

	write(fd, "BM", 2);
	data[0] = (WIN_W * WIN_H);
	data[1] = 0;
	data[2] = 54;
	write(fd, (char *)data, 12);
}

void			put_image_header(int fd)
{
	int				data[10];

	data[0] = 40;
	data[1] = WIN_W;
	data[2] = WIN_H;
	data[3] = 1 + 24 * 256 * 256;
	data[4] = 0;
	data[5] = 0;
	data[6] = 0;
	data[7] = 0;
	data[8] = 0;
	data[9] = 0;
	write(fd, (char *)data, 40);
}

void			export_image(t_env *e)
{
	int			fd;
	int			x;
	int			y;
	int			i;

	ft_putendl_color("Saving screenshot...", TERM_BOLD_BLACK);
	fd = create_file(e);
	put_file_header(fd);
	put_image_header(fd);
	y = WIN_H;
	while (y > 0)
	{
		x = 0;
		while (x < WIN_W)
		{
			i = x * 4 + y * e->size;
			write(fd, (char *)&e->data[i], 3);
			x++;
		}
		y--;
	}
	ft_putendl_color(ft_strcat(get_file_name(e, IMAGE),
		" saved !"), TERM_BOLD_GREEN);
	close(fd);
}
