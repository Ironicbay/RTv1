/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:02:40 by acostaz           #+#    #+#             */
/*   Updated: 2019/06/24 15:46:50 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

/*
** error code 1 : malloc error in parsing
** error code 2 : mlx_get_data_addr error
** error code 3 : > 1000 error
** error code 4 : format error in input file
** error code 5 : mlx_init error
** error code 6 : mlx_new_window error
** error code 7 : mlx_new_image error
*/

void				close_program(t_env *e, int err)
{
	if (err != 1 && err != 4 && err != 5)
	{
		if (err != 6 && err != 7)
			mlx_destroy_image(e->mlx, e->img.img_addr);
		if (err != 6)
			mlx_destroy_window(e->mlx, e->win);
		mlx_del(e->mlx);
	}
	if (err == 0)
		exit(EXIT_SUCCESS);
	if (err == 1)
		ft_error("malloc error");
	if (err == 2 || err == 5 || err == 6 || err == 7)
		ft_error("mlx error");
	if (err == 3)
		ft_error("One or more values too big");
	if (err == 4)
		ft_error("Input file not well formated");
}

void				list_del(t_env *e, int err)
{
	t_obj_list		*parser;
	t_light_list	*parser_l;

	parser_l = e->light_list;
	while (parser_l)
	{
		parser_l = parser_l->next;
		free(e->light_list);
		e->light_list = parser_l;
	}
	e->light_list = NULL;
	parser = e->obj_list;
	while (parser)
	{
		parser = parser->next;
		free(e->obj_list->object);
		e->obj_list->object = NULL;
		free(e->obj_list);
		e->obj_list = parser;
	}
	e->obj_list = NULL;
	close_program(e, err);
}

void				alloc_type(t_env *e, t_obj_list *new, char *type)
{
	if (ft_strequ(type, "sphere"))
		if (!(new->object = (t_sphere*)malloc(sizeof(t_sphere)))
					|| (new->type = 0))
			list_del(e, 1);
	if (ft_strequ(type, "plane"))
		if (!(new->object = (t_plane*)malloc(sizeof(t_plane)))
				|| !(new->type = 1))
			list_del(e, 1);
	if (ft_strequ(type, "cylinder"))
		if (!(new->object = (t_cylinder*)malloc(sizeof(t_cylinder)))
				|| !(new->type = 2))
			list_del(e, 1);
	if (ft_strequ(type, "cone"))
		if (!(new->object = (t_cone*)malloc(sizeof(t_cone)))
				|| !(new->type = 3))
			list_del(e, 1);
}

void				list_append(t_env *e, char *type)
{
	t_obj_list		*new;
	t_obj_list		*stock;

	if (!(new = (t_obj_list*)malloc(sizeof(t_obj_list))))
		list_del(e, 1);
	alloc_type(e, new, type);
	choose_material(e, new, "silver");
	new->next = NULL;
	if (e->obj_list)
	{
		stock = e->obj_list;
		while (stock->next)
			stock = stock->next;
		stock->next = new;
	}
	else
		e->obj_list = new;
}

void				list_light_append(t_env *e)
{
	t_light_list	*new;
	t_light_list	*stock;

	if (!(new = (t_light_list*)malloc(sizeof(t_light_list))))
		list_del(e, 1);
	new->next = NULL;
	if (e->light_list)
	{
		stock = e->light_list;
		while (stock->next)
			stock = stock->next;
		stock->next = new;
		e->light_num++;
	}
	else
	{
		e->light_list = new;
		e->light_num = 1;
	}
}
