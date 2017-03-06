/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 08:14:44 by vchaillo          #+#    #+#             */
/*   Updated: 2017/02/23 04:29:34 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_realloc(int const fd, char **tmp, int *ret)
{
	char			*buffer;

	buffer = ft_strnew(BUFF_SIZE + 1);
	if ((*ret = read(fd, buffer, BUFF_SIZE)) == -1)
		return (-1);
	if (*tmp == '\0')
		*tmp = ft_strnew(0);
	buffer[*ret] = '\0';
	*tmp = ft_strjoin(*tmp, buffer);
	free(buffer);
	return (0);
}

static int	get_endl(char **tmp, char **line)
{
	char			*str;

	if ((str = ft_strchr(*tmp, '\n')))
	{
		*str = '\0';
		*line = ft_strdup(*tmp);
		ft_memmove(*tmp, str + 1, ft_strlen(str + 1) + 1);
		return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char		*tmp[1024];
	int				ret;

	if (!line || fd < 0)
		return (-1);
	ret = BUFF_SIZE;
	while (ret > 0 || ft_strlen(tmp[fd]))
	{
		if ((get_endl(&tmp[fd], line)) == 1)
			return (1);
		if (my_realloc(fd, &tmp[fd], &ret) == -1)
			return (-1);
		if (ret == 0 && ft_strlen(tmp[fd]))
		{
			*line = ft_strdup(tmp[fd]);
			ft_bzero(tmp[fd], ft_strlen(tmp[fd]));
			return (1);
		}
	}
	free(tmp[fd]);
	*tmp = NULL;
	return (0);
}
