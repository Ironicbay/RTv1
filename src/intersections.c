/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 13:48:38 by acostaz           #+#    #+#             */
/*   Updated: 2019/06/13 13:39:26 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

double		is_inter_line_cone(t_ray ray, t_cone cone)
{
	t_point	coeffs;
	double	cos_stock;
	double	delta;
	t_vect	co;

	cos_stock = cos(cone.angle) * cos(cone.angle);
	co = make_vector(cone.origin, ray.point);
	delta = dot_product(ray.vector, cone.direction);
	coeffs.x = delta * delta - cos_stock;
	coeffs.y = (2 * (delta * dot_product(co, cone.direction)
				- dot_product(ray.vector, co) * cos_stock));
	coeffs.z = dot_product(co, cone.direction) * dot_product(co, cone.direction)
		- (dot_product(co, co) * cos_stock);
	return (solve_quadratic(coeffs.x, coeffs.y, coeffs.z));
}

double		is_inter_line_plane(t_ray ray, t_plane plane)
{
	double	res;
	double	denominator;
	t_vect	difference;

	denominator = dot_product(plane.normal, ray.vector);
	if (fabs(denominator) > 0.0001)
	{
		difference = make_vector(ray.point, plane.origin);
		res = dot_product(difference, plane.normal) / denominator;
	}
	else
		res = -1;
	return (res > 0.0001 ? res : -1);
}

double		is_inter_line_sphere(t_ray ray, t_sphere sphere)
{
	t_vect	co;
	t_point coef;

	co = make_vector(sphere.origin, ray.point);
	coef.x = dot_product(ray.vector, ray.vector);
	coef.y = 2 * dot_product(co, ray.vector);
	coef.z = dot_product(co, co) - sphere.radius * sphere.radius;
	return (solve_quadratic(coef.x, coef.y, coef.z));
}

double		inter_cyl_general_case(t_ray ray, t_cylinder cyl, t_vect co,
		t_vect w)
{
	t_vect	wn;
	double	r;
	t_vect	e;
	double	s;
	double	t;

	wn = norm_vector(w);
	r = fabs(dot_product(co, wn));
	if (r > cyl.radius)
		return (-1);
	else
	{
		e = vect_product(co, cyl.direction);
		t = -dot_product(e, wn) / sqrt(dot_product(w, w));
		e = vect_product(wn, cyl.direction);
		e = norm_vector(e);
		s = fabs(sqrt(cyl.radius * cyl.radius - r * r) /
				dot_product(ray.vector, e));
		if (t - s > 0.0001)
			return (t - s);
		else if (t + s > 0.0001)
			return (t + s);
		return (-1);
	}
}

double		is_inter_line_cylinder(t_ray ray, t_cylinder cyl)
{
	t_vect	co;
	t_vect	w;

	cyl.direction = norm_vector(cyl.direction);
	co = make_vector(cyl.origin, ray.point);
	w = vect_product(ray.vector, cyl.direction);
	if (dot_product(w, w) == 0)
		return (-1);
	else
		return (inter_cyl_general_case(ray, cyl, co, w));
}
