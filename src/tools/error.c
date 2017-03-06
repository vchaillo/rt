/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:01:11 by vchaillo          #+#    #+#             */
/*   Updated: 2017/01/10 11:41:51 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			print_help(void)
{
	ft_putendl("Usage : ./rtv1 [options]");
	ft_putendl_color("Available options :", TERM_BLACK);
	ft_putstr_color("-v,      	:   ", TERM_BLACK);
	ft_putendl_color("display rays and scene infos", TERM_BLACK);
	ft_putstr_color("-V   		:   ", TERM_BLACK);
	ft_putendl_color("display only rays infos", TERM_BLACK);
	ft_putstr_color("-s1 -s2 -s3   	:   ", TERM_BLACK);
	ft_putendl_color("load defaults scenes", TERM_BLACK);
}

void			print_error(int error_code)
{
	if (error_code == ARG_ERROR)
	{
		ft_putendl_color("rtv1 : Unknow option", TERM_BOLD_RED);
		print_help();
	}
	else if (error_code == MLX_ERROR)
		ft_putendl_color("Mlx initialization failed", TERM_BOLD_RED);
	else if (error_code == MALLOC_ERROR)
		ft_putendl_color("Memory allocation failed", TERM_BOLD_RED);
	exit(0);
}
