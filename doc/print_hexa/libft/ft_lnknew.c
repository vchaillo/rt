/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnknew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 12:20:59 by tlegroux          #+#    #+#             */
/*   Updated: 2017/01/05 14:34:13 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_link		*ft_lnknew(void const *content, size_t content_size)
{
	t_link	*node;

	if (!(node = malloc(sizeof(t_link))))
		return (NULL);
	node->content = (void *)content;
	if (content)
		node->content_size = content_size;
	else
		node->content_size = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
