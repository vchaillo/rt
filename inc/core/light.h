/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 23:47:38 by valentin          #+#    #+#             */
/*   Updated: 2017/03/12 23:47:41 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

int				is_in_shadow(t_object *objects, t_ray *ray, t_object *hit_obj);
t_color			illuminate(t_env *e, t_ray *ray);
void			exposure_correction(t_color **colors);

#endif
