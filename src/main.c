/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:13 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/30 16:16:45 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		main(int ac, char **av)
{
	t_env	e;

	e.scene = NULL;
	e.macros = create_macros_arrays();
	load_scene(SCENE_1, &e);
	if (ac > 1)
		parse_arguments(ac, av, &e);
	start_mlx(&e);
	return (0);
}
