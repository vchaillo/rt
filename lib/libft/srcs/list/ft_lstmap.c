/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 04:21:53 by vchaillo          #+#    #+#             */
/*   Updated: 2014/11/22 07:57:46 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*origin;
	t_list	*prev;

	if (lst && *f)
	{
		new = (*f)(lst);
		prev = new;
		origin = new;
		lst = lst->next;
		while (lst)
		{
			new = (*f)(lst);
			if (new == NULL)
				return (NULL);
			prev->next = new;
			prev = new;
			lst = lst->next;
		}
		new->next = NULL;
		return (origin);
	}
	return (NULL);
}
