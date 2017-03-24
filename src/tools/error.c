/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:01:11 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/24 01:16:46 by vchaillo         ###   ########.fr       */
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

void			print_parser_error(char *str, int error_code, int line)
{
	ft_putstr_color(ft_strtrim(str), TERM_BOLD_GREY);
	if (error_code == OBJECT_ABSENT_ERROR)
		ft_putstr_color(" No object in scene file", TERM_BOLD_RED);
	else if (error_code == LIGHT_ABSENT_ERROR)
		ft_putstr_color(" No light in scene file", TERM_BOLD_RED);
	else if (error_code == MISSING_TAG_ERROR)
		ft_putstr_color(" tag is missing", TERM_BOLD_RED);
	else if (error_code == THREE_ARGV_VEC_ERROR)
		ft_putstr_color(" Need 3 values for vector at line : ", TERM_BOLD_RED);
	else if (error_code == IS_EMPTY_ERROR)
		ft_putstr_color(" is empty at line : ", TERM_BOLD_RED);
	else if (error_code == MISSING_ERROR)
		ft_putstr_color("Missing value between both tags", TERM_BOLD_RED);
	else if (error_code == NOT_DEFINE_ERROR)
		ft_putstr_color(" is not a define", TERM_BOLD_RED);
	line != 0 ? ft_putnbr_color(line, TERM_BOLD_GREY) : NULL;
	ft_putstr_color("\n", TERM_END);
	exit(0);
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
