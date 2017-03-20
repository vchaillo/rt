/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:47:03 by valentin          #+#    #+#             */
/*   Updated: 2017/03/20 01:26:16 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/*
** multi threading
*/
#define NUM_THREADS 4

/*
** reflection and refraction defines
*/
# define MAX_DEPTH 10
# define AIR_IOR 1
# define EPSILON_SHADOW 0.01

/*
** rotations and translations defines
*/
# define CAM_SPEED 1
# define CAM_ROT 10
# define OBJ_SPEED 1
# define OBJ_ROT 10
# define OBJ_EXPAND 1

/*
** exposure defines
*/
# define EXPOSURE -1
# define EXPOSE_TYPE 2
# define DO_GAMMA 0
# define INV_GAMMA 6

/*
** basics defines
*/
# define TRUE 1
# define FALSE 0
# define ACTIVE 1
# define INACTIVE 0
# define ACTIVE_AA 4
# define INACTIVE_AA 1

/*
** verbose defines
*/
# define VERBOSE 1

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
# define VIEWPLANE_W 0.5
# define VIEWPLANE_H 0.35
# define RATIO (float)WIN_W / (float)WIN_H
# define FOV tan((40 * M_PI) / 180)
# define FOCALE 1
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
# define NB_SCENES 8
# define SCENE_1 1
# define SCENE_2 2
# define SCENE_3 3
# define SCENE_4 4
# define SCENE_5 5
# define SCENE_6 6
# define SCENE_7 7
# define SCENE_8 8

/*
** objects defines
*/
# define SPHERE 0
# define PLANE 1
# define CYLINDER 2
# define CONE 3
# define TORE 4
# define BOLOID 5
# define BOX 6

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
# define STEREO 5

/*
** files modes defines
*/
# define IMAGE 0
# define SCENE 1

/*
** tags defines
*/
# define TAG_OPEN 0
# define TAG_OPEN_ENDL 1
# define TAG_CLOSE 2

#endif
