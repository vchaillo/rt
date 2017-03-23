/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_macros.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <mmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 02:09:12 by mmorice           #+#    #+#             */
/*   Updated: 2017/03/23 06:24:31 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int					get_color(t_env *e, char **array, char *tag, char *tagg)
{
	char		*str;
	int			start;
	int			end;
	int			i;

	i = 0;
	start = tag_present(array, tagg, "open") + 1;
	end = tag_present(array, tagg, "close") - 1;
	str = between_tags(&array[start], tag, end);
	while (ft_strcmp(e->macros.colors[i].define, "end"))
	{
		if (!(ft_strcmp(str, e->macros.colors[i].define)))
			return (e->macros.colors[i].value);
		i++;
	}
	print_parser_error(str, NOT_DEFINE_ERROR, 0);
	return (0);
}

int					get_material(t_env *e, char **array, char *tag, char *tagg)
{
	char		*str;
	int			start;
	int			end;
	int			i;

	i = 0;
	start = tag_present(array, tagg, "open") + 1;
	end = tag_present(array, tagg, "close") - 1;
	str = between_tags(&array[start], tag, end);
	while (ft_strcmp(e->macros.materials[i].define, "end"))
	{
		if (!(ft_strcmp(str, e->macros.materials[i].define)))
			return (e->macros.materials[i].value);
		i++;
	}
	print_parser_error(str, NOT_DEFINE_ERROR, 0);
	return (0);
}

int					get_effect(t_env *e, char **array, char *tag, char *tagg)
{
	char		*str;
	int			start;
	int			end;
	int			i;

	i = 0;
	start = tag_present(array, tagg, "open") + 1;
	end = tag_present(array, tagg, "close") - 1;
	str = between_tags(&array[start], tag, end);
	while (ft_strcmp(e->macros.effects[i].define, "end"))
	{
		if (!(ft_strcmp(str, e->macros.effects[i].define)))
			return (e->macros.effects[i].value);
		i++;
	}
	print_parser_error(str, NOT_DEFINE_ERROR, 0);
	return (0);
}

int					get_light(t_env *e, char **array, char *tag, char *tagg)
{
	char		*str;
	int			start;
	int			end;
	int			i;

	i = 0;
	start = tag_present(array, tagg, "open") + 1;
	end = tag_present(array, tagg, "close") - 1;
	str = between_tags(&array[start], tag, end);
	while (ft_strcmp(e->macros.lights[i].define, "end"))
	{
		if (!(ft_strcmp(str, e->macros.lights[i].define)))
			return (e->macros.lights[i].value);
		i++;
	}
	print_parser_error(str, NOT_DEFINE_ERROR, 0);
	return (0);
}

int					get_pstyle(t_env *e, char **array, char *tag, char *tagg)
{
	char		*str;
	int			start;
	int			end;
	int			i;

	i = 0;
	start = tag_present(array, tagg, "open") + 1;
	end = tag_present(array, tagg, "close") - 1;
	str = between_tags(&array[start], tag, end);
	while (ft_strcmp(e->macros.plane_styles[i].define, "end"))
	{
		if (!(ft_strcmp(str, e->macros.plane_styles[i].define)))
			return (e->macros.plane_styles[i].value);
		i++;
	}
	print_parser_error(str, NOT_DEFINE_ERROR, 0);
	return (0);
}
