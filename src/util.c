/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:57:17 by avanhers          #+#    #+#             */
/*   Updated: 2019/06/14 11:12:38 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

double				deg_to_rad(double angle)
{
	angle = (double)((int)(angle) % 180);
	angle *= M_PI;
	angle /= 180.0;
	return (angle);
}

t_point				vect_to_point(t_vect u)
{
	t_point	p;

	p.x = u.x;
	p.y = u.y;
	p.z = u.z;
	return (p);
}

t_vect				point_to_vect(t_point p)
{
	t_vect	u;

	u.x = p.x;
	u.y = p.y;
	u.z = p.z;
	return (u);
}

int					check_object_sizes(t_obj_list *obj)
{
	if ((obj->type == 0 && (fabs(((t_sphere*)obj->object)->origin.x) > MAX
					|| fabs(((t_sphere*)obj->object)->origin.y) > MAX
					|| fabs(((t_sphere*)obj->object)->origin.z) > MAX
					|| ((t_sphere*)obj->object)->radius > MAX))
			|| (obj->type == 1 && (fabs(((t_plane*)obj->object)->origin.x) > MAX
					|| fabs(((t_plane*)obj->object)->origin.y) > MAX
					|| fabs(((t_plane*)obj->object)->origin.z) > MAX
					|| fabs(((t_plane*)obj->object)->normal.x) > MAX
					|| fabs(((t_plane*)obj->object)->normal.y) > MAX
					|| fabs(((t_plane*)obj->object)->normal.z) > MAX))
			|| (obj->type == 2 && (fabs(((t_cone*)obj->object)->origin.x) > MAX
					|| fabs(((t_cone*)obj->object)->origin.y) > MAX
					|| fabs(((t_cone*)obj->object)->origin.z) > MAX
					|| fabs(((t_cone*)obj->object)->direction.x) > MAX
					|| fabs(((t_cone*)obj->object)->direction.y) > MAX
					|| fabs(((t_cone*)obj->object)->direction.z) > MAX))
			|| (obj->type == 3 && (fabs(((t_cylinder*)obj->object)->origin.x)
					> MAX || fabs(((t_cylinder*)obj->object)->origin.y) > MAX
					|| fabs(((t_cylinder*)obj->object)->origin.z) > MAX
					|| fabs(((t_cylinder*)obj->object)->direction.x) > MAX
					|| fabs(((t_cylinder*)obj->object)->direction.y) > MAX
					|| fabs(((t_cylinder*)obj->object)->direction.z) > MAX
					|| ((t_cylinder*)obj->object)->radius > MAX)))
		return (0);
	return (1);
}

void				check_value_sizes(t_env *e)
{
	t_light_list	*light;
	t_obj_list		*obj;

	light = e->light_list;
	obj = e->obj_list;
	if (fabs(e->cam.x) > MAX || fabs(e->cam.y) > MAX || fabs(e->cam.z) > MAX
			|| fabs(e->focus.x) > MAX || fabs(e->focus.y) > MAX
			|| fabs(e->focus.z) > MAX)
		list_del(e, 3);
	while (light)
	{
		if (light->origin.x > MAX || light->origin.y > MAX
				|| light->origin.z > MAX)
			list_del(e, 3);
		light = light->next;
	}
	while (obj)
	{
		if (!check_object_sizes(obj))
			list_del(e, 3);
		obj = obj->next;
	}
}
