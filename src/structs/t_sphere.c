/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sphere.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:25:01 by vchaillo          #+#    #+#             */
/*   Updated: 2017/01/10 14:36:38 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere		*new_sphere(float x, float y, float z, float r)
{
	t_sphere	*sphere;

	if (!(sphere = (t_sphere*)malloc(sizeof(t_sphere))))
		print_error(MALLOC_ERROR);
	sphere->pos = new_vector(x, y, z);
	sphere->r = r;
	return (sphere);
}

void			delete_sphere(t_sphere *sphere)
{
	free(sphere);
}
