/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_macros.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:10:18 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/20 19:04:02 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				search_macro(char *str, char **tab)
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
	return (0);
}

t_macros		create_macros_arrays(t_env *e)
{
	t_macros	macros;
	char		**file_colors;
	char		**file_materials;
	char		**file_macros;

	(void)e;
	macros.macros_colors = NULL;
	file_colors = get_tab("inc/colors.h");
	file_materials = get_tab("inc/materials.h");
	file_macros = get_tab("inc/macros.h");
	return (macros);
}
