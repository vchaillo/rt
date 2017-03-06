/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 01:05:12 by vchaillo          #+#    #+#             */
/*   Updated: 2014/11/22 07:56:28 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next_elem;

	if (alst && *alst && *del)
	{
		while (*alst)
		{
			next_elem = *alst;
			ft_lstdelone(alst, del);
			free(*alst);
			*alst = next_elem->next;
		}
		*alst = NULL;
	}
}
