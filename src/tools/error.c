/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:01:11 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/17 12:35:50 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			print_help(void)
{
	ft_putendl("Usage : ./rt [options]");
	ft_putendl_color("Available options :", TERM_BLACK);
	ft_putstr_color("-v,      	:   ", TERM_BLACK);
	ft_putendl_color("display rays and frame time infos", TERM_BLACK);
	ft_putstr_color("-s1 -s2 -s3   	:   ", TERM_BLACK);
	ft_putendl_color("load defaults scenes", TERM_BLACK);
}

void			print_error(int error_code)
{
	if (error_code == ARG_ERROR)
	{
		ft_putendl_color("rt : Unknow option", TERM_BOLD_RED);
		print_help();
	}
	else if (error_code == MLX_ERROR)
		ft_putendl_color("Mlx initialization failed", TERM_BOLD_RED);
	else if (error_code == MALLOC_ERROR)
		ft_putendl_color("Memory allocation failed", TERM_BOLD_RED);
	else if (error_code == OPEN_ERROR)
		ft_putendl_color("Open or create file failed", TERM_BOLD_RED);
	exit(0);
}
