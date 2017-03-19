/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 23:47:46 by valentin          #+#    #+#             */
/*   Updated: 2017/03/12 23:47:47 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_H
# define NORMAL_H

t_vector		get_normal(t_ray *ray);
t_vector		get_normal_at_plane(t_ray *ray, t_plane *plane);
t_vector		get_normal_at_cylinder(t_ray *ray, t_cylinder *c);
t_vector		get_normal_at_cone(t_ray *ray, t_cone *cone);
t_vector		get_normal_at_tore(t_ray *ray, t_tore *tor);
t_vector		get_normal_at_boloid(t_ray *ray, t_boloid *boloid);

#endif
