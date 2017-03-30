/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <mmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 05:53:22 by mmorice           #+#    #+#             */
/*   Updated: 2017/03/30 19:12:48 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			parse_scenes(t_env *e, char **array)
{
	// char	*aa;

	e->scene = new_scene(new_color(get_color(e, array, "background", "scene")),
	new_camera(get_vector(array, "pos", "camera"),
	get_vector(array, "look_at", "camera")));
	e->scene->amb_intensity = get_nbr(array, "amb_intensity", "scene");
	e->scene->amb_color = new_color(get_color(e, array, "amb_color", "scene"));
	e->scene->effect = get_effect(e, array, "effect", "scene");
	// aa = between_tags(&array[tag_present(array, "scene", "open") + 1],
	// "antialiasing", tag_present(array, "scene", "close") - 1);
	// if (!(ft_strcmp(aa, "ACTIVE")))
	// e->scene->aa = ACTIVE_AA;
}

void			parse_objects(t_env *e, char **array)
{
	int			start;
	int			end;

	start = tag_present(array, "objects", "open") + 1;
	end = tag_present(array, "objects", "close") - 1;
	tag_present(&array[start], "object", "open");
	tag_present(&array[start], "object", "close");
	while (start <= end)
	{
		if (ft_strstr(array[start], "<object>"))
		{
			create_object(e, &array[start]);
			tag_present(&array[start], "object", "close");
		}
		start++;
	}
	(void)*e;
}

void			parse_lights(t_env *e, char **array)
{
	int			start;
	int			end;

	start = tag_present(array, "lights", "open") + 1;
	end = tag_present(array, "lights", "close") - 1;
	tag_present(&array[start], "light", "open");
	tag_present(&array[start], "light", "close");
	while (start <= end)
	{
		if (ft_strstr(array[start], "<light>"))
		{
			create_light(e, &array[start]);
			tag_present(&array[start], "light", "close");
		}
		start++;
	}
}

void			parse_xml_file(t_env *e, char **array)
{
	int			i;

	i = 0;
	parse_scenes(e, array);
	parse_objects(e, array);
	parse_lights(e, array);
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
