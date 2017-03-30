/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:15:39 by valentin          #+#    #+#             */
/*   Updated: 2017/03/30 17:35:34 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			print_frame_time(t_env *e)
{
	ft_putstr_color("\n", TERM_BOLD_GREY);
	ft_putstr_color("Frame time : ", TERM_BOLD_GREY);
	ft_putfloat2(e->frame_time);
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
