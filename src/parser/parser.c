/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 05:53:22 by mmorice           #+#    #+#             */
/*   Updated: 2017/03/17 07:27:33 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char		**get_tab(char *file)
{
	int		fd;
	char	*tmp;
	char	*tmp2;
	char	**tab;
	char	*line;

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
