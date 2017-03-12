/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 23:47:33 by valentin          #+#    #+#             */
/*   Updated: 2017/03/12 23:47:34 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EFFECTS_H
# define EFFECTS_H

/*
**	Take in a color, apply effect(s), and return the new color.
*/
t_color			apply_effects(t_env *e, t_color color);
t_color			sepia(t_color color);
t_color			grayscale(t_color color);
float			cartoon(t_env *e, float dot);

#endif
