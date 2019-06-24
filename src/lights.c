/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:12:15 by acostaz           #+#    #+#             */
/*   Updated: 2019/06/13 16:00:52 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void			compute_shading(t_env *e, t_ray shadow_ray, t_surface *surface)
{
	double		theta;

	if (surface->obj->type == 2
			&& ((t_cylinder*)surface->obj->object)->origin.z == e->focus.z
			&& e->focus.z == e->cam.z)
	{
		((t_cylinder*)surface->obj->object)->origin.x +=
			((t_cylinder*)surface->obj->object)->direction.x;
		((t_cylinder*)surface->obj->object)->origin.y +=
			((t_cylinder*)surface->obj->object)->direction.y;
		((t_cylinder*)surface->obj->object)->origin.z +=
			((t_cylinder*)surface->obj->object)->direction.z + EPS;
	}
	e->pass_normal[surface->obj->type](surface);
	theta = fabs(dot_product(shadow_ray.vector, surface->normal));
	surface->mat.diffuse = vect_scal_op(surface->obj->mat.diffuse, theta, '*');
}

void			compute_shadow(t_env *e, t_ray shadow_ray,
		t_surface *surface, t_point light)
{
	t_obj_list	*lst_ptr;
	double		dist_inter_spot;
	t_surface	tmp_surface;

	lst_ptr = e->obj_list;
	dist_inter_spot = distance(surface->intersection, light);
	while (lst_ptr)
	{
		tmp_surface = e->pass_inter[lst_ptr->type](lst_ptr, shadow_ray);
		if (dist_inter_spot > tmp_surface.t && tmp_surface.t > EPS)
		{
			surface->shadow = 1;
			break ;
		}
		else
			surface->shadow = 0;
		lst_ptr = lst_ptr->next;
	}
}

void			compute_shine(t_ray shadow_ray, t_ray ray, t_surface *surface)
{
	double		theta;
	t_vect		refl;

	refl = vect_op(vect_scal_op(vect_scal_op(surface->normal,
					dot_product(surface->normal, shadow_ray.vector), '*'),
				2, '*'), shadow_ray.vector, '-');
	theta = dot_product(refl, vect_scal_op(ray.vector, -1, '*'));
	if (theta < 0)
		theta = 0;
	theta = pow(theta, surface->obj->mat.shine);
	if (theta > 0)
		surface->mat.specular = vect_scal_op(surface->obj->mat.specular, theta,
				'*');
	else
	{
		surface->mat.specular.x = 0;
		surface->mat.specular.y = 0;
		surface->mat.specular.z = 0;
	}
}
