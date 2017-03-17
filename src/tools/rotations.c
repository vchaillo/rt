/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 01:20:22 by valentin          #+#    #+#             */
/*   Updated: 2017/03/17 01:51:20 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector		vector_rot_x(t_vector v, float angle)
{
	t_vector	vector;

	angle = M_PI * angle / 180;
	vector.x = v.x;
	vector.y = v.y * cos(angle) - v.z * sin(angle);
	vector.z = v.y * sin(angle) + v.z * cos(angle);
	return (vector);
}

t_vector		vector_rot_y(t_vector v, float angle)
{
	t_vector	vector;

	angle = M_PI * angle / 180;
	vector.x = v.x * cos(angle) + v.z * sin(angle);
	vector.y = v.y;
	vector.z = -v.x * sin(angle) + v.z * cos(angle);
	return (vector);
}

t_vector		vector_rot_z(t_vector v, float angle)
{
	t_vector	vector;

	angle = M_PI * angle / 180;
	vector.x = v.x * cos(angle) - v.y * sin(angle);
	vector.y = v.x * sin(angle) + v.y * cos(angle);
	vector.z = v.z;
	return (vector);
}

t_vector		vector_rot_axis(t_vector v, t_vector axis, float angle)
{
	t_vector	vector;
	float		c;
	float		s;

	angle = M_PI * angle / 180;
	c = cos(angle);
	s = sin(angle);
	vector.x = ((pow_2(axis.x) * (1 - c) + c) * v.x)
		+ ((axis.x * axis.y * (1 - c) - (axis.z * s)) * v.y)
		+ ((axis.x * axis.z * (1 - c) + (axis.y * s)) * v.z);
	vector.y = ((axis.x * axis.y * (1 - c) + (axis.z * s)) * v.x)
		+ ((pow_2(axis.y) * (1 - c) + c) * v.y)
		+ ((axis.y * axis.z * (1 - c) - (axis.x * s)) * v.z);
	vector.z = ((axis.x * axis.z * (1 - c) - (axis.y * s)) * v.x)
		+ ((axis.y * axis.z * (1 - c) + (axis.x * s)) * v.y)
		+ ((pow_2(axis.z) * (1 - c) + c) * v.z);
	return (normalize(vector));
}

t_vector	convert_to_rotated_coordinates(t_vector pos, t_vector axis)
{
	t_vector	pos2;
	t_vector	ret;

	pos2.x = pos.x;
	pos2.y = 0;
	pos2.z = 0;
	ret.x = dot_product(pos2, axis);
	pos2.x = 0;
	pos2.y = pos.y;
	ret.y = dot_product(pos2, axis);
	pos2.y = 0;
	pos2.z = pos.z;
	ret.z = dot_product(pos2, axis);
	return (ret);
}
