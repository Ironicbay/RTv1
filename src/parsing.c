/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 11:38:40 by acostaz           #+#    #+#             */
/*   Updated: 2019/06/24 13:45:53 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"
#include <fcntl.h>

void				make_object(char **line, t_env *e)
{
	free(*line);
	get_next_line(e->fd, line);
	if (ft_strnequ(*line, "	type = sphere", 14))
		make_sphere(e, line);
	if (ft_strnequ(*line, "	type = plane", 13))
		make_plane(e, line);
	if (ft_strnequ(*line, "	type = cylinder", 16))
		make_cylinder(e, line);
	if (ft_strnequ(*line, "	type = cone", 12))
		make_cone(e, line);
	if (!ft_strequ(*line, "end_object"))
	{
		free(*line);
		list_del(e, 4);
	}
}

void				make_camera(t_env *e)
{
	char			*line;

	if (get_next_line(e->fd, &line) == -1)
		ft_error("Invalid file");
	if (!ft_strequ(line, "camera"))
	{
		free(line);
		ft_error("Invalid file");
	}
	free(line);
	get_next_line(e->fd, &line);
	if (ft_strnequ(line, "	origin = ", 10))
		add_coords(&e->cam, line + 10);
	else
	{
		free(line);
		ft_error("Wrong camera input");
	}
	free(line);
}

void				make_focus(t_env *e, char **line)
{
	free(*line);
	if (get_next_line(e->fd, line) < 0)
		ft_error("read error");
	if (ft_strnequ(*line, "	origin = ", 10))
		add_coords(&e->focus, *line + 10);
	else
	{
		free(*line);
		ft_error("Wrong focus input");
	}
}

void				make_light(t_env *e)
{
	char			*line;
	t_light_list	*light;

	list_light_append(e);
	light = e->light_list;
	while (light->next)
		light = light->next;
	default_light(light);
	while (get_next_line(e->fd, &line) > 0 && !ft_strequ(line, "end_light"))
	{
		if (ft_strnequ(line, "	origin = ", 10))
			add_coords(&(light->origin), line + 10);
		if (ft_strnequ(line, "	color = ", 9))
			add_color(&(light->color), line + 9);
		if (ft_strnequ(line, "	ambient = ", 10))
			light->amb = fabs(ft_atof(line + 10) - (double)ft_atoi(line + 10));
		if (ft_strnequ(line, "	diffuse = ", 10))
			light->diff = fabs(ft_atof(line + 10) - (double)ft_atoi(line + 10));
		if (ft_strnequ(line, "	specular = ", 11))
			light->spec = fabs(ft_atof(line + 11) - (double)ft_atoi(line + 11));
		free(line);
	}
	free(line);
}

void				parsing(t_env *e, char *arg)
{
	char			*line;

	if ((e->fd = open(arg, O_RDONLY)) < 0)
		ft_error("Invalid file");
	e->obj_list = NULL;
	e->light_list = NULL;
	make_camera(e);
	while (get_next_line(e->fd, &line) > 0)
	{
		if (ft_strequ(line, "focus"))
			make_focus(e, &line);
		if (ft_strequ(line, "light"))
			make_light(e);
		if (ft_strequ(line, "object"))
			make_object(&line, e);
		free(line);
	}
	free(line);
	if (!(e->light_list))
		ft_error("No lights :'(");
	check_value_sizes(e);
}
