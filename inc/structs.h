/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:23:02 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/10 20:51:12 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct				s_color
{
	float					r;
	float					g;
	float					b;
}							t_color;

typedef struct				s_vector
{
	double					x;
	double					y;
	double					z;
}							t_vector;

typedef struct				s_sphere
{
	t_vector				pos;
	float					r;
}							t_sphere;

typedef struct				s_plane
{
	t_vector				normal;
	float					offset;
	int						wave;
}							t_plane;

typedef struct				s_cylinder
{
	t_vector				axis;
	t_vector				pos;
	float					r;
}							t_cylinder;

typedef struct				s_cone
{
	t_vector				axis;
	t_vector				apex;
	float					angle;
}							t_cone;

typedef struct				s_mat
{
	int						type;
	float					diffuse;
	float					specular;
	float					reflexion;
	float					refraction;
}							t_mat;

typedef struct				s_object
{
	int						type;
	void					*object;
	t_color					color;
	t_mat					material;
	struct s_object			*next;
}							t_object;

typedef struct				s_hitpoint
{
	t_vector				pos;
	t_vector				normal;
	t_color					color;
	t_object				*object;
}							t_hitpoint;

typedef struct				s_ray
{
	t_vector				o;
	t_vector				d;
	float					t;
	t_hitpoint				hitpoint;
}							t_ray;

typedef struct				s_light
{
	int						type;
	float					intensity;
	t_vector				pos;
	t_vector				dir;
	t_color					color;
	struct s_light			*next;
}							t_light;

typedef struct				s_camera
{
	t_vector				pos;
	t_vector				dir;
	t_vector				rot;
	float					ratio;
	float					fov;
	float					focale;
}							t_camera;

typedef struct				s_scene
{
	t_color					background_color;
	t_camera				*camera;
	t_object				*objects;
	t_light					*lights;
	float					amb_intensity;
	t_color					amb_color;
	int						amb;
	int						dir;
	int						spot;
	int						diffuse;
	int						specular;
	t_object				*selected_object;
	int						nb_objects;
	int						nb_lights;
	int						mode;
	int						effect;
	int						aa;
}							t_scene;

typedef struct				s_env
{
	void					*mlx;
	void					*win;
	void					*img;
	char					*data;
	int						size;
	int						endian;
	int						bpp;
	int						scene_type;
	t_scene					*scene;
	double					nb_rays;
	double					nb_cam_rays;
	double					nb_light_rays;
	int						verbose;
	t_color					**color_array;
	t_color					**color_array_aa;
}							t_env;

#endif
