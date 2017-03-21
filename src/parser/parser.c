/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <mmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 05:53:22 by mmorice           #+#    #+#             */
/*   Updated: 2017/03/21 09:55:27 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// int				create_object(t_env *e, char **tab, int i, t_array t)
// {
// 	int				color;
// 	int				type;
// 	int				material;
//
// 	type = get_value(e, ("<type>", tab, i, t);
// 	color = get_value(e, ("<color>", tab, i, t);
// 	material = get_value(e, ("<material>", tab, i, t);
// 	type == 0 ? add_object(e->scene, new_object(type,
// 		new_sphere(get_vect("<pos>", tab, i),
// 		get_nbr("<r>", tab, i)),
// 		new_color(color), new_material(material))) : NULL;
// 	type == 1 ? add_object(e->scene, new_object(type,
// 		new_plane(get_vect("<normal>", tab, i), 0,
// 		get_value(e, ("<style>", tab, i, t)),
// 		new_color(color), new_material(material))) : NULL;
// 	type == 2 ? add_object(e->scene, new_object(type,
// 		new_cylinder(get_vect("<axis>", tab, i),
// 		get_vect("<pos>", tab, i), get_nbr("<r>", tab, i)),
// 		new_color(color), new_material(material))) : NULL;
// 	type == 3 ? add_object(e->scene, new_object(type,
// 		new_cone(get_vect("<axis>", tab, i),
// 		get_vect("<apex>", tab, i), get_nbr("<angle>", tab, i)),
// 		new_color(color), new_material(material))) : NULL;
// 	return (++t.countobj);
// }
//
// int				create_light(t_env *e, char **tab, int i, t_array t)
// {
// 	int				color;
// 	int				type;
// 	int				intensity;
//
// 	type = get_value(e, ("<type>", tab, i, t);
// 	color = get_value(e, ("<color>", tab, i, t);
// 	intensity = get_nbr("<intensity>", tab, i);
// 	add_light(e->scene, new_light(type, intensity,
// 	get_vect("<pos>", tab, i), new_color(color)));
// 	return (++t.countlight);
// }

int				check_tag_present(char **array, char *tag)
{
	int			i;

	i = 0;
	while (array[i])
	{
		if (ft_strstr(array[i], tag))
			return (i);
		// printf("%s\n", array[i]);
		i++;
	}
	print_parser_error(tag, MISSING_TAG_ERROR, 0);
	return (0);
}

t_vector		parse_vector(char *line, char *tag)
{
	t_vector	vector;
	char		*open_tag;
	char		*close_tag;

	open_tag = ft_strcat(ft_strnew(ft_strlen(tag) + 2), "<");
	open_tag = ft_strcat(ft_strcat(open_tag, tag), ">");
	close_tag = ft_strcat(ft_strnew(ft_strlen(tag) + 3), "</");
	close_tag = ft_strcat(ft_strcat(close_tag, tag), ">");
	check_tag_present(&line, open_tag);
	check_tag_present(&line, close_tag);

	// int start = ft_strstr(line, open_tag) + ft_strlen(open_tag);

	// line[ft_strlen(tag) + 2];
	// vector = new_vector(x, y, z);
	(void)line;
	vector = new_vector(0, 0, 0);
	return (vector);
}

int				parse_camera(t_env *e, char **array)
{
	int			current_line;

	current_line = check_tag_present(array, "<camera>") + 1;
	check_tag_present(array, "</camera>");
	e->scene->camera->pos = parse_vector(array[current_line], "pos");
	e->scene->camera->dir = parse_vector(array[current_line], "dir");
	return (current_line);
}

void			parse_xml_file(t_env *e, char **array)
{
	int			current_line;
	int			countlight;
	int			countobj;

	countlight = 0;
	countobj = 0;
	current_line = 0;
	printf("%s\n", array[0]);

	check_tag_present(array, "<scene>");
	check_tag_present(array, "</scene>");
	parse_camera(e, array);
	// parse_objects();
	// parse_lights();
	// e->scene = new_scene(new_color(get_value(e, ("<background>", array, i)),
	// 	new_camera(get_vect("<pos>", array, i), get_vect("<dir>", array, i)));
	// e->scene->amb_intensity = get_nbr("<amb_intensity>", array, i);
	// e->scene->amb_color = new_color(get_value(e, ("<amb_color>", array, i));
	// while (array[i])
	// {
	// 	if (ft_strstr(array[i], "<object>"))
	// 		t.countobj = create_object(e, array, i, t);
	// 	if (ft_strstr(array[i], "<light>"))
	// 		t.countlight = create_light(e, array, i, t);
	// 	i++;
	// }
	// if (t.countlight == 0 || t.countobj == 0)
	// 	t.countlight == 0 ? print_error(LIGHT_ABSENT_ERROR) :
	// 	print_error(OBJECT_ABSENT_ERROR);
}
