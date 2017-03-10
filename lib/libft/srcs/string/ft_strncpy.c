/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:01:09 by hbock             #+#    #+#             */
/*   Updated: 2016/05/13 16:01:10 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	lsrc;

	i = -1;
	while (src[++i] && i < len)
		dst[i] = src[i];
	if ((lsrc = ft_strlen(src)) < len)
	{
		while (i < len)
			dst[i++] = 0;
	}
	return (dst);
}
