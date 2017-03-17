/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:31:16 by valentin          #+#    #+#             */
/*   Updated: 2017/03/17 10:17:33 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		hextoint(const char *str)
{
	int	i;
	int	value;
	int	count;

	value = 0;
	count = 0;
	i = 0;
	while (str[i] > '9' || str[i] < '0')
	{
		if (str[i] == 0)
			print_parser_error("", MISSING, 0);
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		value = value * 10;
		value = value + str[i] - 48;
		count++;
		i++;
	}
	return (value);
}

int		search_macro(char *str, char **tab)
{
	t_parser	p;
	char		*line;
	int			i;

	i = 0;
	p.i = 0;
	p.y = 0;
	line = NULL;
	while (tab[p.i] != 0)
	{
		if (ft_strstr(tab[p.i], str))
		{
			i = hextoint(tab[p.i]);
			return (i);
		}
		p.i++;
	}
	print_parser_error(str, NOT_DEFINE, p.i);
	free(str);
	return (0);
}

static int			get_value(char *str, char **tab, int x, t_array t)
{
	t_parser	p;
	int			i;

	i = 0;
	p.i = 0;
	p.y = 0;
	p.line = NULL;
	while (tab[x] != 0)
	{
		if (ft_strstr(tab[x], str))
		{
			while (tab[x][p.y] != '>')
				p.y++;
			p.fd = p.y;
			while (tab[x][++p.y] != '<' && (i = tab[x][p.y]) && i++)
				if (!(p.line = (char *)malloc(sizeof(char) * (i + 1))))
					p.y = p.fd;
			i = 0;
			while (tab[x][++p.fd] != '<')
				p.line[i++] = tab[x][p.fd];
			p.line[i] = 0;
			if (ft_strcmp(str, "<material>") == 0)
				return (search_macro(p.line, t.tab_material));
			else if (ft_strcmp(str, "<color>") == 0 ||
					ft_strcmp(str, "<background>") == 0 ||
					ft_strcmp(str, "<amb_color>") == 0)
				return (search_macro(p.line, t.tab_color));
			else
				return (search_macro(p.line, t.tab_macro));
			if (p.line[0] == 0)
				print_parser_error(str, IS_EMPTY, x);
		}
		if (ft_strstr(tab[x], "</object>"))
			print_parser_error(str, IS_MISSING, 0);
		x++;
	}
	print_parser_error(str, IS_MISSING, 0);
	return (0);
}

static int			get_nbr(char *str, char **tab, int x)
{
	while (tab[x])
	{
		if (ft_strstr(tab[x], str))
			return (hextoint(tab[x]));
		if (ft_strstr(tab[x], "</object>"))
			print_parser_error(str, IS_MISSING, 0);
		x++;
	}
	return (0);
}

static t_vector		get_vect(char *str, char **tab, int x)
{
	float		abc[3];
	t_parser	p;
	float		value;
	int			count;
	int			check;

	ft_bzero(abc, 3 * sizeof(float));
	count = 0;
	p.i = 1;
	while (tab[x])
	{
		if (ft_strstr(tab[x], str))
		{
			while (tab[x][p.y] != '>')
				p.y++;
			p.fd = p.y;
			while (tab[x][p.y] != '<')
			{
				value = 0;
				check = 0;
				if (tab[x][p.y] == '-')
					p.i = -1;
				while (tab[x][++p.y] <= '9' && tab[x][p.y] >= '0')
				{
					value = value * 10;
					value = value + tab[x][p.y] - 48;
					check++;
				}
				if (tab[x][p.y] == ',' || tab[x][p.y] == '<')
				{
					value = value * p.i;
					if (check == 0)
						print_parser_error(tab[x], THREE_ARGV_VEC, x);
					if (count == 0)
						abc[0] = value;
					if (count == 1)
						abc[1] = value;
					if (count == 2)
						abc[2] = value;
					p.i = 1;
					count++;
				}
			}
			(count != 3) ? print_parser_error(tab[x], THREE_ARGV_VEC, x) : NULL;
			return (new_vector(abc[0], abc[1], abc[2]));
		}
		if (ft_strstr(tab[x++], "</object>"))
			print_parser_error(str, IS_MISSING, 0);
	}
	return (new_vector(abc[0], abc[1], abc[2]));
}

static int			create_object(t_env *e, char **tab, int i, t_array t)
{
	int	color;
	int	type;
	int	material;

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

static int			create_light(t_env *e, char **tab, int i, t_array t)
{
	int	color;
	int	type;
	int	intensity;

	type = get_value("<type>", tab, i, t);
	color = get_value("<color>", tab, i, t);
	intensity = get_nbr("<intensity>", tab, i);
	add_light(e->scene, new_light(type, intensity,
	get_vect("<pos>", tab, i), new_color(color)));
	return (++t.countlight);
}

static void			send_value(t_env *e, char **tab)
{
	int		i;
	t_array	t;

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

void			parse_arguments(int ac, char **av, t_env *e)
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
			send_value(e, p.tab);
		}
	}
}
