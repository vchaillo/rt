/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:41:17 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/20 18:46:32 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char			**get_tab(char *file)
{
	int			fd;
	char		*tmp;
	char		*tmp2;
	char		**tab;
	char		*line;

	line = NULL;
	tmp = NULL;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		tmp2 = tmp;
		tmp = ft_strjoin(tmp, line);
		free(tmp2);
		tmp2 = tmp;
		tmp = ft_strjoin(tmp, "\n");
		free(tmp2);
		free(line);
	}
	close(fd);
	(tmp == NULL) ? print_error(OPEN_ERROR) : NULL;
	tab = ft_strsplit(tmp, '\n');
	return (tab);
}

int				hextoint(const char *str)
{
	int			i;
	int			value;
	int			count;

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

int				get_value(char *str, char **tab, int x, t_array t)
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

int				get_nbr(char *str, char **tab, int x)
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

t_vector		get_vect(char *str, char **tab, int x)
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
