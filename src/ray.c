/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:22:02 by acostaz           #+#    #+#             */
/*   Updated: 2019/06/19 16:50:29 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

t_surface		first_hit(t_env *e, t_surface surface, t_ray ray)
{
	t_surface	tmp_surface;
	t_obj_list	*lst_ptr;

	lst_ptr = e->obj_list;
	while (lst_ptr)
	{
		tmp_surface = e->pass_inter[lst_ptr->type](lst_ptr, ray);
		if (surface.t > tmp_surface.t && tmp_surface.t > EPS)
		{
			surface.t = tmp_surface.t;
			surface.obj = lst_ptr;
		}
		lst_ptr = lst_ptr->next;
	}
	return (surface);
}

void			init_surface(t_surface *surface)
{
	surface->mat.diffuse.x = 0;
	surface->mat.diffuse.y = 0;
	surface->mat.diffuse.z = 0;
	surface->mat.ambient.x = 0;
	surface->mat.ambient.y = 0;
	surface->mat.ambient.z = 0;
	surface->mat.specular.x = 0;
	surface->mat.specular.y = 0;
	surface->mat.specular.z = 0;
	surface->shadow = 0;
	surface->color.number = 0;
}

void			get_surface_color(t_env *e, t_surface *surface, t_vect coef,
		t_light_list *light_ptr)
{
	surface->color.channel[2] += (coef.x < 1) ? coef.x *
		light_ptr->color.channel[2] / e->light_num
		: light_ptr->color.channel[2] / e->light_num;
	surface->color.channel[1] += (coef.y < 1) ? coef.y *
		light_ptr->color.channel[1] / e->light_num :
		light_ptr->color.channel[1] / e->light_num;
	surface->color.channel[0] += (coef.z < 1) ? coef.z *
		light_ptr->color.channel[0] / e->light_num :
		light_ptr->color.channel[0] / e->light_num;
}

void			compute_light(t_surface *surface, t_env *e,
		t_light_list *light_ptr, t_ray ray)
{
	t_ray		shadow_ray;
	t_vect		coef;

	if (ray.point.x == 0)
		ray.point.x = 0;
	surface->shadow = 0;
	surface->mat.ambient = surface->obj->mat.ambient;
	shadow_ray.point = surface->intersection;
	shadow_ray.vector = norm_vector(make_vector(surface->intersection,
				light_ptr->origin));
	compute_shading(e, shadow_ray, surface);
	compute_shine(shadow_ray, ray, surface);
	compute_shadow(e, shadow_ray, surface, light_ptr->origin);
	surface->mat.ambient = vect_scal_op(surface->mat.ambient,
			light_ptr->amb, '*');
	surface->mat.diffuse = vect_scal_op(surface->mat.diffuse,
			light_ptr->diff, '*');
	surface->mat.specular = vect_scal_op(surface->mat.specular,
			light_ptr->spec, '*');
	coef = vect_op(surface->mat.specular, surface->mat.diffuse, '+');
	coef = vect_scal_op(coef, 1 - surface->shadow, '*');
	coef = vect_op(coef, surface->mat.ambient, '+');
	get_surface_color(e, surface, coef, light_ptr);
}

t_surface		hit_object(t_env *e, t_ray ray)
{
	t_light_list	*light_ptr;
	t_surface		surface;

	surface.t = HUGE;
	surface.obj = NULL;
	light_ptr = e->light_list;
	surface = first_hit(e, surface, ray);
	init_surface(&surface);
	if (surface.obj)
	{
		surface.intersection = vect_to_point(vect_op(vect_scal_op(ray.vector,
						surface.t, '*'), point_to_vect(ray.point), '+'));
		light_ptr = e->light_list;
		while (light_ptr)
		{
			compute_light(&surface, e, light_ptr, ray);
			light_ptr = light_ptr->next;
		}
	}
	return (surface);
}
