#ifndef NORMAL_H
# define NORMAL_H

t_vector		get_normal(t_ray *ray);
t_vector		get_normal_at_plane(t_ray *ray, t_plane *plane);
t_vector		get_normal_at_cylinder(t_ray *ray, t_cylinder *cylinder);
t_vector		get_normal_at_cone(t_ray *ray, t_cone *cone);

#endif
