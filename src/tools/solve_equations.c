/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_equations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:07:17 by valentin          #+#    #+#             */
/*   Updated: 2017/03/14 19:32:46 by tlegroux         ###   ########.fr       */
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

/*
** eq = {e, d, c, b, a}
*/

double			solve_deg4(const double *eq)
{
  	int		nr;
	gsl_poly_complex_workspace	*workspace;
	double		r[8];
	int			i;
	double		result;
	double		root;

	gsl_set_error_handler (NULL);
	if (!(workspace = gsl_poly_complex_workspace_alloc(5)))
		print_error(MALLOC_ERROR);
	gsl_poly_complex_solve(eq, 5, workspace, r);
	//printf("%.18lf*x^4 + %.18lf*x^3 + %.18lf*x^2 + %.18lf*x + %.18lf = 0\n", eq[4], eq[3] , eq[2] , eq[1] , eq[0]);
	i = 0;
	nr = 0;
	while (i < 4)
	  {
	    if (r[(2 * i) + 1] == 0)
	      nr++;
	    i++;
	  }
	if (nr > 0)
	  result = DBL_MAX;
	else
	  return (DBL_MAX);
	i = 0;       
	while (i < 4)
	  {
	    if (r[(2 * i) + 1] == 0)
	      {
		root = r[2 * i];
       		//printf("%lf + i*%lf\n", r[2 * i], r[1 + 2*i]); 
		if (root > EPSILON && root < result)
		  result = root;
	      }
	    i++;
	  }
	//printf("result: %lf\n", result);
	gsl_poly_complex_workspace_free(workspace);
	return (result);
}
