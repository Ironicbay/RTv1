/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:23:32 by acostaz           #+#    #+#             */
/*   Updated: 2019/06/24 14:17:49 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void				if_no_lights(t_env *e)
{
	if (!(e->light_list))
	{
		list_light_append(e);
		default_light(e->light_list);
		ft_putendl("No lights specified");
	}
}

void				add_coords(t_point *point, char *line)
{
	int				i;

	i = 0;
	point->x = ft_atof(line);
	while (line[i])
		if (line[i++] == ' ')
		{
			point->y = ft_atof(line + i);
			break ;
		}
	while (line[i] != ' ')
		i++;
	point->z = ft_atof(line + i);
}

void				add_color(t_color *color, char *line)
{
	int				i;

	color->channel[3] = 0;
	i = 0;
	color->channel[2] = abs(ft_atoi(line)) % 256;
	while (line[i])
		if (line[i++] == ' ')
		{
			color->channel[1] = abs(ft_atoi(line + i)) % 256;
			break ;
		}
	while (line[i] != ' ')
		i++;
	color->channel[0] = abs(ft_atoi(line + i)) % 256;
}

void				add_normal(t_vect *normal, char *line)
{
	int				i;

	i = 0;
	normal->x = ft_atof(line);
	while (line[i])
		if (line[i++] == ' ')
		{
			normal->y = ft_atof(line + i);
			break ;
		}
	while (line[i] != ' ')
		i++;
	normal->z = ft_atof(line + i);
	*normal = norm_vector(*normal);
}

void				choose_material(t_env *e, t_obj_list *obj, char *str)
{
	int				i;

	i = 0;
	while (i < 24 && ft_strcmp(e->name_material[i], str))
		i++;
	if (i != 24)
		e->choose_material[i](obj);
	else
	{
		ft_putstr("Wrong color : ");
		ft_putendl(str);
		ft_putendl("Putting silver color as default");
	}
}
