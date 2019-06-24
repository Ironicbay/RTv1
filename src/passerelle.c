/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passerelle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 09:41:27 by avanhers          #+#    #+#             */
/*   Updated: 2019/06/19 16:51:24 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

t_surface		passerelle_sphere(t_obj_list *lst_ptr, t_ray ray)
{
	t_surface	surface;
	t_sphere	sphere;

	sphere = *(t_sphere*)lst_ptr->object;
	surface.t = is_inter_line_sphere(ray, sphere);
	return (surface);
}

t_surface		passerelle_plane(t_obj_list *lst_ptr, t_ray ray)
{
	t_surface	surface;
	t_plane		plane;

	plane = *(t_plane*)lst_ptr->object;
	surface.t = is_inter_line_plane(ray, plane);
	return (surface);
}

t_surface		passerelle_cylinder(t_obj_list *lst_ptr, t_ray ray)
{
	t_surface	surface;
	t_cylinder	cylinder;

	cylinder = *(t_cylinder*)lst_ptr->object;
	surface.t = is_inter_line_cylinder(ray, cylinder);
	return (surface);
}

t_surface		passerelle_cone(t_obj_list *lst_ptr, t_ray ray)
{
	t_surface	surface;
	t_cone		cone;
	t_point		inter;

	cone = *(t_cone*)lst_ptr->object;
	surface.t = is_inter_line_cone(ray, cone);
	inter = vect_to_point(vect_op(vect_scal_op(ray.vector,
		surface.t, '*'), point_to_vect(ray.point), '+'));
	if (inter.x < cone.origin.x + EPS && inter.x > cone.origin.x - EPS
			&& inter.y < cone.origin.y + EPS && inter.y > cone.origin.y - EPS
			&& inter.z < cone.origin.z + EPS && inter.z > cone.origin.z - EPS)
		surface.t = HUGE;
	return (surface);
}

void			init_pass_inter(t_passerelle func[4])
{
	func[0] = &passerelle_sphere;
	func[1] = &passerelle_plane;
	func[2] = &passerelle_cylinder;
	func[3] = &passerelle_cone;
}
