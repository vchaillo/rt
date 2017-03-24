/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:36:20 by valentin          #+#    #+#             */
/*   Updated: 2017/03/24 21:06:14 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			put_file_header(int fd)
{
	int				data[3];

	(void)(write(fd, "BM", 2) + 1);
	data[0] = (WIN_W * WIN_H);
	data[1] = 0;
	data[2] = 54;
	(void)(write(fd, (char *)data, 12) + 1);
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
	(void)(write(fd, (char *)data, 40) + 1);
}

void			export_image(t_env *e)
{
	int			fd;
	int			x;
	int			y;
	int			i;

	ft_putendl_color("Saving screenshot...", TERM_BOLD_BLACK);
	fd = create_file(e, IMAGE);
	put_file_header(fd);
	put_image_header(fd);
	y = WIN_H - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < WIN_W)
		{
			i = x * 4 + y * e->size;
			(void)(write(fd, (char *)&e->data[i], 3) + 1);
			x++;
		}
		y--;
	}
	ft_putendl_color(ft_strcat(get_file_name(e, IMAGE),
		" saved !\n"), TERM_BOLD_GREEN);
	close(fd);
}
