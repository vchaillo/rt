/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_colors.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 21:12:00 by valentin          #+#    #+#             */
/*   Updated: 2017/01/10 11:43:18 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_COLORS_H
# define TERM_COLORS_H

/*
** term colors defines
*/
# define TERM_BLACK "\033[30;1m"
# define TERM_RED "\033[31m"
# define TERM_GREEN "\033[32m"
# define TERM_YELLOW "\033[33m"
# define TERM_BLUE "\033[34m"
# define TERM_GREY "\033[37m"
# define TERM_END "\033[0;0m"

/*
** term bold colors defines
*/
# define TERM_BOLD_BLACK "\033[30;1m"
# define TERM_BOLD_RED "\033[31;1m"
# define TERM_BOLD_GREEN "\033[32;1m"
# define TERM_BOLD_YELLOW "\033[33;1m"
# define TERM_BOLD_BLUE "\033[34;1m"
# define TERM_BOLD_GREY "\033[37;1m"
/*
** term background colors defines
*/
# define TERM_BLACK_BG "\033[40m"
# define TERM_RED_BG "\033[41m"
# define TERM_GREEN_BG "\033[42m"
# define TERM_YELLOW_BG "\033[43m"
# define TERM_BLUE_BG "\033[44m"
# define TERM_GREY_BG "\033[45m"

#endif
