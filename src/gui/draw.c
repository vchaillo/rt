/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:05 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/22 06:07:06 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			fill_pixel(t_env *e, t_color color, int x, int y)
{
	int			i;

	i = x * 4 + y * e->size;
	e->data[i] = (color.b);
	e->data[i + 1] = (color.g);
	e->data[i + 2] = (color.r);
}

void			apply_color_to_image(t_env *e)
{
	int 		x;
	int 		y;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			if (e->scene->effect == NEGATIVE)
				e->scene->color_array[y][x] = negative_color(e->scene->color_array[y][x]);
			fill_pixel(e, e->scene->color_array[y][x], x, y);
		}
	}
}

void			update_image(t_env *e)
{
	clock_t 	begin;
	clock_t 	end;

	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, WIN_W, WIN_H);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->size), &(e->endian));
	begin = clock();
	draw(e);
	end = clock();
	e->frame_time = (float)(end - begin) / CLOCKS_PER_SEC;
	print_gui_output(e);
	print_cli_output(e);
}

void		join_environements(t_env *e, t_env e_tab[NUM_THREADS])
{
	int			x;
	int			y;

	y = -1;
	while (++y < WIN_H * e->scene->aa)
	{
		x = -1;
		while (++x < WIN_W * e->scene->aa)
			e->scene->color_array_aa[y][x] = e_tab[y % NUM_THREADS].scene->color_array_aa[y][x];
	}
}

void* perform_work( void* argument )
{
	int			x;
	int			y;
	t_color		color;
	t_env		*e;
	int			thread;

	e = ( (t_env* )argument );
	thread = e->thread;
	e->nb_cam_rays = WIN_W * WIN_H;
	e->nb_light_rays = 0;
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
	return NULL;
}

void	draw(t_env *e)
{
	t_env			e_tab[NUM_THREADS];

	pthread_t threads[NUM_THREADS];
	int result_code;
	unsigned index;

	// create all threads one by one
	for( index = 0; index < NUM_THREADS; ++index )
	{
		e_tab[ index ] = *e;
		e_tab[index].thread = index;
		// printf("In draw: creating thread %d\n", index);
		result_code = pthread_create( &threads[index], NULL, perform_work, &(e_tab[index]) );
		assert( !result_code );
	}

	// wait for each thread to complete
	for( index = 0; index < NUM_THREADS; ++index )
	{
		// block until thread 'index' completes
		result_code = pthread_join( threads[ index ], NULL );
		assert( !result_code );
		// printf( "In draw: thread %d has completed\n", index );
	}
	join_environements(e, e_tab);
	super_sampling(e);
	exposure(e->scene->color_array);
	apply_color_to_image(e);
	stereoscopy(e);
	e->nb_rays = e->nb_cam_rays + e->nb_light_rays;
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
