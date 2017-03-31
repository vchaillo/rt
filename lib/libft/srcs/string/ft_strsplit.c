/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 03:51:23 by valentin          #+#    #+#             */
/*   Updated: 2017/03/31 03:51:27 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_word(char const *s, char c)
{
	int	i;
	int	nb;
	int	is_new;

	nb = 0;
	i = -1;
	is_new = 1;
	while (s[++i])
	{
		if (is_new && s[i] != c)
		{
			is_new = 0;
			nb++;
		}
		else if (!is_new && s[i] == c)
			is_new = 1;
	}
	return (nb);
}

static char		*ret_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (ft_strsub(s, 0, i));
}

static int		check_full_same_char(char const *s, char c, char ***tab)
{
	int		i;

	i = -1;
	while (s[++i])
	{
		if (s[i] != c)
			return (1);
	}
	if (!(*tab = ft_memalloc(sizeof(*tab))))
		return (0);
	(*tab)[0] = NULL;
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nb_word;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (!check_full_same_char(s, c, &tab))
		return (tab);
	if ((nb_word = count_word(s, c)) == 0)
		return (NULL);
	if (!(tab = ft_memalloc(sizeof(*tab) * (nb_word + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < nb_word)
	{
		while (s[j] && s[j] == c)
			j++;
		tab[i] = ret_word(s + j, c);
		while (s[j] && s[j] != c)
			j++;
	}
	tab[i] = NULL;
	return (tab);
}
