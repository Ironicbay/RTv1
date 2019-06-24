/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 11:38:40 by acostaz           #+#    #+#             */
/*   Updated: 2019/06/24 14:58:45 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"
#include <fcntl.h>

void				free_line_and_exit(t_env *e, char **line)
{
	free(*line);
	list_del(e, 4);
}

void				make_object(t_env *e, char **line)
{
	free(*line);
	if (get_next_line(e->fd, line) < 0)
		ft_error("GNL error");
	if (ft_strnequ(*line, "	type = sphere", 14))
		make_sphere(e, line);
	if (ft_strnequ(*line, "	type = plane", 13))
		make_plane(e, line);
	if (ft_strnequ(*line, "	type = cylinder", 16))
		make_cylinder(e, line);
	if (ft_strnequ(*line, "	type = cone", 12))
		make_cone(e, line);
	if (!ft_strequ(*line, "end_object"))
		free_line_and_exit(e, line);
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
	if (get_next_line(e->fd, &line) < 0)
		ft_error("GNL error");
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
		if (ft_strequ(line, "end_object") || ft_strequ(line, "end_light"))
			free_line_and_exit(e, &line);
		if (ft_strequ(line, "focus"))
			make_focus(e, &line);
		if (ft_strequ(line, "light"))
			make_light(e, &line);
		if (ft_strequ(line, "object"))
			make_object(e, &line);
		free(line);
	}
	free(line);
	if_no_lights(e);
	check_value_sizes(e);
}
