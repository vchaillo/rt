/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:22:57 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/14 19:33:43 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <float.h>
# include "gsl/gsl_poly.h"
# include "gsl/gsl_errno.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include "colors.h"
# include "term_colors.h"
# include "structs.h"
# include "keycodes.h"
# include "macros.h"
# include "materials.h"

/*
** 				main functions
*/
void			print_error(int error_code);
void			print_help(void);

/*********************************************
** 				core functions				**
**********************************************/
/*
**				raytracer
*/
# include "prototypes/core/raytracer.h"

/*
**				Color effects
*/
# include "prototypes/core/effects.h"

/*
**				Reflection effects
*/
# include "prototypes/core/reflection.h"
/*
**				Normals
*/
# include "prototypes/core/normal.h"

/*
**				Perlin Noise
*/
# include "prototypes/core/perlin.h"

/*
**				Objects
*/
# include "prototypes/core/objects.h"

/*
*				Lights
*/
# include "prototypes/core/light.h"

void			super_sampling(t_env *e);

/*
** 				gui functions
*/
void			start_mlx(t_env *e);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
int				key_hook_camera(int keycode, t_camera *camera);
int				key_hook_move_camera(int keycode, t_camera *camera);
int				key_hook_rot_x_camera(int keycode, t_camera *camera);
int				key_hook_rot_y_camera(int keycode, t_camera *camera);
int				key_hook_rot_z_camera(int keycode, t_camera *camera);
int				key_hook_light(int key, t_scene *scene);
int				key_hook_scene(int keycode, t_env *e);
void			key_hook_effects(int keycode, t_env *e);
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
void			print_frame_time(t_env *e);
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
t_color			negative_color(t_color color);
t_vector		vector_rot_x(t_vector v, float angle);
t_vector		vector_rot_y(t_vector v, float angle);
t_vector		vector_rot_z(t_vector v, float angle);
void			export_image(t_env *e);
int				create_file(t_env *e);
void			put_file_header(int fd);
void			put_image_header(int fd);
char			*get_file_name(t_env *e, int type);
double			solve_deg4(const double *eq);
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
void			load_scene6(t_env *e);
void			load_scene6_objects(t_scene *scene);
void			load_scene6_lights(t_scene *scene);
/*
** 				structs functions
*/
t_color			new_color(int color);
t_vector		new_vector(float x, float y, float z);
t_scene			*new_scene(t_color background_color, t_camera *camera);
void			delete_scene(t_scene *scene);
t_camera		*new_camera(t_vector pos, t_vector dir);
void			delete_camera(t_camera *camera);
t_sphere		*new_sphere(t_vector pos, float r);
void			delete_sphere(t_sphere *sphere);
t_tore			*new_tore(t_vector pos, float r, float big_r);
void			delete_tore(t_tore *tore);
t_boloid		*new_boloid(t_vector pos, float a, float b, float c);
void			delete_boloid(t_boloid *boloid);
t_plane			*new_plane(t_vector normal, float offset, int wave);
void			delete_plane(t_plane *plane);
t_cylinder		*new_cylinder(t_vector axis, t_vector pos, float r);
void			delete_cylinder(t_cylinder *cylinder);
t_cone			*new_cone(t_vector axis, t_vector apex, float aperture);
void			delete_cone(t_cone *cone);
t_object		*new_object(int type, void *object, t_color color, t_mat mat);
void			add_object(t_scene *scene, t_object *new);
void			delete_objects(t_object *objects);
t_light			*new_light(int type, float intensity, t_vector v, t_color c);
void			add_light(t_scene *scene, t_light *new);
void			delete_lights(t_light *lights);
t_mat			new_material(int material);
t_mat			new_basic_material(void);
t_mat			new_plastic_material(void);
t_mat			new_glass_material(void);
t_mat			new_marble_material(void);
t_color			**new_color_array(int wmax, int hmax);
void			delete_color_array(int hmax, t_color **colors);
t_color			**reset_color_array(int aa, t_color **colors);

#endif
