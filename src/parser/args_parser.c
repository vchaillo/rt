/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:31:16 by valentin          #+#    #+#             */
/*   Updated: 2017/03/29 07:46:38 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			parse_scene_arguments(char *arg, t_env *e)
{
	if (ft_strcmp(arg, "-s1") == 0)
		load_scene(SCENE_1, e);
	else if (ft_strcmp(arg, "-s2") == 0)
		load_scene(SCENE_2, e);
	else if (ft_strcmp(arg, "-s3") == 0)
		load_scene(SCENE_3, e);
	else if (ft_strcmp(arg, "-s4") == 0)
		load_scene(SCENE_4, e);
	else if (ft_strcmp(arg, "-s5") == 0)
		load_scene(SCENE_5, e);
	else if (ft_strcmp(arg, "-s6") == 0)
		load_scene(SCENE_6, e);
	else if (ft_strcmp(arg, "-s7") == 0)
		load_scene(SCENE_7, e);
	else if (ft_strcmp(arg, "-s8") == 0)
		load_scene(SCENE_8, e);
	else if (ft_strcmp(arg, "-s9") == 0)
		load_scene(SCENE_9, e);
	else
		parse_xml_file(e, get_tab(arg));
}

void				parse_arguments(int ac, char **av, t_env *e)
{
	int				i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-v") == 0)
			e->verbose = VERBOSE;
		else if (ft_strcmp(av[i], "-gtk") == 0)
			e->graphic_library = GTK;
		else
			parse_scene_arguments(av[i], e);
		i++;
	}
}
