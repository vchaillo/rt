/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:47:03 by valentin          #+#    #+#             */
/*   Updated: 2017/03/11 04:51:15 by valentinchaillou89###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/*
** reflection defines
** reflection coef need to be change with real material reflection
*/
# define REF_COEF 0.2
# define REF_DEPTH 3

/*
** basics defines
*/
# define TRUE 1
# define FALSE 0
# define ACTIVE 1
# define INACTIVE 0
# define ACTIVE_AA 2
# define INACTIVE_AA 1

/*
** verbose defines
*/
# define FULL_VERBOSE 1
# define MIN_VERBOSE 2

/*
** errors defines
*/
# define MALLOC_ERROR 0
# define MLX_ERROR 1
# define ARG_ERROR 2
# define OPEN_ERROR 3

/*
** window and camera defines
*/
# define WIN_W 1080
# define WIN_H 720
# define RATIO (float)WIN_W / (float)WIN_H
# define FOV tan((20 * M_PI) / 180)
# define FOCALE -1
# define EPSILON 0.01
# define MAX_DIST 1000

/*
** lights defines
*/
# define MOVE_MODE 0
# define EDIT_MODE 1

/*
** scenes defines
*/
# define NB_SCENES 5
# define SCENE_1 1
# define SCENE_2 2
# define SCENE_3 3
# define SCENE_4 4
# define SCENE_5 5

/*
** objects defines
*/
# define SPHERE 0
# define PLANE 1
# define CYLINDER 2
# define CONE 3

/*
** plane types defines
*/
# define NORMAL 0
# define WAVE 1
# define CHECK 2
# define CHECK_WAVE 3

/*
** lights defines
*/
# define AMB 0
# define SPOT 1
# define DIR 2

/*
** effects defines
*/
# define SEPIA 1
# define GRAYSCALE 2
# define CARTOON 3
# define NEGATIVE 4

/*
** files modes defines
*/
# define IMAGE 0
# define SCENE 1

#endif
