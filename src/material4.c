/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 12:25:41 by avanhers          #+#    #+#             */
/*   Updated: 2019/06/12 13:07:40 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void			material_red_plastic(t_obj_list *obj)
{
	obj->mat.ambient.x = 0;
	obj->mat.ambient.y = 0;
	obj->mat.ambient.z = 0;
	obj->mat.diffuse.x = 0.5;
	obj->mat.diffuse.y = 0.0;
	obj->mat.diffuse.z = 0.0;
	obj->mat.specular.x = 0.7;
	obj->mat.specular.y = 0.6;
	obj->mat.specular.z = 0.6;
	obj->mat.shine = 32;
}

void			material_white_plastic(t_obj_list *obj)
{
	obj->mat.ambient.x = 0;
	obj->mat.ambient.y = 0;
	obj->mat.ambient.z = 0;
	obj->mat.diffuse.x = 0.55;
	obj->mat.diffuse.y = 0.55;
	obj->mat.diffuse.z = 0.55;
	obj->mat.specular.x = 0.70;
	obj->mat.specular.y = 0.70;
	obj->mat.specular.z = 0.70;
	obj->mat.shine = 32;
}

void			material_yellow_plastic(t_obj_list *obj)
{
	obj->mat.ambient.x = 0;
	obj->mat.ambient.y = 0;
	obj->mat.ambient.z = 0;
	obj->mat.diffuse.x = 0.5;
	obj->mat.diffuse.y = 0.5;
	obj->mat.diffuse.z = 0.0;
	obj->mat.specular.x = 0.60;
	obj->mat.specular.y = 0.60;
	obj->mat.specular.z = 0.50;
	obj->mat.shine = 32;
}

void			material_black_rubber(t_obj_list *obj)
{
	obj->mat.ambient.x = 0.02;
	obj->mat.ambient.y = 0.02;
	obj->mat.ambient.z = 0.02;
	obj->mat.diffuse.x = 0.01;
	obj->mat.diffuse.y = 0.01;
	obj->mat.diffuse.z = 0.01;
	obj->mat.specular.x = 0.4;
	obj->mat.specular.y = 0.4;
	obj->mat.specular.z = 0.4;
	obj->mat.shine = 10;
}

void			material_cyan_rubber(t_obj_list *obj)
{
	obj->mat.ambient.x = 0.0;
	obj->mat.ambient.y = 0.05;
	obj->mat.ambient.z = 0.05;
	obj->mat.diffuse.x = 0.4;
	obj->mat.diffuse.y = 0.5;
	obj->mat.diffuse.z = 0.5;
	obj->mat.specular.x = 0.04;
	obj->mat.specular.y = 0.7;
	obj->mat.specular.z = 0.7;
	obj->mat.shine = 10;
}
