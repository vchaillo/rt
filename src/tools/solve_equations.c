/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_equations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:07:17 by valentin          #+#    #+#             */
/*   Updated: 2017/03/13 19:57:26 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float			solve_deg2(double a, double b, double c)
{
	float		delta;
	float		res;
	float		x1;
	float		x2;

	delta = (b * b) - (4 * a * c);
	if (delta > 0)
	{
		x1 = (-b - sqrt(delta)) / (2 * a);
		x2 = (-b + sqrt(delta)) / (2 * a);
		if (x1 > EPSILON)
		{
			res = x1;
			return (res);
		}
		if (x1 < x2)
			res = x1;
		else
			res = x2;
	}
	else if (delta == 0)
		res = -b / (2 * a);
	else
		res = 0;
	return (res);
}

double			solve_deg4(const double *eq)
{
	gsl_poly_complex_workspace	*workspace;
	double		r[8];
	int			i;
	double		result;

	if (!(workspace = gsl_poly_complex_workspace_alloc(5)))
		return (DBL_MIN);
	gsl_poly_complex_solve(eq, 5, workspace, r);
	result = DBL_MAX;
	i = 0;	
	while (i < 4)
	{
		if (!r[2 * i + 1])
		{
			if (r[2 * i] > EPSILON && r[2 * i] < result)
				result = r[2 * i];
		}
		i++;
	}
	gsl_poly_complex_workspace_free(workspace);
	return (result);
}
