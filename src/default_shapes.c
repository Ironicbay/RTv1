/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_shapes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:44:37 by acostaz           #+#    #+#             */
/*   Updated: 2019/06/25 13:35:46 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	default_sphere(t_sphere *sphere)
{
	add_coords(&sphere->origin, "0 0 0");
	sphere->radius = 5;
}

void	default_plane(t_plane *plane)
{
	add_coords(&plane->origin, "0 0 0");
	add_normal(&plane->normal, "0 0 1");
}

void	default_cylinder(t_cylinder *cyl)
{
	add_coords(&cyl->origin, "0 0 0");
	add_normal(&cyl->direction, "0 0 1");
	cyl->radius = 3;
}

void	default_cone(t_cone *cone)
{
	add_coords(&cone->origin, "0 0 0");
	add_normal(&cone->direction, "0 0 1");
	cone->angle = deg_to_rad(15.0);
}

void	default_light(t_light_list *light)
{
	light->amb = 0.2;
	light->diff = 0.5;
	light->spec = 0.99;
	light->color.channel[0] = 255;
	light->color.channel[1] = 255;
	light->color.channel[2] = 255;
	light->origin.x = 50;
	light->origin.y = 50;
	light->origin.z = 50;
}
