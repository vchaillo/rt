/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:41:17 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/24 02:00:00 by vchaillo         ###   ########.fr       */
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
	free(tmp);
	return (tab);
}

float			get_nbr(char **array, char *tag, char *tagg)
{
	float		abc;
	char		*str;

	str = between_tags(&array[tag_present(array, tagg, "open") + 1],
	tag, tag_present(array, tagg, "close") - 1);
	abc = ft_atof(&str[0]);
	printf("before : %s\n", &str[0]);
	printf("after : %f\n", abc);
	return (abc);
}

t_vector		get_vector(char **array, char *tag, char *tagg)
{
	t_vector	vector;
	int			i;
	float		abc[3];
	char		*str;

	i = 0;
	ft_bzero(abc, 3 * sizeof(float));
	str = between_tags(&array[tag_present(array, tagg, "open") + 1],
	tag, tag_present(array, tagg, "close") - 1);
	abc[0] = ft_atof(&str[i]);
	while (str[i] != ',')
		i++;
	i++;
	abc[1] = ft_atof(&str[i++]);
	while (str[i] != ',')
		i++;
	abc[2] = ft_atof(&str[i + 2]);
	vector = new_vector(abc[0], abc[1], abc[2]);
	free(str);
	return (vector);
}

char			*between_tags(char **array, char *tag, int end)
{
	int			open_close[2];
	int			i_mlen[2];
	char		*str;

	ft_bzero(i_mlen, 2 * sizeof(int));
	open_close[0] = tag_present(array, tag, "open");
	open_close[1] = tag_present(array, tag, "close");
	if (open_close[0] != open_close[1] || open_close[0] > end)
		print_parser_error(tag, MISSING_TAG_ERROR, 0);
	while (array[open_close[0]][i_mlen[0]] != '>')
		i_mlen[0]++;
	while (array[open_close[0]][i_mlen[0]] != '<')
	{
		i_mlen[1]++;
		i_mlen[0]++;
	}
	if (!(str = (char *)malloc(sizeof(char) * i_mlen[1])))
		print_error(MALLOC_ERROR);
	i_mlen[0] -= (i_mlen[1] - 1);
	i_mlen[1] = 0;
	while (array[open_close[0]][i_mlen[0]] != '<')
		str[i_mlen[1]++] = array[open_close[0]][i_mlen[0]++];
	str[i_mlen[1]] = 0;
	return (str);
}

int				tag_present(char **array, char *tag, char *str)
{
	int			i;
	char		*tagg;

	i = 0;
	if (ft_strcmp("close", str) == 0)
		tag = ft_strjoin("</", tag);
	else
		tag = ft_strjoin("<", tag);
	tagg = tag;
	tag = ft_strjoin(tag, ">");
	free(tagg);
	while (array[i])
	{
		if (ft_strstr(array[i], tag))
		{
			free(tag);
			return (i);
		}
		i++;
	}
	print_parser_error(tag, MISSING_TAG_ERROR, 0);
	return (0);
}
