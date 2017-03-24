/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <mmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 05:53:22 by mmorice           #+#    #+#             */
/*   Updated: 2017/03/24 01:45:42 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				create_object(t_env *e, char **tab)
{
	int				color;
	int				type;
	int				material;

	// temporary
	t_vector	limits[2];
	t_vector	axis;

	limits[0] = new_vector(0, 0, 0);
	limits[1] = new_vector(0, 0, 0);
	axis = new_vector(0, 1, 1);
	// temporary

	type = get_object(e, tab, "type", "object");
	color = get_color(e, tab, "color", "object");
	material = get_material(e, tab, "material", "object");
	type == SPHERE ? add_object(e->scene, new_object(type,
		new_sphere(get_vector(tab, "pos", "sphere"),
		get_nbr(tab, "r", "sphere"), axis, limits),
		new_color(color), new_material(material))) : NULL;
	type == PLANE ? add_object(e->scene, new_object(type,
		new_plane(get_vector(tab, "normal", "plane"),
		get_nbr(tab, "offset", "plane"), get_pstyle(e, tab, "style", "plane"), limits),
		new_color(color), new_material(material))) : NULL;
	type == CYLINDER ? add_object(e->scene, new_object(type,
		new_cylinder(get_vector(tab, "axis", "cylinder"),
		get_vector(tab, "pos", "cylinder"), get_nbr(tab, "r", "cylinder"), limits),
		new_color(color), new_material(material))) : NULL;
	type == CONE ? add_object(e->scene, new_object(type,
		new_cone(get_vector(tab, "axis", "cone"),
		get_vector(tab, "apex", "cone"), get_nbr(tab, "angle", "cone"), limits),
		new_color(color), new_material(material))) : NULL;
	return (0);
}

int				create_light(t_env *e, char **tab)
{
	int				color;
	int				type;
	int				intensity;

	type = get_light(e, tab, "type", "light");
	color = get_color(e, tab, "color", "light");
	intensity = 1;
	add_light(e->scene, new_light(type, intensity,
	get_vector(tab, "vector", "light"), new_color(color)));
	return (0);
}

int				get_object(t_env *e, char **array, char *tag, char *tagg)
{
	char		*str;
	int			start;
	int			end;
	int			i;

	i = 0;
	start = tag_present(array, tagg, "open") + 1;
	end = tag_present(array, tagg, "close") - 1;
	str = between_tags(&array[start], tag, end);
	while (ft_strcmp(e->macros.objects[i].define, "end"))
	{
		if (!(ft_strcmp(str, e->macros.objects[i].define)))
			return (e->macros.objects[i].value);
		i++;
	}
	print_parser_error(str, NOT_DEFINE_ERROR, 0);
	return (0);
}
