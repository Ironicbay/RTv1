/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 14:20:36 by avanhers          #+#    #+#             */
/*   Updated: 2019/06/12 10:43:02 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

double		solve_quadratic(double a, double b, double c)
{
	double	delta;
	t_tuple	res;

	res.a = -1;
	res.b = -1;
	delta = b * b - 4 * a * c;
	if (delta >= 0)
	{
		res.a = (-b - sqrt(delta)) / (2 * a);
		res.b = (-b + sqrt(delta)) / (2 * a);
	}
	if (res.a > EPS && res.b > EPS)
		return (res.a < res.b ? res.a : res.b);
	if (res.a < EPS && res.b > EPS)
		return (res.b);
	if (res.a > EPS && res.b < EPS)
		return (res.a);
	return (-1);
}

double		distance(t_point a, t_point b)
{
	double	result;

	result = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)
			+ (a.z - b.z) * (a.z - b.z));
	return (result);
}

/*
** the base camera is an orthonormal base, with :
** u points to the right of the camera
** v points up from the camera
** m points backward; -n is the center of view
*/

t_base		create_base_cam(t_point cam, t_point coi)
{
	t_base	result;
	t_vect	v_up;

	v_up.x = 0;
	v_up.y = 0;
	v_up.z = -1;
	if (cam.x == coi.x && cam.y == coi.y)
		coi.x += EPS;
	result.origin = cam;
	result.n = make_vector(coi, cam);
	result.n = norm_vector(result.n);
	result.u = vect_product(v_up, result.n);
	result.u = norm_vector(result.u);
	result.v = vect_product(result.n, result.u);
	return (result);
}

/*
**This function give the new coordinate of the point p in the base b
*/

t_point		coord_new_base(t_point p, t_base b)
{
	t_point result;

	result.x = b.u.x * p.x + b.v.x * p.y + b.n.x * p.z;
	result.y = b.u.y * p.x + b.v.y * p.y + b.n.y * p.z;
	result.z = b.u.z * p.x + b.v.z * p.y + b.n.z * p.z;
	return (result);
}
