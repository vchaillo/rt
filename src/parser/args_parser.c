/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:31:16 by valentin          #+#    #+#             */
/*   Updated: 2017/01/10 14:34:48 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			parse_arguments(int ac, char **av, t_env *e)
{
	int			i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-V") == 0)
			e->verbose = MIN_VERBOSE;
		else if (ft_strcmp(av[i], "-v") == 0)
			e->verbose = FULL_VERBOSE;
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
		else
			print_error(ARG_ERROR);
		i++;
	}
}
