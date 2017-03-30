/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:11:57 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/30 20:43:27 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float				pow_2(float nb)
{
	return (nb * nb);
}

void				ft_swapf(float *f1, float *f2)
{
	float			tmp;

	tmp = *f1;
	*f1 = *f2;
	*f2 = tmp;
}

void				free_array(char **array)
{
	int				i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}
