/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:15:39 by valentin          #+#    #+#             */
/*   Updated: 2017/04/01 21:00:06 by valentinchaillou89###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			print_frame_time(t_env *e)
{
	ft_putstr_color("\n", TERM_BOLD_GREY);
	ft_putstr_color("Frame time : ", TERM_BOLD_GREY);
	ft_putfloat(e->frame_time, 2);
	ft_putendl_color(" s\n", TERM_BOLD_GREY);
}

void			print_cli_output(t_env *e)
{
	if (e->verbose == VERBOSE)
	{
		ft_putendl_color("\n***********************", TERM_BOLD_GREEN);
		print_frame_time(e);
	}
}
