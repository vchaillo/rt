/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <mmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 05:53:22 by mmorice           #+#    #+#             */
/*   Updated: 2017/03/20 18:55:38 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				create_object(t_env *e, char **tab, int i, t_array t)
{
	int				color;
	int				type;
	int				material;

	type = get_value("<type>", tab, i, t);
	color = get_value("<color>", tab, i, t);
	material = get_value("<material>", tab, i, t);
	type == 0 ? add_object(e->scene, new_object(type,
		new_sphere(get_vect("<pos>", tab, i),
		get_nbr("<r>", tab, i)),
		new_color(color), new_material(material))) : NULL;
	type == 1 ? add_object(e->scene, new_object(type,
		new_plane(get_vect("<normal>", tab, i), 0,
		get_value("<style>", tab, i, t)),
		new_color(color), new_material(material))) : NULL;
	type == 2 ? add_object(e->scene, new_object(type,
		new_cylinder(get_vect("<axis>", tab, i),
		get_vect("<pos>", tab, i), get_nbr("<r>", tab, i)),
		new_color(color), new_material(material))) : NULL;
	type == 3 ? add_object(e->scene, new_object(type,
		new_cone(get_vect("<axis>", tab, i),
		get_vect("<apex>", tab, i), get_nbr("<angle>", tab, i)),
		new_color(color), new_material(material))) : NULL;
	return (++t.countobj);
}

int				create_light(t_env *e, char **tab, int i, t_array t)
{
	int				color;
	int				type;
	int				intensity;

	type = get_value("<type>", tab, i, t);
	color = get_value("<color>", tab, i, t);
	intensity = get_nbr("<intensity>", tab, i);
	add_light(e->scene, new_light(type, intensity,
	get_vect("<pos>", tab, i), new_color(color)));
	return (++t.countlight);
}

void			parse_xml_file(t_env *e, char **tab)
{
	int				i;
	t_array			t;

	i = 0;
	t.countlight = 0;
	t.countobj = 0;
	t.tab_color = get_tab("inc/colors.h");
	t.tab_material = get_tab("inc/materials.h");
	t.tab_macro = get_tab("inc/macros.h");
	e->scene = new_scene(new_color(get_value("<background>", tab, i, t)),
			new_camera(get_vect("<pos>", tab, i), get_vect("<dir>", tab, i)));
	e->scene->amb_intensity = get_nbr("<amb_intensity>", tab, i);
	e->scene->amb_color = new_color(get_value("<amb_color>", tab, i, t));
	while (tab[i])
	{
		if (ft_strstr(tab[i], "<object>"))
			t.countobj = create_object(e, tab, i, t);
		if (ft_strstr(tab[i], "<light>"))
			t.countlight = create_light(e, tab, i, t);
		i++;
	}
	if (t.countlight == 0 || t.countobj == 0)
		t.countlight == 0 ? print_error(LIGHT_ABSENT_ERROR) :
		print_error(OBJECT_ABSENT_ERROR);
}
