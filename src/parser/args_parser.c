/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:31:16 by valentin          #+#    #+#             */
/*   Updated: 2017/03/17 12:29:45 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			parse_arguments(int ac, char **av, t_env *e)
{
	int			i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-v") == 0)
			e->verbose = VERBOSE;
		else if (ft_strcmp(av[i], "-s1") == 0)
			load_scene(SCENE_1, e);
		else if (ft_strcmp(av[i], "-s2") == 0)
			load_scene(SCENE_2, e);
		else if (ft_strcmp(av[i], "-s3") == 0)
			load_scene(SCENE_3, e);
		else if (ft_strcmp(av[i], "-s4") == 0)
			load_scene(SCENE_4, e);
		else if (ft_strcmp(av[i], "-s5") == 0)
			load_scene(SCENE_5, e);
		else if (ft_strcmp(av[i], "-s6") == 0)
			load_scene(SCENE_6, e);
		else if (ft_strcmp(av[i], "-s7") == 0)
			load_scene(SCENE_7, e);
		else if (ft_strcmp(av[i], "-s8") == 0)
			load_scene(SCENE_8, e);
		else
			print_error(ARG_ERROR);
		i++;
	}
}
