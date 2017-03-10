/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:02:13 by hbock             #+#    #+#             */
/*   Updated: 2016/05/13 16:02:13 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	j;

	if (!ft_strlen(little))
		return ((char*)big);
	i = -1;
	while (big[++i])
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] && big[i + j] && little[j] == big[i + j])
				j++;
			if (little[j] == 0)
				return ((char*)big + i);
		}
	}
	return (NULL);
}
