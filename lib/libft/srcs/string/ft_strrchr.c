/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:58:42 by vchaillo          #+#    #+#             */
/*   Updated: 2014/11/22 07:47:07 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	while (s[i] != (char)c)
	{
		i--;
		if (i < 0)
			return (NULL);
	}
	return (char *)(&(s[i]));
}
