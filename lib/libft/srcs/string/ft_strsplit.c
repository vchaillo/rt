/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 23:30:17 by vchaillo          #+#    #+#             */
/*   Updated: 2014/11/22 07:55:34 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	get_word_len(char const *s, char c)
{
	size_t		word_len;

	word_len = 0;
	while (*s != c && *s != '\0')
	{
		word_len++;
		s++;
	}
	return (word_len);
}

static size_t	get_nb_words(char const *s, char c)
{
	size_t		nb_words;

	nb_words = 0;
	while (*s != '\0')
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			nb_words++;
		s++;
	}
	return (nb_words);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		nb_words;
	size_t		word_len;
	size_t		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	nb_words = get_nb_words(s, c);
	if (!(tab = malloc(sizeof(*tab) * (nb_words + 1))))
		return (NULL);
	while (i < nb_words && *s != '\0')
	{
		while (*s == c)
			s++;
		word_len = get_word_len(s, c);
		if (!(tab[i] = malloc(sizeof(tab[i]) * (word_len + 1))))
			return (NULL);
		ft_strncpy(tab[i], s, word_len);
		tab[i][word_len] = '\0';
		s = s + word_len;
		i++;
	}
	tab[i] = "\0";
	return (tab);
}
