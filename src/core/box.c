/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 07:55:18 by hbock             #+#    #+#             */
/*   Updated: 2017/03/14 07:55:18 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector            ray_coord_modif(t_ray ray, t_vec trans, t_vec rotxyz)
{
    t_vector        new;

    new.d = vector_rot_x(ray->d, -rotxyz.x);
    new.d = vector_rot_y(ray->d, -rotxyz.y);
    new.d = vector_rot_z(ray->d, -rotxyz.z);
    new.o = vector_rot_x(ray->o, -rotxyz.x);
    new.o = vector_rot_y(ray->o, -rotxyz.y);
    new.o = vector_rot_z(ray->o, -rotxyz.z);
    new.o = vector_sub(ray->o, trans);
    return (new);
}

float           hit_box(t_box *box, t_ray *ray)
{
    float       tmin;
    float       tmax;
    t_vector    rot_ray;

    rot_ray = ray_coord_modif(ray, box->trans, box->rotxyz);
    tmin = 0;
    tmax = MAX_FLOAT;
}
