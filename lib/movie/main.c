/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 23:07:13 by hbock             #+#    #+#             */
/*   Updated: 2017/03/27 23:07:15 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft/includes/libft.h"
#include <sys/types.h>
// #include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

int			get_scenes(char **av, char **env)
{
	int		ret;
	int		fd;
	char	*line;

	if ((fd = open(av[1], O_RDWR)) == -1)
		return (-1);
	while ((ret = get_next_line(fd, &line)))
	{
		env[0] = ft_strjoin(env[0], line);
		free(line);
	}
	close(fd);
	if (ret == -1)
		return (-1);
	if ((fd = open(av[2], O_RDWR)) == -1)
		return (-1);
	while ((ret = get_next_line(fd, &line)))
	{
		env[1] = ft_strjoin(env[1], line);
		free(line);
	}
	close(fd);
	if (ret == -1)
		return (-1);
	return (0);
}

int			get_movie_properties(char **av, char **env)
{
	if ((env[2] = ft_strdup(av[3])) == NULL)
		return (-1);
	if ((env[3] = ft_strdup(av[4])) == NULL)
		return (-1);
	return (0);
}

t_vector	get_vector(char *search_in, char *to_search)
{
	char		*target;
	t_vector 	new;

	if ((target = ft_strstr(search_in, to_search)) == NULL)
		exit(0);
	target += 4;
	new.x = ft_atof(target);
	if ((target = ft_strstr(target, ",")) == NULL)
		exit(0);
	target += 1;
	new.y = ft_atof(target);
	if ((target = ft_strstr(target, ",")) == NULL)
		exit(0);
	target += 1;
	new.z = ft_atof(target);
	return (new);
}

int			test_print(t_vector starts[2], t_vector increments[2], char **env)
{
	int		i;
	int		i_max;

	i_max = (int)(1.0 * ft_atoi(env[2]) * ft_atof(env[3])) + 1;
	i = -1;
	while (++i < i_max)
		printf("pos: %f|%f|%f\n", starts[0].x + increments[0].x * i, starts[0].y + increments[0].y * i, starts[0].z + increments[0].z * i);
	i = -1;
	while (++i < i_max)
		printf("pos: %f|%f|%f\n", starts[1].x + increments[1].x * i, starts[1].y + increments[1].y * i, starts[1].z + increments[1].z * i);
	return (0);
}

int			create_inter_scenes(char **env)
{
	t_vector	starts[2];
	t_vector	ends[2];
	char		*target;
	t_vector	increments[2];

	if ((target = ft_strstr(env[0], "amera")) == NULL)
		return (-1);
	starts[0] = get_vector(target, "pos");
	starts[1] = get_vector(target, "dir");
	if ((target = ft_strstr(env[1], "amera")) == NULL)
		return (-1);
	ends[0] = get_vector(target, "pos");
	ends[1] = get_vector(target, "dir");
	increments[0].x = 1.0 * (ends[0].x - starts[0].x) / (1.0 * ft_atoi(env[2]) * ft_atof(env[3]));
	increments[0].y = 1.0 * (ends[0].y - starts[0].y) / (1.0 * ft_atoi(env[2]) * ft_atof(env[3]));
	increments[0].z = 1.0 * (ends[0].z - starts[0].z) / (1.0 * ft_atoi(env[2]) * ft_atof(env[3]));
	increments[1].x = 1.0 * (ends[1].x - starts[1].x) / (1.0 * ft_atoi(env[2]) * ft_atof(env[3]));
	increments[1].y = 1.0 * (ends[1].y - starts[1].y) / (1.0 * ft_atoi(env[2]) * ft_atof(env[3]));
	increments[1].z = 1.0 * (ends[1].z - starts[1].z) / (1.0 * ft_atoi(env[2]) * ft_atof(env[3]));
	test_print(starts, increments, env);
	return (0);
}

int			main(int ac, char **av)
{
	char	**env;

	if (ac < 5)
		return (0);
	if ((env = malloc(sizeof(char *) * 4)) == NULL)
		return (-1);
	if ((env[0] = malloc(sizeof(char) * 1)) == NULL)
		return (-1);
	if ((env[1] = malloc(sizeof(char) * 1)) == NULL)
		return (-1);
	if (get_scenes(av, env) == -1)
		return (-1);
	if (get_movie_properties(av, env) == -1)
		return (-1);
	create_inter_scenes(env);
	// printf("%d\n", ft_atoi(env[2]));
	// printf("%f\n", ft_atof(env[3]));
	return (0);
}
