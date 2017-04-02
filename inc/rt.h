/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:22:57 by vchaillo          #+#    #+#             */
/*   Updated: 2017/04/02 13:08:01 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

/*
** 		system includes
*/
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
# include <pthread.h>
# include <assert.h>

/*
** 		rt includes
*/
# include "libft.h"
# include "colors.h"
# include "term_colors.h"
# include "structs.h"
# include "keycodes.h"
# include "macros.h"
# include "materials.h"

/*
** 				core functions
*/
t_color			fog(t_env *e, t_ray *ray, t_color color);
void			super_sampling(t_env *e);
void			exposure(t_color **color_array);
void			stereoscopy(t_env *e);
t_color			apply_effects(t_env *e, t_color color);
t_color			sepia(t_color color);
t_color			grayscale(t_color color);
float			cartoon(t_env *e, float dot);
int				is_in_shadow(t_object *objects, t_ray *ray, t_object *hit_obj);
t_color			illuminate(t_env *e, t_ray *ray);
void			exposure_correction(t_color **colors);
t_vector		get_normal(t_ray *ray);
t_vector		get_normal_at_plane(t_ray *ray, t_plane *plane);
t_vector		get_normal_at_cylinder(t_ray *ray, t_cylinder *c);
t_vector		get_normal_at_cone(t_ray *ray, t_cone *cone);
t_vector		get_normal_at_tore(t_ray *ray, t_tore *tor);
t_vector		get_normal_at_boloid(t_ray *ray, t_boloid *boloid);
float			hit_plane(t_plane *plane, t_ray *ray);
int				is_plane_illuminated(t_ray *ray, t_light *light);
t_color			checkerboard_plane(t_hitpoint hitpoint);
float			hit_sphere(t_sphere *sphere, t_ray *ray);
float			hit_cylinder(t_cylinder *cylinder, t_ray *ray);
float			hit_cone(t_cone *cone, t_ray *ray);
float			hit_tore(t_tore *tore, t_ray *ray);
float			hit_boloid(t_boloid *boloid, t_ray *ray);
float			hit_box(t_box *box, t_ray *ray, float t);
float			hit_disc(t_disc *disc, t_ray *ray);
void			get_hitpoint(t_object *object, t_ray *ray, float t_min);
float			get_hit_distance(t_object *object, t_ray *ray, float tn);
int				get_ray_intersection(t_object *objects, t_ray *ray);
t_vector		get_camray_dir(t_camera *camera, int x, int y, int aa);
t_color			raytracer(t_env *e, int x, int y);
unsigned int	permutation(int index);
float			perlin(float x, float y, int resolution, int material);
float			gradient(int i, int j);
float			noise(float x, float y, float res);
float			fade(float nb);
t_color			phong(t_env *e, t_light *light, t_ray *vray);
t_color			specular(t_ray *v_ray, t_light *spot, t_ray *l_ray);
t_color			diffuse(t_env *e, t_hitpoint hitpoint, t_light *l, t_ray *ray);
t_color			depth_compute(t_env *e, t_ray *ray, int depth,
					float cumul_coef);
t_color			global_illumination(t_env *e, t_ray *ray);
t_color			reflection(t_env *e, t_ray *ray, t_ref r, float coef);
void			reflected_ray(t_ray *ray);
t_color			refraction(t_env *e, t_ray *ray, t_ref r, float coef);
void			*perform_work(void *argument);
void			join_environements(t_env *e, t_env e_tab[NUM_THREADS]);
void			multithreading(t_env *e);

/*
** 				gui functions
*/
void			start_mlx(t_env *e);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
int				key_hook_camera(int keycode, t_camera *camera);
int				mouse_hook(int button, int x, int y, t_env *e);
int				mouse_clic(t_env *e);
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
int				key_hook_box(int keycode, t_box *box);
int				key_hook_cone(int keycode, t_cone *cone);
int				key_hook_cone_rotation(int keycode, t_cone *cone);
int				key_hook_disc(int keycode, t_disc *disc);
int				key_hook_objects(int keycode, t_scene *scene);

/*
** 				cli functions
*/
void			print_cli_output(t_env *e);
void			print_exposehook(t_env *e);
void			print_keyhook(int keycode, t_env *e);
void			print_mousehook(int button, int x, int y, t_env *e);
void			print_frame_time(t_env *e);

/*
** 				parser functions
*/
void			parse_arguments(int ac, char **av, t_env *e);
void			parse_xml_file(t_env *e, char **tab);
t_macros		create_macros_arrays(void);
void			free_array(char **array);
int				search_macro(char *str, char **tab);
char			**get_tab(char *file);
int				create_object(t_env *e, char **tab);
int				create_light(t_env *e, char **tab);
int				hextoint(const char *str);
t_vector		get_vector(char **array, char *tag, char *tagg);
int				get_color(t_env *e, char **array, char *tag, char *tagg);
int				get_material(t_env *e, char **array, char *tag, char *tagg);
int				get_effect(t_env *e, char **array, char *tag, char *tagg);
int				get_object(t_env *e, char **array, char *tag, char *tagg);
int				get_light(t_env *e, char **array, char *tag, char *tagg);
int				get_pstyle(t_env *e, char **array, char *tag, char *tagg);
int				tag_present(char **array, char *tag, char *str);
char			*between_tags(char **array, char *tag, int end);
float			get_nbr(char **array, char *tag, char *tagg);
t_vector		get_vect(char *str, char **tab, int x);
void			print_error(int error_code);
void			print_parser_error(char *str, int error_code, int line);
void			print_help(void);

