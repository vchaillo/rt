/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 17:35:02 by hbock             #+#    #+#             */
/*   Updated: 2016/07/13 17:35:05 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_first_gnl(t_static_s *g, int fd)
{
	if (fd != g->first_gnl_use)
	{
		g->first_gnl_use = fd;
		ft_bzero(g->static_s, BUFF_SIZE + 1);
	}
}

static int	use_static_s(char *static_s, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (static_s[i] && static_s[i] != '\n')
		i++;
	if ((*line = ft_strnew(i)) == NULL)
		return (-1);
	i = -1;
	while (static_s[++i] && static_s[i] != '\n' && static_s[i] != EOF)
		(*line)[i] = static_s[i];
	if (static_s[i] == '\n')
	{
		if ((tmp = ft_strdup(static_s + i + 1)) == NULL)
			return (-1);
		ft_bzero(static_s, BUFF_SIZE + 1);
		ft_strcpy(static_s, tmp);
		ft_strdel(&tmp);
		return (1);
	}
	if (static_s[i] == EOF)
		return (0);
	ft_strclr(static_s);
	return (-2);
}

static int	realloc_line(char **line, int nread)
{
	int		len;
	char	*tmp;

	tmp = *line;
	len = (tmp) ? ft_strlen(tmp) + nread : nread;
	if ((*line = ft_strnew(len)) == NULL)
		return (-1);
	if (tmp)
		*line = ft_strcpy(*line, tmp);
	ft_strdel(&tmp);
	return (1);
}

static int	add_buff(char *buff, char *line, char *static_s)
{
	int	i;

	while (*line)
		line++;
	i = -1;
	while (buff[++i] && buff[i] != '\n' && buff[i] != EOF)
		line[i] = buff[i];
	if (buff[i] == '\n')
	{
		ft_strcpy(static_s, buff + i + 1);
		return (1);
	}
	if (buff[i] == EOF)
		return (-1);
	ft_bzero(buff, BUFF_SIZE + 1);
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	int					ret;
	char				buff[BUFF_SIZE + 1];
	static t_static_s	g;

	check_first_gnl(&g, fd);
	ft_bzero(buff, BUFF_SIZE + 1);
	if (line == NULL)
		return (-1);
	if ((ret = use_static_s(g.static_s, line)) > -2)
		return (ret);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (realloc_line(line, ret) == -1)
			return (-1);
		ret = add_buff(buff, *line, g.static_s);
		if (ret)
			break ;
	}
	if (!ret && *line && ft_strlen(*line))
		return (1);
	if (!ret)
		ft_strdel(line);
	return (ret);
}
