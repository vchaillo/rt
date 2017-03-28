/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_material2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 04:03:48 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/28 02:15:18 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_mat			new_glass_material(void)
{
	t_mat		material;

	material.type = GLASS;
	material.diffuse = GLASS_DIFFUSE;
	material.specular = GLASS_SPECULAR;
	material.shininess = GLASS_SHININESS;
	material.reflexion = GLASS_REFLEXION;
	material.refraction = GLASS_REFRACTION;
	material.ior = GLASS_IOR;
	material.property = TRANSMITIVE;
	material.shadow = GLASS_SHADOW;
	return (material);
}

t_mat			new_perlin_material(void)
{
	t_mat		material;

	material.type = PERLIN;
	material.diffuse = PERLIN_DIFFUSE;
	material.specular = PERLIN_SPECULAR;
	material.shininess = PERLIN_SHININESS;
	material.reflexion = PERLIN_REFLEXION;
	material.refraction = PERLIN_REFRACTION;
	material.ior = PERLIN_IOR;
	material.property = DIFFUSE;
	material.shadow = PERLIN_SHADOW;
	return (material);
}

t_mat			new_chrome_material(void)
{
	t_mat		material;

	material.type = CHROME;
	material.diffuse = CHROME_DIFFUSE;
	material.specular = CHROME_SPECULAR;
	material.shininess = CHROME_SHININESS;
	material.reflexion = CHROME_REFLEXION;
	material.refraction = CHROME_REFRACTION;
	material.ior = CHROME_IOR;
	material.property = REFLECTIVE;
	material.shadow = CHROME_SHADOW;
	return (material);
}

t_mat			new_plastic_material(void)
{
	t_mat		material;

	material.type = PLASTIC;
	material.diffuse = PLASTIC_DIFFUSE;
	material.specular = PLASTIC_SPECULAR;
	material.shininess = PLASTIC_SHININESS;
	material.reflexion = PLASTIC_REFLEXION;
	material.refraction = PLASTIC_REFRACTION;
	material.ior = PLASTIC_IOR;
	material.property = REFLECTIVE;
	material.shadow = PLASTIC_SHADOW;
	return (material);
}
