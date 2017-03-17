/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 23:57:59 by mmorice           #+#    #+#             */
/*   Updated: 2016/11/06 21:08:16 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_len_malloc(char const *s, char c)
{
	int		i;
	int		cm;

	i = 0;
	cm = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			cm++;
		}
	}
	return (cm);
}

static char	*ft_word(char *tab, char const *s, int i, int g)
{
	int		c;
	int		y;

	c = 0;
	y = 0;
	while (c < i)
	{
		tab[y] = s[g + c];
		c++;
		y++;
	}
	tab[y] = '\0';
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		y;
	int		i;
	int		v;
	char	**tab;

	y = 0;
	v = 0;
	if (!s || !(tab = (char **)malloc(sizeof(char *) * (ft_len_malloc(s, c)))))
		return (NULL);
	while (s[y] != '\0')
	{
		while (!(i = 0) && s[y] == c)
			y++;
		while (s[y] && s[y] != c)
		{
			y++;
			i++;
		}
		if (!(tab[v] = (char *)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		if (i != 0)
			ft_word(tab[v++], s, i, y - i);
	}
	tab[v] = 0;
	return (tab);
}
