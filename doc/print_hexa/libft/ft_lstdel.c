/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 16:49:44 by tlegroux          #+#    #+#             */
/*   Updated: 2017/01/05 14:29:08 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;
	t_list	*next;

	node = *alst;
	if (node)
		next = node->next;
	else
		return ;
	while (next)
	{
		next = node->next;
		(*del)(node->content, node->content_size);
		free(node);
		node = next;
	}
	*alst = NULL;
}
