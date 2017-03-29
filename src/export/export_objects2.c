/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_objects2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 05:01:05 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/29 00:09:59 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			print_cone_tofile(t_cone *cone, int fd)
{
	print_tag_tofile("cone", TAG_OPEN_ENDL, 3, fd);
	print_vector_tofile(cone->axis, "axis", 4, fd);
	print_vector_tofile(cone->apex, "apex", 4, fd);
	print_tag_tofile("angle", TAG_OPEN, 4, fd);
	dprintf(fd, "%.1f", cone->angle);
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
	dprintf(fd, "%.1f", tore->r);
	print_tag_tofile("little_radius", TAG_CLOSE, 0, fd);
	print_tag_tofile("big_radius", TAG_OPEN, 4, fd);
	dprintf(fd, "%.1f", tore->big_r);
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
	dprintf(fd, "%.1f", boloid->sign);
	print_tag_tofile("sign", TAG_CLOSE, 0, fd);
	print_tag_tofile("abc", TAG_OPEN, 4, fd);
	dprintf(fd, "%.1f, ", boloid->a);
	dprintf(fd, "%.1f, ", boloid->b);
	dprintf(fd, "%.1f", boloid->c);
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
	dprintf(fd, "%.1f", disc->r_min);
	print_tag_tofile("little_radius", TAG_CLOSE, 0, fd);
	print_tag_tofile("big_radius", TAG_OPEN, 4, fd);
	dprintf(fd, "%.1f", disc->r_max);
	print_tag_tofile("big_radius", TAG_CLOSE, 0, fd);
	print_tag_tofile("disc", TAG_CLOSE, 3, fd);
}
