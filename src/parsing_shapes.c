/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_shapes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:23:39 by acostaz           #+#    #+#             */
/*   Updated: 2019/06/13 15:10:08 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void				make_cone(t_env *e, char **line)
{
	t_obj_list		*obj;

	list_append(e, "cone");
	obj = e->obj_list;
	while (obj->next)
		obj = obj->next;
	default_cone(((t_cone*)obj->object));
	free(*line);
	while (get_next_line(e->fd, line) > 0 && !ft_strequ(*line, "end_object")
			&& !ft_strequ(*line, "object"))
	{
		if (ft_strnequ(*line, "	origin = ", 10))
			add_coords(&((t_cone*)obj->object)->origin, *line + 10);
		if (ft_strnequ(*line, "	direction = ", 13))
			add_normal(&((t_cone*)obj->object)->direction, *line + 13);
		if (ft_strnequ(*line, "	angle = ", 9))
			((t_cone*)((obj)->object))->angle = deg_to_rad(ft_atof(*line + 9));
		if (ft_strnequ(*line, "	material = ", 12))
			choose_material(e, obj, *line + 12);
		if (ft_strnequ(*line, "	rotation = ", 12))
			rotate(&((t_cone*)obj->object)->direction, *line + 12);
		if (ft_strnequ(*line, "	translation = ", 15))
			translate(&((t_cone*)obj->object)->origin, *line + 15);
		free(*line);
	}
}

void				make_cylinder(t_env *e, char **line)
{
	t_obj_list		*obj;

	list_append(e, "cylinder");
	obj = e->obj_list;
	while (obj->next)
		obj = obj->next;
	default_cylinder(((t_cylinder*)obj->object));
	free(*line);
	while (get_next_line(e->fd, line) > 0 && !ft_strequ(*line, "end_object")
			&& !ft_strequ(*line, "object"))
	{
		if (ft_strnequ(*line, "	origin = ", 10))
			add_coords(&((t_cylinder*)obj->object)->origin, *line + 10);
		if (ft_strnequ(*line, "	direction = ", 13))
			add_normal(&((t_cylinder*)obj->object)->direction, *line + 13);
		if (ft_strnequ(*line, "	radius = ", 10))
			((t_cylinder*)((obj)->object))->radius = fabs(ft_atof(*line + 10));
		if (ft_strnequ(*line, "	material = ", 12))
			choose_material(e, obj, *line + 12);
		if (ft_strnequ(*line, "	rotation = ", 12))
			rotate(&((t_cylinder*)obj->object)->direction, *line + 12);
		if (ft_strnequ(*line, "	translation = ", 15))
			translate(&((t_cylinder*)obj->object)->origin, *line + 15);
		free(*line);
	}
}

void				make_plane(t_env *e, char **line)
{
	t_obj_list		*obj;

	list_append(e, "plane");
	obj = e->obj_list;
	while (obj->next)
		obj = obj->next;
	default_plane(((t_plane*)obj->object));
	free(*line);
	while (get_next_line(e->fd, line) > 0 && !ft_strequ(*line, "end_object")
			&& !ft_strequ(*line, "object"))
	{
		if (ft_strnequ(*line, "	origin = ", 10))
			add_coords(&((t_plane*)obj->object)->origin, *line + 10);
		if (ft_strnequ(*line, "	normal = ", 10))
			add_normal(&((t_plane*)obj->object)->normal, *line + 10);
		if (ft_strnequ(*line, "	material = ", 12))
			choose_material(e, obj, *line + 12);
		if (ft_strnequ(*line, "	rotation = ", 12))
			rotate(&((t_plane*)obj->object)->normal, *line + 12);
		if (ft_strnequ(*line, "	translation = ", 15))
			translate(&((t_plane*)obj->object)->origin, *line + 15);
		free(*line);
	}
}

void				make_sphere(t_env *e, char **line)
{
	t_obj_list		*obj;

	list_append(e, "sphere");
	obj = e->obj_list;
	while (obj->next)
		obj = obj->next;
	default_sphere(((t_sphere*)obj->object));
	free(*line);
	while (get_next_line(e->fd, line) > 0 && !ft_strequ(*line, "end_object")
			&& !ft_strequ(*line, "object"))
	{
		if (ft_strnequ(*line, "	origin = ", 10))
			add_coords(&((t_sphere*)obj->object)->origin, *line + 10);
		if (ft_strnequ(*line, "	radius = ", 10))
			((t_sphere*)((obj)->object))->radius = fabs(ft_atof(*line + 10));
		if (ft_strnequ(*line, "	material = ", 12))
			choose_material(e, obj, *line + 12);
		if (ft_strnequ(*line, "	translation = ", 15))
			translate(&((t_sphere*)obj->object)->origin, *line + 15);
		free(*line);
	}
}
