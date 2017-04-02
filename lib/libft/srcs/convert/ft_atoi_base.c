/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 22:28:14 by valentin          #+#    #+#             */
/*   Updated: 2017/04/02 15:24:14 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_result(const char *str, const unsigned int base, int i)
{
	int			result;

	result = 0;
	while (str[i])
	{
		result *= base;
		if (str[i] >= 48 && str[i] <= 57)
			result += str[i] - '0';
		else if ((str[i] >= 97 && str[i] <= 102)
			|| (str[i] >= 65 && str[i] <= 70))
		{
			result = str[i] == 'A' || str[i] == 'a' ? result + 10 : result;
			result = str[i] == 'B' || str[i] == 'b' ? result + 11 : result;
			result = str[i] == 'C' || str[i] == 'c' ? result + 12 : result;
			result = str[i] == 'D' || str[i] == 'd' ? result + 13 : result;
			result = str[i] == 'E' || str[i] == 'e' ? result + 14 : result;
			result = str[i] == 'F' || str[i] == 'f' ? result + 15 : result;
		}
		else
			break ;
		i++;
	}
	return (result);
}

int				ft_atoi_base(const char *str, const unsigned int base)
{
	int			i;
	int			sign;
	int			result;

	if ((base < 2) || (base > 16))
		return (0);
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||\
			str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	result = get_result(str, base, i);
	return (result * sign);
}
