/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:39:55 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/21 07:19:41 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIALS_H
# define MATERIALS_H

/*
** materials defines
*/
# define BASIC 0
# define PLASTIC 1
# define GLASS 2
# define PERLIN 3

/*
** materials values defines
*/
# define BASIC_DIFFUSE 1
# define BASIC_SPECULAR 100
# define BASIC_REFLEXION 0
# define BASIC_REFRACTION 0

# define PLASTIC_DIFFUSE 1
# define PLASTIC_SPECULAR 10
# define PLASTIC_REFLEXION 0
# define PLASTIC_REFRACTION 0

# define GLASS_DIFFUSE 1
# define GLASS_SPECULAR 1000
# define GLASS_REFLEXION 1
# define GLASS_REFRACTION 1

# define PERLIN_DIFFUSE 1
# define PERLIN_SPECULAR 100
# define PERLIN_REFLEXION 0.5
# define PERLIN_REFRACTION 1

#endif
