/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 11:49:11 by avanhers          #+#    #+#             */
/*   Updated: 2019/06/12 17:04:09 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void			material_emerald(t_obj_list *obj)
{
	obj->mat.ambient.x = 0.0215;
	obj->mat.ambient.y = 0.1745;
	obj->mat.ambient.z = 0.0215;
	obj->mat.diffuse.x = 0.07568;
	obj->mat.diffuse.y = 0.61424;
	obj->mat.diffuse.z = 0.07568;
	obj->mat.specular.x = 0.633;
	obj->mat.specular.y = 0.727811;
	obj->mat.specular.z = 0.633;
	obj->mat.shine = 76.8;
}

void			material_jade(t_obj_list *obj)
{
	obj->mat.ambient.x = 0.135;
	obj->mat.ambient.y = 0.2225;
	obj->mat.ambient.z = 0.1575;
	obj->mat.diffuse.x = 0.54;
	obj->mat.diffuse.y = 0.89;
	obj->mat.diffuse.z = 0.63;
	obj->mat.specular.x = 0.316228;
	obj->mat.specular.y = 0.316228;
	obj->mat.specular.z = 0.316228;
	obj->mat.shine = 12.8;
}

void			material_obsidian(t_obj_list *obj)
{
	obj->mat.ambient.x = 0.05375;
	obj->mat.ambient.y = 0.05;
	obj->mat.ambient.z = 0.06625;
	obj->mat.diffuse.x = 0.18275;
	obj->mat.diffuse.y = 0.17;
	obj->mat.diffuse.z = 0.622525;
	obj->mat.specular.x = 0.332741;
	obj->mat.specular.y = 0.328634;
	obj->mat.specular.z = 0.346435;
	obj->mat.shine = 38.4;
}

void			material_pearl(t_obj_list *obj)
{
	obj->mat.ambient.x = 0.25;
	obj->mat.ambient.y = 0.20725;
	obj->mat.ambient.z = 0.20725;
	obj->mat.diffuse.x = 1;
	obj->mat.diffuse.y = 0.829;
	obj->mat.diffuse.z = 0.829;
	obj->mat.specular.x = 0.296648;
	obj->mat.specular.y = 0.296648;
	obj->mat.specular.z = 0.296648;
	obj->mat.shine = 11.264;
}

void			material_ruby(t_obj_list *obj)
{
	obj->mat.ambient.x = 0.1745;
	obj->mat.ambient.y = 0.01175;
	obj->mat.ambient.z = 0.01175;
	obj->mat.diffuse.x = 0.61424;
	obj->mat.diffuse.y = 0.04136;
	obj->mat.diffuse.z = 0.04136;
	obj->mat.specular.x = 0.727811;
	obj->mat.specular.y = 0.626959;
	obj->mat.specular.z = 0.626959;
	obj->mat.shine = 76.8;
}