/*
** 				tools functions
*/
float			solve_deg2(double a, double b, double c);
double			solve_deg4(const double *eq);
float			pow_2(float nb);
void			ft_swapf(float *f1, float *f2);
t_vector		normalize(t_vector vector);
t_vector		vector_scalar(float scalar, t_vector v);
t_vector		vector_add(t_vector v1, t_vector v2);
t_vector		vector_sub(t_vector v1, t_vector v2);
float			dot_product(t_vector v1, t_vector v2);
t_vector		cross_product(t_vector u, t_vector v);
t_color			limit_color(t_color color);
t_color			average_color(t_color color);
t_color			scalar_color(float scalar, t_color color);
t_color			add_color(t_color color1, t_color color2);
t_color			negative_color(t_color color);
t_vector		vector_rot_x(t_vector v, float angle);
t_vector		vector_rot_y(t_vector v, float angle);
t_vector		vector_rot_z(t_vector v, float angle);
t_vector		vector_rot_axis(t_vector v, t_vector axis, float angle);
t_vector		convert_to_rotated_coordinates(t_vector pos, t_vector axis);
t_ray			ray_coord_modif(t_ray *ray, t_vector trans, t_vector rotxyz);
t_vector		cross_product(t_vector u, t_vector v);
void			print_error(int error_code);
void			print_help(void);
void			ft_putfloat(float n, int max);
void			ft_putfloat_fd(float n, int max, int fd);

/*
** 				export functions
*/
void			export_image(t_env *e);
int				create_file(t_env *e, int type);
void			put_file_header(int fd);
void			put_image_header(int fd);
char			*get_file_name(t_env *e, int type);
void			export_scene(t_env *e);
void			print_tag_tofile(char *tag, int type, int tabulations, int fd);
void			print_vector_tofile(t_vector v, char *name, int tabs, int fd);
void			print_color_tofile(t_env *e, t_color c, int fd);
void			print_objects_tofile(t_env *e, int fd);
void			print_cone_tofile(t_cone *cone, int fd);
void			print_tore_tofile(t_tore *tore, int fd);
void			print_boloid_tofile(t_boloid *boloid, int fd);
void			print_box_tofile(t_box *box, int fd);
void			print_disc_tofile(t_disc *disc, int fd);
void			print_lights_tofile(t_env *e, t_light *lights, int fd);

/*
** 				scenes functions
*/
void			load_scene(int scene_type, t_env *e);
void			switch_scene(int keycode, t_env *e);
void			load_scene1(t_env *e);
void			load_scene2(t_env *e);
void			load_scene3(t_env *e);
void			load_scene4(t_env *e);
void			load_scene5(t_env *e);
void			load_scene6(t_env *e);
void			load_scene7(t_env *e);
void			load_scene8(t_env *e);
void			load_scene9(t_env *e);

/*
** 				structs functions
*/
t_color			new_color(int color);
t_vector		new_vector(float x, float y, float z);
t_scene			*new_scene(t_color background_color, t_camera *camera);
void			delete_scene(t_scene *scene);
t_camera		*new_camera(t_vector pos, t_vector look_at);
void			delete_camera(t_camera *camera);
void			get_viewplane_pos(t_camera *camera);
t_sphere		*new_sphere(t_vector pos, float r, t_vector axis,
					t_vector limits[]);
void			delete_sphere(t_sphere *sphere);
t_tore			*new_tore(t_vector pos, float r, float big_r,
					t_vector limits[]);
void			delete_tore(t_tore *tore);
t_boloid		*new_boloid(t_vector pos, t_vector abc, float sign,
					t_vector limits[]);
void			delete_boloid(t_boloid *boloid);
t_plane			*new_plane(t_vector normal, float offset, int wave,
					t_vector limits[]);
void			delete_plane(t_plane *plane);
t_cylinder		*new_cylinder(t_vector axis, t_vector pos, float r,
					t_vector limits[]);
void			delete_cylinder(t_cylinder *cylinder);
t_cone			*new_cone(t_vector axis, t_vector apex, float aperture,
					t_vector limits[]);
void			delete_cone(t_cone *cone);
t_box			*new_box(t_vector corner, t_vector translation,
					t_vector rotxyz);
void			delete_box(t_box *box);
t_disc			*new_disc(float r_max, float r_min, t_vector pos,
					t_vector rotxyz);
void			delete_disc(t_disc *disc);
t_object		*new_object(int type, void *object, t_color color, t_mat mat);
void			add_object(t_scene *scene, t_object *new);
void			delete_objects(t_object *objects);
t_light			*new_light(int type, float intensity, t_vector v, t_color c);
void			add_light(t_scene *scene, t_light *new);
void			delete_lights(t_light *lights);
t_mat			new_material(int material);
t_mat			new_basic_material(void);
t_mat			new_plastic_material(void);
t_mat			new_perlin_material(void);
t_mat			new_chrome_material(void);
t_mat			new_glass_material(void);
t_mat			new_water_material(void);
t_mat			new_bitref_material(void);
t_mat			new_test_material(void);
t_color			**new_color_array(int wmax, int hmax);
void			delete_color_array(int hmax, t_color **colors);
t_color			**reset_color_array(int aa, t_color **colors);

#endif
