
#ifndef EFFECTS_H
# define EFFECTS_H

/*
**	Take in a color, apply effect(s), and return the new color.
*/
t_color			apply_effects(t_env *e, t_color color);
t_color			sepia(t_color color);
t_color			grayscale(t_color color);
float			cartoon(t_env *e, float dot);

#endif
