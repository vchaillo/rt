/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnkaddlst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 12:28:26 by tlegroux          #+#    #+#             */
/*   Updated: 2013/12/01 19:26:43 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lnkaddlst(t_link **alst, t_link *new)
{
	t_link	*end;

	if (!(*alst))
	{
		*alst = new;
		(*alst)->prev = NULL;
	}
	else
	{
		end = *alst;
		while (end->next)
			end = end->next;
		new->prev = end;
	}
	new->next = NULL;
}
