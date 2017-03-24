/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:34 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/21 07:44:01 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
