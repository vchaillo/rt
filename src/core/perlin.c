/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:38:44 by valentin          #+#    #+#             */
/*   Updated: 2017/03/09 17:34:16 by valentinchaillou89###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

struct perlin
{
	int p[512];
	perlin(void);
	static perlin & getInstance(){static perlin instance; return instance;}
};

static int permutation[] = { 151,160,137,91,90,15,
	131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,
	190, 6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,
	88,237,149,56,87,174,20,125,136,171,168, 68,175,74,165,71,134,139,48,27,166,
	77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,
	102,143,54, 65,25,63,161, 1,216,80,73,209,76,132,187,208, 89,18,169,200,196,
	135,130,116,188,159,86,164,100,109,198,173,186, 3,64,52,217,226,250,124,123,
	5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,
	223,183,170,213,119,248,152, 2,44,154,163, 70,221,153,101,155,167, 43,172,9,
	129,22,39,253, 19,98,108,110,79,113,224,232,178,185, 112,104,218,246,97,228,
	251,34,242,193,238,210,144,12,191,179,162,241, 81,51,145,235,249,14,239,107,
	49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127, 4,150,254,
	138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180
	};


double			fade(double t)
{
	return t * t * t * (t * (t * 6 - 15) + 10);
}


double			lerp(double t, double a, double b)
{
	return a + t * (b - a);
}


double 			grad(int hash, double x, double y, double z)
{
	int 		h;
	double 		u;
	double 		v;

	h = hash & 15;                      // CONVERT LO 4 BITS OF HASH CODE
	u = h < 8 || h == 12 || h == 13 ? x : y;   // INTO 12 GRADIENT DIRECTIONS.
	v = h < 4 || h == 12 || h == 13 ? y : z;
	return ((h&1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}


double 			noise(double x, double y, double z)
{

	perlin & myPerlin = perlin::getInstance();

	int x1;
	int y1;
	int z1;
	double u;
	double v;
	double w;
	int a;
	int aa;
	int ab;
	int b;
	int ba;
	int bb;

	x1 = (int)floor(x) & 255;
	y1 = (int)floor(y) & 255;
	z1 = (int)floor(z) & 255;     // FIND UNIT CUBE THAT
	x -= floor(x);                // FIND RELATIVE x1,y1,z1
	y -= floor(y);                // OF POINT IN CUBE.
	z -= floor(z);
	u = fade(x);                  // COMPUTE FADE CURVES
	v = fade(y);                  // FOR EACH OF x1,y1,z1.
	w = fade(z);

	a = myPerlin.p[x1] + y1;      // HASH COORDINATES OF
	aa = myPerlin.p[a] + z1;      // THE 8 CUBE CORNERS
	ab = myPerlin.p[a + 1] + z1;
	b = myPerlin.p[x1 + 1] + y1;
	ba = myPerlin.p[b] + z1;
	bb = myPerlin.p[b + 1] + z1;

	return lerp(w, lerp(v, lerp(u, grad(myPerlin.p[aa], x, y, z),  // AND ADD
		grad(myPerlin.p[ba], x - 1, y, z)), // BLENDED
		lerp(u, grad(myPerlin.p[ab], x, y - 1, z),  // RESULTS
		grad(myPerlin.p[bb], x - 1, y - 1, z))),// FROM  8
		lerp(v, lerp(u, grad(myPerlin.p[aa + 1], x, y, z - 1),  // CORNERS
		grad(myPerlin.p[ba + 1], x - 1, y, z - 1)), // OF CUBE
		lerp(u, grad(myPerlin.p[ab + 1], x, y - 1, z - 1),
		grad(myPerlin.p[bb + 1], x - 1, y - 1, z - 1))));
}

perlin::perlin (void)
{
	int		i;

	i = 0;
	while (i < 256)
	{
		p[256 + i] = p[i] = permutation[i];
		i++;
	}
}
