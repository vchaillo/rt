/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 16:33:55 by tlegroux          #+#    #+#             */
/*   Updated: 2017/01/05 14:35:52 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	if (!(node = malloc(sizeof(t_list))))
		return (NULL);
	node->content = (void *)content;
	if (content)
		node->content_size = content_size;
	else
		node->content_size = 0;
	node->next = NULL;
	return (node);
}
