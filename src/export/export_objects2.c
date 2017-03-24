/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_objects2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 05:01:05 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/24 05:20:45 by vchaillo         ###   ########.fr       */
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
}

// void			print_tore_tofile(t_tore *tore, int fd)
// void			print_boloid_tofile(t_cone *cone, int fd)
// void			print_box_tofile(t_cone *cone, int fd)
// void			print_disc_tofile(t_cone *cone, int fd)
