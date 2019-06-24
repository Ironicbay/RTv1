/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:37:01 by avanhers          #+#    #+#             */
/*   Updated: 2019/06/13 13:39:48 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	get_normal_sphere(t_surface *surface)
{
	t_sphere	sphere;

	sphere = *(t_sphere*)surface->obj->object;
	surface->normal = norm_vector(make_vector(sphere.origin,
				surface->intersection));
}

void	get_normal_plane(t_surface *surface)
{
	t_plane	plane;

	plane = *(t_plane*)surface->obj->object;
	surface->normal = norm_vector(plane.normal);
}

void	get_normal_cylinder(t_surface *surface)
{
	t_cylinder	cyl;
	double		dist;
	t_point		op;
	t_vect		v1;
	t_vect		v2;

	cyl = *(t_cylinder*)surface->obj->object;
	dist = sqrt(dot_product(make_vector(cyl.origin, surface->intersection),
				make_vector(cyl.origin, surface->intersection)));
	dist = sqrt(dist * dist - cyl.radius * cyl.radius);
	op.x = cyl.origin.x + cyl.direction.x * dist;
	op.y = cyl.origin.y + cyl.direction.y * dist;
	op.z = cyl.origin.z + cyl.direction.z * dist;
	v1 = make_vector(op, surface->intersection);
	op.x = cyl.origin.x - cyl.direction.x * dist;
	op.y = cyl.origin.y - cyl.direction.y * dist;
	op.z = cyl.origin.z - cyl.direction.z * dist;
	v2 = make_vector(op, surface->intersection);
	if (sqrt(dot_product(v1, v1)) <= sqrt(dot_product(v2, v2)))
		surface->normal = norm_vector(v1);
	else
		surface->normal = norm_vector(v2);
}

void	get_normal_cone(t_surface *surface)
{
	t_cone		cone;
	double		dist;
	t_point		op;
	t_vect		v1;
	t_vect		v2;

	cone = *(t_cone*)surface->obj->object;
	dist = sqrt(dot_product(make_vector(cone.origin, surface->intersection),
				make_vector(cone.origin, surface->intersection)));
	dist = dist / cos(cone.angle);
	op.x = cone.origin.x + cone.direction.x * dist;
	op.y = cone.origin.y + cone.direction.y * dist;
	op.z = cone.origin.z + cone.direction.z * dist;
	v1 = make_vector(op, surface->intersection);
	op.x = cone.origin.x - cone.direction.x * dist;
	op.y = cone.origin.y - cone.direction.y * dist;
	op.z = cone.origin.z - cone.direction.z * dist;
	v2 = make_vector(op, surface->intersection);
	if (sqrt(dot_product(v1, v1)) < sqrt(dot_product(v2, v2)))
		surface->normal = norm_vector(v1);
	else
		surface->normal = norm_vector(v2);
}

void	init_get_normal(t_pass_normal func[4])
{
	func[0] = &get_normal_sphere;
	func[1] = &get_normal_plane;
	func[2] = &get_normal_cylinder;
	func[3] = &get_normal_cone;
}
