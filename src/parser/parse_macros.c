/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_macros.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:10:18 by vchaillo          #+#    #+#             */
/*   Updated: 2017/04/01 23:27:37 by valentinchaillou89###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int			find_start(char **array, char *str)
{
	int				start;

	start = 0;
	while (array[start])
	{
		if (ft_strstr(array[start], str))
			break ;
		start++;
	}
	return (start + 2);
}

static int			get_nb_macros(char **array, int start)
{
	int				nb_macros;

	nb_macros = 0;
	while (array[start])
	{
		if (ft_strstr(array[start], "*/"))
			break ;
		if (ft_strstr(array[start], "# define"))
			nb_macros++;
		start++;
	}
	return (nb_macros);
}

t_macro_array		create_macros_array_case(char *macro, char *str)
{
	t_macro_array	macro_case;
	char			**array;

	array = ft_strsplit(&macro[9], ' ');
	if (!(macro_case.define = ft_strdup(array[0])))
		print_error(MALLOC_ERROR);
	if (ft_strcmp(str, "colors defines"))
		macro_case.value = ft_atoi_base(array[1], 10);
	else
		macro_case.value = ft_atoi_base(array[1] + 2, 16);
	free(array[0]);
	free(array[1]);
	free(array[2]);
	free(array);
	return (macro_case);
}

t_macro_array		*create_macros_array(char **array, char *str)
{
	int				start;
	int				nb_macros;
	int				i;
	t_macro_array	*macro_array;

	macro_array = NULL;
	start = find_start(array, str);
	nb_macros = get_nb_macros(array, start);
	if (!(macro_array = (t_macro_array *)malloc(sizeof(t_macro_array)
		* (nb_macros + 1))))
		print_error(MALLOC_ERROR);
	i = 0;
	macro_array[nb_macros].define = "end";
	while (nb_macros > 0)
	{
		if (ft_strstr(array[start], "# define"))
		{
			macro_array[i] = create_macros_array_case(array[start], str);
			nb_macros--;
			i++;
		}
		start++;
	}
	return (macro_array);
}

t_macros			create_macros_arrays(void)
{
	t_macros		macros;
	char			**file_colors;
	char			**file_materials;
	char			**file_macros;

	file_colors = get_tab("inc/colors.h");
	macros.colors = create_macros_array(file_colors, "colors defines");
	file_materials = get_tab("inc/materials.h");
	macros.materials = create_macros_array(file_materials, "materials defines");
	file_macros = get_tab("inc/macros.h");
	macros.lights = create_macros_array(file_macros, "lights defines");
	macros.objects = create_macros_array(file_macros, "objects defines");
	macros.effects = create_macros_array(file_macros, "effects defines");
	macros.plane_styles = create_macros_array(file_macros, "plane types defin");
	free_array(file_macros);
	free_array(file_materials);
	free_array(file_colors);
	return (macros);
}
