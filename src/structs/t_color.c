/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:34 by vchaillo          #+#    #+#             */
/*   Updated: 2016/11/22 01:04:21 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color			new_color(int color)
{
	t_color		new_color;

	new_color.b = (color % 256);
	color /= 256;
	new_color.g = (color % 256);
	color /= 256;
	new_color.r = (color % 256);
	return (new_color);
}
