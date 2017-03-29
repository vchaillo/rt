/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:13 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/29 01:46:36 by valentinchaillou89###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		main(int ac, char **av)
{
	t_env	e;

	e.scene = NULL;
	e.graphic_library = MLX;
	e.macros = create_macros_arrays();
	load_scene(SCENE_1, &e);
	if (ac > 1)
		parse_arguments(ac, av, &e);
	if (e.graphic_library == MLX)
		start_mlx(&e);
	else
		start_gtk(&e);
	return (0);
}
