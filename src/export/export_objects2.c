/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_objects2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 05:01:05 by vchaillo          #+#    #+#             */
/*   Updated: 2017/04/01 21:50:36 by valentinchaillou ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			print_cone_tofile(t_cone *cone, int fd)
{
	print_tag_tofile("cone", TAG_OPEN_ENDL, 3, fd);
	print_vector_tofile(cone->axis, "axis", 4, fd);
	print_vector_tofile(cone->apex, "apex", 4, fd);
	print_tag_tofile("angle", TAG_OPEN, 4, fd);
	ft_putfloat_fd(cone->angle, 1, fd);
	print_tag_tofile("angle", TAG_CLOSE, 0, fd);
	print_tag_tofile("cone", TAG_CLOSE, 3, fd);
	print_tag_tofile("limits", TAG_OPEN_ENDL, 3, fd);
	print_vector_tofile(cone->limit_min, "min", 4, fd);
	print_vector_tofile(cone->limit_max, "max", 4, fd);
	print_tag_tofile("limits", TAG_CLOSE, 3, fd);
}

void			print_tore_tofile(t_tore *tore, int fd)
{
	print_tag_tofile("tore", TAG_OPEN_ENDL, 3, fd);
	print_vector_tofile(tore->pos, "pos", 4, fd);
	print_tag_tofile("little_radius", TAG_OPEN, 4, fd);
	ft_putfloat_fd(tore->r, 1, fd);
	print_tag_tofile("little_radius", TAG_CLOSE, 0, fd);
	print_tag_tofile("big_radius", TAG_OPEN, 4, fd);
	ft_putfloat_fd(tore->big_r, 1, fd);
	print_tag_tofile("big_radius", TAG_CLOSE, 0, fd);
	print_tag_tofile("tore", TAG_CLOSE, 3, fd);
	print_tag_tofile("limits", TAG_OPEN_ENDL, 3, fd);
	print_vector_tofile(tore->limit_min, "min", 4, fd);
	print_vector_tofile(tore->limit_max, "max", 4, fd);
	print_tag_tofile("limits", TAG_CLOSE, 3, fd);
}

void			print_boloid_tofile(t_boloid *boloid, int fd)
{
	print_tag_tofile("boloid", TAG_OPEN_ENDL, 3, fd);
	print_vector_tofile(boloid->pos, "pos", 4, fd);
	print_tag_tofile("sign", TAG_OPEN, 4, fd);
	ft_putfloat_fd(boloid->sign, 1, fd);
	print_tag_tofile("sign", TAG_CLOSE, 0, fd);
	print_tag_tofile("abc", TAG_OPEN, 4, fd);
	ft_putfloat_fd(boloid->a, 1, fd);
	ft_putstr_fd(", ", fd);
	ft_putfloat_fd(boloid->b, 1, fd);
	ft_putstr_fd(", ", fd);
	ft_putfloat_fd(boloid->c, 1, fd);
	print_tag_tofile("abc", TAG_CLOSE, 0, fd);
	print_tag_tofile("boloid", TAG_CLOSE, 3, fd);
	print_tag_tofile("limits", TAG_OPEN_ENDL, 3, fd);
	print_vector_tofile(boloid->limit_min, "min", 4, fd);
	print_vector_tofile(boloid->limit_max, "max", 4, fd);
	print_tag_tofile("limits", TAG_CLOSE, 3, fd);
}

void			print_box_tofile(t_box *box, int fd)
{
	print_tag_tofile("box", TAG_OPEN_ENDL, 3, fd);
	print_vector_tofile(box->corner_min, "corner", 4, fd);
	print_vector_tofile(box->rotxyz, "rotxyz", 4, fd);
	print_vector_tofile(box->trans, "translation", 4, fd);
	print_tag_tofile("box", TAG_CLOSE, 3, fd);
}

void			print_disc_tofile(t_disc *disc, int fd)
{
	print_tag_tofile("disc", TAG_OPEN_ENDL, 3, fd);
	print_vector_tofile(disc->pos, "pos", 4, fd);
	print_vector_tofile(disc->rotxyz, "rotxyz", 4, fd);
	print_tag_tofile("little_radius", TAG_OPEN, 4, fd);
	ft_putfloat_fd(disc->r_min, 1, fd);
	print_tag_tofile("little_radius", TAG_CLOSE, 0, fd);
	print_tag_tofile("big_radius", TAG_OPEN, 4, fd);
	ft_putfloat_fd(disc->r_max, 1, fd);
	print_tag_tofile("big_radius", TAG_CLOSE, 0, fd);
	print_tag_tofile("disc", TAG_CLOSE, 3, fd);
}
