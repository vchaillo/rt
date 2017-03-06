/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:22:57 by vchaillo          #+#    #+#             */
/*   Updated: 2017/01/28 15:51:56 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "colors.h"
# include "term_colors.h"
# include "structs.h"
# include "keycodes.h"
# include "macros.h"

/*
** 				main functions
*/
void			print_error(int error_code);
void			print_help(void);
/*
** 				core functions
*/
void			get_hitpoint(t_object *object, t_ray *ray, float t_min);
int				get_ray_intersection(t_object *objects, t_ray *ray);
t_vector		get_camray_dir(t_camera *camera, int x, int y);
t_color			raytracer(t_env *e, int x, int y);
float			hit_plane(t_plane *plane, t_ray *ray);
int				is_plane_illuminated(t_ray *ray, t_light *light);
float			hit_sphere(t_sphere *sphere, t_ray *ray);
float			hit_cylinder(t_cylinder *cylinder, t_ray *ray);
float			hit_cone(t_cone *cone, t_ray *ray);
int				is_in_shadow(t_object *objects, t_ray *ray, t_object *hit_obj);
t_color			specular(t_ray *v_ray, t_light *spot, t_ray *l_ray);
t_color			diffuse(t_hitpoint hitpoint, t_light *spot, t_ray *ray);
t_color			phong(t_env *e, t_light *light, t_ray *v_ray);
t_color			illuminate(t_env *e, t_ray *ray);
t_vector		get_normal(t_ray *ray);
t_vector		get_normal_at_cylinder(t_ray *ray, t_cylinder *cylinder);
t_vector		get_normal_at_cone(t_ray *ray, t_cone *cone);
/*
** 				gui functions
*/
void			start_mlx(t_env *e);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
int				key_hook_camera(int keycode, t_camera *camera);
int				key_hook_light(int keycode, t_scene *scene);
int				key_hook_scene(int keycode, t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
void			fill_pixel(t_env *e, t_color color, int x, int y);
void			update_image(t_env *e);
void			draw(t_env *e);
void			select_object(int x, int y, t_env *e);
void			print_gui_output(t_env *e);
void			print_gui_selected_object(t_env *e);
void			print_mode(t_env *e);
int				key_hook_sphere(int keycode, t_sphere *sphere);
int				key_hook_plane(int keycode, t_plane *plane);
int				key_hook_cylinder(int keycode, t_cylinder *cylinder);
int				key_hook_cylinder_rotation(int keycode, t_cylinder *cylinder);
int				key_hook_cone(int keycode, t_cone *cone);
int				key_hook_cone_rotation(int keycode, t_cone *cone);
int				key_hook_objects(int keycode, t_scene *scene);
/*
** 				cli functions
*/
void			print_cli_output(t_env *e);
void			print_camera_pos(t_env *e);
void			print_nb_rays(t_env *e);
void			print_lights(t_env *e);
void			print_exposehook(t_env *e);
void			print_keyhook(int keycode, t_env *e);
void			print_mousehook(int button, int x, int y, t_env *e);
void			print_objects(t_env *e);
void			print_sphere(t_sphere *sphere);
void			print_plane(t_plane *plane);
void			print_cylinder(t_cylinder *cylinder);
void			print_lights(t_env *e);
void			print_amb_light(t_env *e);
void			print_spot_light(t_light *light);
void			print_dir_light(t_light *light);
void			print_color(t_color color);
void			print_vector(t_vector vector);
void			print_start_line(void);
void			print_end_line(void);
/*
** 				tools functions
*/
void			parse_arguments(int ac, char **av, t_env *e);
float			solve_deg2(double a, double b, double c);
float			pow_2(float nb);
t_vector		normalize(t_vector vector);
t_vector		vector_scalar(float scalar, t_vector v);
t_vector		vector_add(t_vector v1, t_vector v2);
t_vector		vector_sub(t_vector v1, t_vector v2);
float			dot_product(t_vector v1, t_vector v2);
t_color			limit_color(t_color color);
t_color			average_color(t_color color);
t_color			scalar_color(float scalar, t_color color);
t_color			add_color(t_color color1, t_color color2);
t_color			mult_color(t_color color1, t_color color2);
t_vector		vector_rot_x(t_vector v, float angle);
t_vector		vector_rot_y(t_vector v, float angle);
t_vector		vector_rot_z(t_vector v, float angle);
/*
** 				scenes functions
*/
void			load_scene(int scene_type, t_env *e);
void			switch_scene(int keycode, t_env *e);
void			load_scene1(t_env *e);
void			load_scene1_objects(t_scene *scene);
void			load_scene1_lights(t_scene *scene);
void			load_scene2(t_env *e);
void			load_scene2_objects(t_scene *scene);
void			load_scene2_lights(t_scene *scene);
void			load_scene3(t_env *e);
void			load_scene3_objects(t_scene *scene);
void			load_scene3_lights(t_scene *scene);
void			load_scene4(t_env *e);
void			load_scene4_objects(t_scene *scene);
void			load_scene4_lights(t_scene *scene);
void			load_scene5(t_env *e);
void			load_scene5_objects(t_scene *scene);
void			load_scene5_lights(t_scene *scene);
/*
** 				structs functions
*/
t_color			new_color(int color);
t_vector		new_vector(float x, float y, float z);
t_scene			*new_scene(t_color background_color, t_camera *camera);
void			delete_scene(t_scene *scene);
t_camera		*new_camera(float x, float y, float z);
void			delete_camera(t_camera *camera);
t_sphere		*new_sphere(float x, float y, float z, float r);
void			delete_sphere(t_sphere *sphere);
t_plane			*new_plane(float x, float y, float z, float d);
void			delete_plane(t_plane *plane);
t_cylinder		*new_cylinder(t_vector axis, t_vector pos, float r);
void			delete_cylinder(t_cylinder *cylinder);
t_cone			*new_cone(t_vector axis, t_vector apex, float aperture);
void			delete_cone(t_cone *cone);
t_object		*new_object(int type, void *object, t_color color, int mat);
void			add_object(t_scene *scene, t_object *new);
void			delete_objects(t_object *objects);
t_light			*new_light(int type, float intensity, t_vector v, t_color c);
void			add_light(t_scene *scene, t_light *new);
void			delete_lights(t_light *lights);

#endif
