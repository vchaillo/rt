/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithreading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:26:56 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/30 17:42:27 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			join_environements(t_env *e, t_env e_tab[NUM_THREADS])
{
	int			x;
	int			y;

	y = -1;
	while (++y < WIN_H * e->scene->aa)
	{
		x = -1;
		while (++x < WIN_W * e->scene->aa)
			e->scene->color_array_aa[y][x] =
				e_tab[y % NUM_THREADS].scene->color_array_aa[y][x];
	}
}

void			*perform_work(void *argument)
{
	int			x;
	int			y;
	t_color		color;
	t_env		*e;
	int			thread;

	e = ((t_env*)argument);
	thread = e->thread;
	y = 0;
	while (y < WIN_H * e->scene->aa)
	{
		x = 0;
		if ((y % NUM_THREADS) == thread)
		{
			while (x < WIN_W * e->scene->aa)
			{
				color = raytracer(e, x, y);
				color = apply_effects(e, color);
				e->scene->color_array_aa[y][x] = color;
				x++;
			}
		}
		y++;
	}
	return (NULL);
}

void			multithreading(t_env *e)
{
	t_env		e_tab[NUM_THREADS];
	pthread_t	threads[NUM_THREADS];
	int			result_code;
	unsigned	index;

	index = 0;
	while (index < NUM_THREADS)
	{
		e_tab[index] = *e;
		e_tab[index].thread = index;
		result_code = pthread_create(&threads[index], NULL,
									perform_work, &(e_tab[index]));
		assert(!result_code);
		++index;
	}
	index = 0;
	while (index < NUM_THREADS)
	{
		result_code = pthread_join(threads[index], NULL);
		assert(!result_code);
		++index;
	}
	join_environements(e, e_tab);
}
