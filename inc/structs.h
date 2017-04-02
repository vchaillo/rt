/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:23:02 by vchaillo          #+#    #+#             */
/*   Updated: 2017/04/02 13:10:13 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct				s_fresnel
{
	float					cosi;
	float					etai;
	float					etat;
	float					tmp;
	float					sint;
	float					cost;
	float					rs;
	float					rp;
}							t_fresnel;

typedef struct				s_color
{
	float					r;
	float					g;
	float					b;
}							t_color;

typedef struct				s_vector
{
	float					x;
	float					y;
	float					z;
}							t_vector;

typedef struct				s_sphere
{
	t_vector				pos;
	t_vector				axis;
	t_vector				limit_max;
	t_vector				limit_min;
	float					r;
}							t_sphere;

typedef struct				s_plane
{
	t_vector				normal;
	float					offset;
	int						type;
	int						is_limited;
	t_vector				mins;
	t_vector				maxs;
	t_vector				limit_max;
	t_vector				limit_min;
}							t_plane;

typedef struct				s_cylinder
{
	t_vector				axis;
	t_vector				pos;
	t_vector				limit_max;
	t_vector				limit_min;
	float					r;
}							t_cylinder;

typedef struct				s_cone
{
	t_vector				axis;
	t_vector				limit_max;
	t_vector				limit_min;
	t_vector				apex;
	float					angle;
}							t_cone;

typedef struct				s_tore
{
	t_vector				pos;
	t_vector				limit_max;
	t_vector				limit_min;
	float					r;
	float					big_r;
}							t_tore;

typedef struct				s_boloid
{
	t_vector				pos;
	t_vector				limit_max;
	t_vector				limit_min;
	float					a;
	float					b;
	float					c;
	float					sign;
}							t_boloid;

typedef struct				s_box
{
	t_vector				corner_min;
	t_vector				corner_max;
	t_vector				trans;
	t_vector				rotxyz;
	t_vector				normal;
}							t_box;

typedef struct				s_disc
{
	float					r_min;
	float					r_max;
	t_vector				pos;
	t_vector				rotxyz;
	t_vector				normal;
}							t_disc;

typedef struct				s_mat
{
	int						type;
	float					diffuse;
	float					specular;
	float					shininess;
	float					reflexion;
	float					refraction;
	float					ior;
	int						property;
	float					shadow;
}							t_mat;

typedef struct				s_object
{
	int						type;
	void					*object;
	t_color					color;
	t_mat					material;
	int						id;
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
	float					transmittance_ray;
	t_hitpoint				hitpoint;
	float					ior;
	float					past_ior;
	int						is_in;
}							t_ray;

typedef struct				s_gi
{
	t_color					indirect_light;
	float					pdf;
	float					r1;
	float					r2;
	t_vector				nt;
	t_vector				nb;
	t_vector				sample;
	t_vector				sample_world;
	t_ray					tmp;
	int						i;
}							t_gi;

typedef struct				s_ref
{
	t_color					color;
	t_color					reflect_color;
	t_color					refract_color;
	t_ray					reflect_ray;
	t_ray					refract_ray;
	int						depth;
}							t_ref;

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
	t_vector				look_at;
	t_vector				dir_right;
	t_vector				dir_up;
	t_vector				viewplane_pos;
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
	t_color					**color_array;
	t_color					**color_array_aa;
	int						gi;
}							t_scene;

typedef struct				s_macro_array
{
	char					*define;
	int						value;
}							t_macro_array;

typedef struct				s_macros
{
	t_macro_array			*colors;
	t_macro_array			*materials;
	t_macro_array			*effects;
	t_macro_array			*objects;
	t_macro_array			*lights;
	t_macro_array			*plane_styles;
}							t_macros;

typedef struct				s_env
{
	void					*mlx;
	void					*win;
	void					*img;
	char					*data;
	int						size;
	int						endian;
	int						bpp;
	int						thread;
	int						scene_type;
	t_scene					*scene;
	t_macros				macros;
	int						verbose;
	float					frame_time;
}							t_env;

#endif
