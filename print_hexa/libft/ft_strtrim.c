/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:06:58 by tlegroux          #+#    #+#             */
/*   Updated: 2013/12/01 14:27:01 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char const *end;

	if (!s)
		return (NULL);
	while ((*s == ' ') || (*s == '\n') || (*s == '\t'))
		s++;
	end = ft_strrchr(s, '\0');
	while (((*end == ' ') || (*end == '\n')
			|| (*end == '\t') || (*end == '\0')) && end > s)
		end--;
	return (ft_strndup(s, end - s + 1));
}
