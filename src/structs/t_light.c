/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_light.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:41 by vchaillo          #+#    #+#             */
/*   Updated: 2017/01/12 23:02:24 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light			*new_light(int type, float intensity, t_vector v, t_color c)
{
	t_light		*new_light;

	if (!(new_light = (t_light*)malloc(sizeof(t_light))))
		print_error(MALLOC_ERROR);
	new_light->type = type;
	new_light->intensity = intensity;
	if (type == SPOT)
		new_light->pos = v;
	else
		new_light->dir = normalize(v);
	new_light->color = scalar_color(intensity, c);
	return (new_light);
}

void			add_light(t_scene *scene, t_light *new)
{
	if (scene->lights == NULL)
	{
		scene->lights = new;
		scene->lights->next = NULL;
	}
	else
	{
		new->next = scene->lights;
		scene->lights = new;
	}
	scene->nb_lights++;
}

void			delete_lights(t_light *lights)
{
	t_light		*tmp;

	while (lights != NULL)
	{
		tmp = lights->next;
		lights->next = NULL;
		free(lights);
		lights = tmp;
	}
}
