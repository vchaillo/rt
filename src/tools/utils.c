/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:11:57 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/31 03:19:20 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float				pow_2(float nb)
{
	return (nb * nb);
}

void				ft_swapf(float *f1, float *f2)
{
	float			tmp;

	tmp = *f1;
	*f1 = *f2;
	*f2 = tmp;
}

void				free_array(char **array)
{
	int				i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

t_ray				ray_coord_modif(t_ray *ray, t_vector trans, t_vector rotxyz)
{
	t_ray			new;

	new.o = vector_sub(ray->o, trans);
	new.d = vector_rot_x(ray->d, -rotxyz.x);
	new.d = vector_rot_y(new.d, -rotxyz.y);
	new.d = vector_rot_z(new.d, -rotxyz.z);
	new.o = vector_rot_x(new.o, -rotxyz.x);
	new.o = vector_rot_y(new.o, -rotxyz.y);
	new.o = vector_rot_z(new.o, -rotxyz.z);
	return (new);
}
