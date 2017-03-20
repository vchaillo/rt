/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:31:16 by valentin          #+#    #+#             */
/*   Updated: 2017/03/20 18:49:19 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				parse_arguments(int ac, char **av, t_env *e)
{
	t_parser		p;

	p.i = 0;
	while (++p.i < ac)
	{
		if (ft_strcmp(av[p.i], "-V") == 0)
			e->verbose = MIN_VERBOSE;
		else if (ft_strcmp(av[p.i], "-v") == 0)
			e->verbose = FULL_VERBOSE;
		else if (ft_strcmp(av[p.i], "-s1") == 0)
			load_scene(SCENE_1, e);
		else if (ft_strcmp(av[p.i], "-s2") == 0)
			load_scene(SCENE_2, e);
		else if (ft_strcmp(av[p.i], "-s3") == 0)
			load_scene(SCENE_3, e);
		else if (ft_strcmp(av[p.i], "-s4") == 0)
			load_scene(SCENE_4, e);
		else if (ft_strcmp(av[p.i], "-s5") == 0)
			load_scene(SCENE_5, e);
		else
		{
			p.tab = (get_tab(av[1]));
			parse_xml_file(e, p.tab);
		}
	}
}
