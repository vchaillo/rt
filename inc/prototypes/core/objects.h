#ifndef OBJECTS_H
# define OBJECTS_H

float			hit_plane(t_plane *plane, t_ray *ray);
int				is_plane_illuminated(t_ray *ray, t_light *light);
t_color			checkerboard_plane(t_hitpoint hitpoint);
float			hit_sphere(t_sphere *sphere, t_ray *ray);
float			hit_cylinder(t_cylinder *cylinder, t_ray *ray);
float			hit_cone(t_cone *cone, t_ray *ray);
float			hit_tore(t_tore *tore, t_ray *ray);
float			hit_boloid(t_boloid *boloid, t_ray *ray);
float           hit_box(t_box *box, t_ray *ray);
float           hit_disc(t_disc *disc, t_ray *ray);

#endif
