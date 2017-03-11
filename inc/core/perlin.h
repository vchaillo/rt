#ifndef PERLIN_H
# define PERLIN_H

unsigned int	permutation(int index);
float			perlin(t_vector pos, int resolution);
float			gradient(int i, int j);
float			noise(float x, float y, float res);
float			fade(float nb);

#endif
