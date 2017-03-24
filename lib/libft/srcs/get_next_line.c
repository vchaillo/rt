/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <tlegroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 17:23:30 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/23 21:38:50 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*clean_realloc(char *s, size_t size)
{
	char	*d;

	if (!(d = malloc(size)))
		return (NULL);
	if (!s)
	{
		d[0] = '\0';
	}
	else
	{
		ft_strcpy(d, s);
		free(s);
	}
	return (d);
}

static int	concat_til_eol(const int fd, char **stack)
{
	char	buf[BUFF_SIZE + 1];
	char	*ptr;
	int		r;

	r = 1;
	buf[0] = '\0';
	while (r > 0 && !(ptr = ft_strchr(*stack, '\n')))
	{
		*stack = clean_realloc(*stack, ft_strlen(*stack) + BUFF_SIZE + 1);
		if (!(stack))
			return (-1);
		r = read(fd, buf, BUFF_SIZE);
		buf[r] = '\0';
		ft_strcat(*stack, buf);
	}
	return (r);
}

static void	shave_rest(char *stack, char **stat)
{
	char *ptr;

	ptr = ft_strchr(stack, '\n');
	if (!ptr)
	{
		*stat = NULL;
		return ;
	}
	else
	{
		*ptr = '\0';
		if (*(ptr + 1))
			*stat = ft_strdup(ptr + 1);
	}
}

static char	**get_fd_stat(const int fd, t_list **list)
{
	t_list		*cur;
	t_fddata	*data;

	cur = *list;
	while (cur)
	{
		data = (t_fddata*)cur->content;
		if (data->fd == fd)
		{
			return (&(data->stat));
		}
		else
			cur = cur->next;
	}
	if (!(data = malloc(sizeof(t_fddata))))
		return (NULL);
	data->fd = fd;
	data->stat = NULL;
	ft_lstadd(list, ft_lstnew(data, sizeof(t_fddata)));
	return (&(data->stat));
}

int			get_next_line(const int fd, char **s)
{
	static t_list	*list;
	char			**stat;
	char			*stack;
	int				r;

	if (fd < 0 || !s)
		return (-1);
	if (!(stat = get_fd_stat(fd, &list)))
		return (-1);
	if (*stat)
	{
		stack = *stat;
		*stat = NULL;
	}
	else
		stack = NULL;
	if ((r = concat_til_eol(fd, &stack)) == -1)
		return (-1);
	shave_rest(stack, stat);
	*s = stack;
	if (r == 0 && (ft_strlen(*stat) + ft_strlen(stack)) == 0)
		return (0);
	else
		return (1);
}
