/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:39:55 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/10 21:18:33 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIALS_H
# define MATERIALS_H

# define BASIC 0
# define PLASTIC 1
# define GLASS 2
# define MARBLE 3
# define BIT_REF 4
# define WATER 5

# define BASIC_DIFFUSE 1
# define BASIC_SPECULAR 100
# define BASIC_REFLEXION 0
# define BASIC_REFRACTION 0
# define BASIC_IOR 0

# define PLASTIC_DIFFUSE 1
# define PLASTIC_SPECULAR 10
# define PLASTIC_REFLEXION 0
# define PLASTIC_REFRACTION 0
# define PLASTIC_IOR 1

# define GLASS_DIFFUSE 1
# define GLASS_SPECULAR 10
# define GLASS_REFLEXION 0.1
# define GLASS_REFRACTION 0.9
# define GLASS_IOR 1.52

# define MARBLE_DIFFUSE 1
# define MARBLE_SPECULAR 100
# define MARBLE_REFLEXION 0.5
# define MARBLE_REFRACTION 0
# define MARBLE_IOR 1

# define BITREF_DIFFUSE 1
# define BITREF_SPECULAR 100
# define BITREF_REFLEXION 0.4
# define BITREF_REFRACTION 0
# define BITREF_IOR 1

# define WATER_DIFFUSE 1
# define WATER_SPECULAR 10
# define WATER_REFLEXION 0.1
# define WATER_REFRACTION 0.9
# define WATER_IOR 1.33

#endif
