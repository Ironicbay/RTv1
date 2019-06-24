/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 12:11:04 by avanhers          #+#    #+#             */
/*   Updated: 2019/06/12 17:04:24 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void			material_turquoise(t_obj_list *obj)
{
	obj->mat.ambient.x = 0.1;
	obj->mat.ambient.y = 0.18725;
	obj->mat.ambient.z = 0.1745;
	obj->mat.diffuse.x = 0.396;
	obj->mat.diffuse.y = 0.74151;
	obj->mat.diffuse.z = 0.69102;
	obj->mat.specular.x = 0.297254;
	obj->mat.specular.y = 0.30829;
	obj->mat.specular.z = 0.306678;
	obj->mat.shine = 12.8;
}

void			material_brass(t_obj_list *obj)
{
	obj->mat.ambient.x = 0.329412;
	obj->mat.ambient.y = 0.223529;
	obj->mat.ambient.z = 0.027451;
	obj->mat.diffuse.x = 0.780392;
	obj->mat.diffuse.y = 0.568627;
	obj->mat.diffuse.z = 0.113725;
	obj->mat.specular.x = 0.992157;
	obj->mat.specular.y = 0.941176;
	obj->mat.specular.z = 0.807843;
	obj->mat.shine = 27.89;
}

void			material_bronze(t_obj_list *obj)
{
	obj->mat.ambient.x = 0.2125;
	obj->mat.ambient.y = 0.1275;
	obj->mat.ambient.z = 0.054;
	obj->mat.diffuse.x = 0.714;
	obj->mat.diffuse.y = 0.4284;
	obj->mat.diffuse.z = 0.18144;
	obj->mat.specular.x = 0.393548;
	obj->mat.specular.y = 0.271906;
	obj->mat.specular.z = 0.166721;
	obj->mat.shine = 25.6;
}

void			material_chrome(t_obj_list *obj)
{
	obj->mat.ambient.x = 0.25;
	obj->mat.ambient.y = 0.25;
	obj->mat.ambient.z = 0.25;
	obj->mat.diffuse.x = 0.4;
	obj->mat.diffuse.y = 0.4;
	obj->mat.diffuse.z = 0.4;
	obj->mat.specular.x = 0.774597;
	obj->mat.specular.y = 0.774597;
	obj->mat.specular.z = 0.774597;
	obj->mat.shine = 76.8;
}

void			material_copper(t_obj_list *obj)
{
	obj->mat.ambient.x = 0.19125;
	obj->mat.ambient.y = 0.0735;
	obj->mat.ambient.z = 0.0225;
	obj->mat.diffuse.x = 0.7038;
	obj->mat.diffuse.y = 0.27048;
	obj->mat.diffuse.z = 0.0828;
	obj->mat.specular.x = 0.256777;
	obj->mat.specular.y = 0.1376622;
	obj->mat.specular.z = 0.086014;
	obj->mat.shine = 12.8;
}
