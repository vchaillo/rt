/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 09:04:45 by tlegroux          #+#    #+#             */
/*   Updated: 2017/01/05 14:18:14 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

#define IS_SEPARATOR(x) (x == c)

static int	cut_word(char *str, char **tab, char c)
{
	int		i;

	i = 0;
	while (!IS_SEPARATOR(str[i]) && str[i] != '\0')
		i++;
	*tab = malloc((i + 1) * sizeof(char));
	ft_strncpy(*tab, str, i);
	return (i);
}

static int	wordcount(char *str, char c)
{
	int		i;
	int		wc;

	wc = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!IS_SEPARATOR(str[i])
			&& (IS_SEPARATOR(str[i + 1]) || str[i + 1] == '\0'))
			wc++;
		i++;
	}
	return (wc);
}

char		**ft_strsplit(char const *str, char c)
{
	char	**tab;
	int		i;
	int		w;

	i = 0;
	w = 0;
	if (!str)
		return (NULL);
	if (!(tab = malloc((wordcount((char *)str, c) + 1) * sizeof(char*))))
		return (NULL);
	while (str[i] != '\0')
	{
		if (!IS_SEPARATOR(str[i]))
		{
			i += cut_word((char *)&(str[i]), &(tab[w]), c) - 1;
			w++;
		}
		i++;
	}
	tab[w] = NULL;
	return (tab);
}
