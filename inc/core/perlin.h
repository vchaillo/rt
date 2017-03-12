/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 23:47:49 by valentin          #+#    #+#             */
/*   Updated: 2017/03/12 23:47:50 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERLIN_H
# define PERLIN_H

unsigned int	permutation(int index);
float			perlin(t_vector pos, int resolution);
float			gradient(int i, int j);
float			noise(float x, float y, float res);
float			fade(float nb);

#endif
