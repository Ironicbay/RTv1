/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:03:32 by avanhers          #+#    #+#             */
/*   Updated: 2019/06/12 13:07:19 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void			material_green_rubber(t_obj_list *obj)
{
	obj->mat.ambient.x = 0.0;
	obj->mat.ambient.y = 0.05;
	obj->mat.ambient.z = 0.0;
	obj->mat.diffuse.x = 0.4;
	obj->mat.diffuse.y = 0.5;
	obj->mat.diffuse.z = 0.4;
	obj->mat.specular.x = 0.04;
	obj->mat.specular.y = 0.7;
	obj->mat.specular.z = 0.04;
	obj->mat.shine = 10;
}

void			material_red_rubber(t_obj_list *obj)
{
	obj->mat.ambient.x = 0.05;
	obj->mat.ambient.y = 0.0;
	obj->mat.ambient.z = 0.0;
	obj->mat.diffuse.x = 0.5;
	obj->mat.diffuse.y = 0.4;
	obj->mat.diffuse.z = 0.4;
	obj->mat.specular.x = 0.7;
	obj->mat.specular.y = 0.04;
	obj->mat.specular.z = 0.04;
	obj->mat.shine = 10;
}

void			material_white_rubber(t_obj_list *obj)
{
	obj->mat.ambient.x = 0.05;
	obj->mat.ambient.y = 0.05;
	obj->mat.ambient.z = 0.05;
	obj->mat.diffuse.x = 0.5;
	obj->mat.diffuse.y = 0.5;
	obj->mat.diffuse.z = 0.5;
	obj->mat.specular.x = 0.7;
	obj->mat.specular.y = 0.7;
	obj->mat.specular.z = 0.7;
	obj->mat.shine = 10;
}

void			material_yellow_rubber(t_obj_list *obj)
{
	obj->mat.ambient.x = 0.05;
	obj->mat.ambient.y = 0.05;
	obj->mat.ambient.z = 0.0;
	obj->mat.diffuse.x = 0.5;
	obj->mat.diffuse.y = 0.5;
	obj->mat.diffuse.z = 0.4;
	obj->mat.specular.x = 0.7;
	obj->mat.specular.y = 0.7;
	obj->mat.specular.z = 0.04;
	obj->mat.shine = 10;
}
