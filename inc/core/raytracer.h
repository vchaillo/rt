#ifndef RAYTRACER_H
# define RAYTRACER_H

void			get_hitpoint(t_object *object, t_ray *ray, float t_min);
int				get_ray_intersection(t_object *objects, t_ray *ray);
t_vector		get_camray_dir(t_camera *camera, int x, int y, int aa);
t_color			raytracer(t_env *e, int x, int y);

#endif
