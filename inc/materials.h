/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:39:55 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/24 01:21:48 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIALS_H
# define MATERIALS_H

# define DIFFUSE 0
# define REFLECTIVE 1
# define TRANSMITIVE 2

/*
** materials defines
*/
# define BASIC 0
# define PLASTIC 1
# define GLASS 2
# define PERLIN 3
# define BIT_REF 4
# define WATER 5
# define CHROME 6
# define TEST 7

/*
** materials values defines
*/
# define BASIC_DIFFUSE 1
# define BASIC_SPECULAR 1
# define BASIC_SHININESS 100
# define BASIC_REFLEXION 0
# define BASIC_REFRACTION 0
# define BASIC_IOR 1
# define BASIC_SHADOW 0

# define PLASTIC_DIFFUSE 1
# define PLASTIC_SPECULAR 1
# define PLASTIC_SHININESS 10
# define PLASTIC_REFLEXION 0
# define PLASTIC_REFRACTION 0
# define PLASTIC_IOR 1
# define PLASTIC_SHADOW 0

# define CHROME_DIFFUSE 0
# define CHROME_SPECULAR 1
# define CHROME_SHININESS 1000
# define CHROME_REFLEXION 1
# define CHROME_REFRACTION 0
# define CHROME_IOR 20
# define CHROME_SHADOW 0

# define PERLIN_DIFFUSE 1
# define PERLIN_SPECULAR 1
# define PERLIN_SHININESS 500
# define PERLIN_REFLEXION 0.5
# define PERLIN_REFRACTION 0
# define PERLIN_IOR 1
# define PERLIN_SHADOW 0

# define BITREF_DIFFUSE 1
# define BITREF_SPECULAR 1
# define BITREF_SHININESS 10
# define BITREF_REFLEXION 0.7
# define BITREF_REFRACTION 0
# define BITREF_IOR 20
# define BITREF_SHADOW 0

# define WATER_DIFFUSE 1
# define WATER_SPECULAR 1
# define WATER_SHININESS 10
# define WATER_REFLEXION 0.2
# define WATER_REFRACTION 0.8
# define WATER_IOR 1.3
# define WATER_SHADOW 0.7

# define GLASS_DIFFUSE 0
# define GLASS_SPECULAR 1
# define GLASS_SHININESS 100
# define GLASS_REFLEXION 0.4
# define GLASS_REFRACTION 1
# define GLASS_IOR 1.55
# define GLASS_SHADOW 0.7

# define TEST_DIFFUSE 1
# define TEST_SPECULAR 1
# define TEST_SHININESS 10
# define TEST_REFLEXION 0
# define TEST_REFRACTION 0
# define TEST_IOR 4
# define TEST_SHADOW 0

#endif
