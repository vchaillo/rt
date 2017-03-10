/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_material.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:53:22 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/10 21:13:43 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_mat			new_marble_material(void)
{
	t_mat		material;

	material.type = MARBLE;
	material.diffuse = MARBLE_DIFFUSE;
	material.specular = MARBLE_SPECULAR;
	material.reflexion = MARBLE_REFLEXION;
	material.refraction = MARBLE_REFRACTION;
	return (material);
}

t_mat			new_glass_material(void)
{
	t_mat		material;

	material.type = GLASS;
	material.diffuse = GLASS_DIFFUSE;
	material.specular = GLASS_SPECULAR;
	material.reflexion = GLASS_REFLEXION;
	material.refraction = GLASS_REFRACTION;
	return (material);
}

t_mat			new_plastic_material(void)
{
	t_mat		material;

	material.type = PLASTIC;
	material.diffuse = PLASTIC_DIFFUSE;
	material.specular = PLASTIC_SPECULAR;
	material.reflexion = PLASTIC_REFLEXION;
	material.refraction = PLASTIC_REFRACTION;
	return (material);
}

t_mat			new_basic_material(void)
{
	t_mat		material;

	material.type = BASIC;
	material.diffuse = BASIC_DIFFUSE;
	material.specular = BASIC_SPECULAR;
	material.reflexion = BASIC_REFLEXION;
	material.refraction = BASIC_REFRACTION;
	return (material);
}

t_mat			new_material(int type)
{
	t_mat		material;

	if (type == BASIC)
		material = new_basic_material();
	else if (type == PLASTIC)
		material = new_plastic_material();
	else if (type == GLASS)
		material = new_glass_material();
	else
		material = new_marble_material();
	return (material);
}
