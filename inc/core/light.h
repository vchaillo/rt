#ifndef LIGHT_H
# define LIGHT_H

int				is_in_shadow(t_object *objects, t_ray *ray, t_object *hit_obj);
t_color			illuminate(t_env *e, t_ray *ray);
void			exposure_correction(t_color **colors);

#endif
