/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 23:47:56 by valentin          #+#    #+#             */
/*   Updated: 2017/03/12 23:47:57 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFLECTION_H
# define REFLECTION_H

/*
**	Taking a ray and a light object, return reflection using phong model.
*/

t_color			phong(t_env *e, t_light *light, t_ray *vray);
/*
** Used by phong model:
*/
t_color			specular(t_ray *v_ray, t_light *spot, t_ray *l_ray);
t_color			diffuse(t_env *e, t_hitpoint hitpoint, t_light *l, t_ray *ray);

t_color			reflection(t_env *e, t_ray *ray);
void			reflected_ray(t_ray *ray);


#endif
