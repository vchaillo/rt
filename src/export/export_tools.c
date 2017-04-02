/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 07:17:32 by vchaillo          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2017/04/01 21:19:34 by valentinchaillou ###   ########.fr       */
=======
/*   Updated: 2017/04/02 00:49:15 by valentinchaillou89###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			print_tag_tofile(char *tag, int type, int tabs, int fd)
{
	while (tabs-- > 0)
		ft_putchar_fd('\t', fd);
	if (type == TAG_OPEN || type == TAG_OPEN_ENDL)
		ft_putstr_fd("<", fd);
	else
		ft_putstr_fd("</", fd);
	ft_putstr_fd(tag, fd);
	ft_putstr_fd(">", fd);
	if (type == TAG_CLOSE || type == TAG_OPEN_ENDL)
		ft_putstr_fd("\n", fd);
}

void			print_vector_tofile(t_vector v, char *name, int tabs, int fd)
{
	print_tag_tofile(name, TAG_OPEN, tabs, fd);
	ft_putfloat_fd(v.x, 3, fd);
	ft_putstr_fd(", ", fd);
	ft_putfloat_fd(v.y, 3, fd);
	ft_putstr_fd(", ", fd);
	ft_putfloat_fd(v.z, 3, fd);
	print_tag_tofile(name, TAG_CLOSE, 0, fd);
}

void			print_color_tofile(t_env *e, t_color c, int fd)
{
	int			hexcolor;
	int			i;

	i = 0;
	hexcolor = (((int)(c.r) & 0xff) << 16)
		+ (((int)(c.g) & 0xff) << 8)
		+ ((int)(c.b) & 0xff);
	while (ft_strcmp(e->macros.colors[i].define, "end"))
	{
		if (hexcolor == e->macros.colors[i].value)
		{
			ft_putstr_fd(e->macros.colors[i].define, fd);
			return ;
		}
		i++;
	}
}
