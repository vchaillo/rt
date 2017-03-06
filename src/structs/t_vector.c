/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:25:07 by vchaillo          #+#    #+#             */
/*   Updated: 2016/11/24 06:12:29 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector		new_vector(float x, float y, float z)
{
	t_vector		vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}
