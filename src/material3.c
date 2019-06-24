/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:04:57 by acostaz           #+#    #+#             */
/*   Updated: 2019/06/12 17:05:08 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void			material_gold(t_obj_list *obj)
{
	obj->mat.ambient.x = 0.24725;
	obj->mat.ambient.y = 0.19925;
	obj->mat.ambient.z = 0.07454;
	obj->mat.diffuse.x = 0.75164;
	obj->mat.diffuse.y = 0.60648;
	obj->mat.diffuse.z = 0.22648;
	obj->mat.specular.x = 0.628281;
	obj->mat.specular.y = 0.555802;
	obj->mat.specular.z = 0.366065;
	obj->mat.shine = 51.2;
}

void			material_silver(t_obj_list *obj)
{
	obj->mat.ambient.x = 0.19225;
	obj->mat.ambient.y = 0.19925;
	obj->mat.ambient.z = 0.19225;
	obj->mat.diffuse.x = 0.50754;
	obj->mat.diffuse.y = 0.50754;
	obj->mat.diffuse.z = 0.50754;
	obj->mat.specular.x = 0.508273;
	obj->mat.specular.y = 0.508273;
	obj->mat.specular.z = 0.508273;
	obj->mat.shine = 51.2;
}

void			material_black_plastic(t_obj_list *obj)
{
	obj->mat.ambient.x = 0.0;
	obj->mat.ambient.y = 0.0;
	obj->mat.ambient.z = 0.0;
	obj->mat.diffuse.x = 0.01;
	obj->mat.diffuse.y = 0.01;
	obj->mat.diffuse.z = 0.01;
	obj->mat.specular.x = 0.5;
	obj->mat.specular.y = 0.5;
	obj->mat.specular.z = 0.5;
	obj->mat.shine = 32;
}

void			material_cyan_plastic(t_obj_list *obj)
{
	obj->mat.ambient.x = 0.0;
	obj->mat.ambient.y = 0.1;
	obj->mat.ambient.z = 0.06;
	obj->mat.diffuse.x = 0.0;
	obj->mat.diffuse.y = 0.50980392;
	obj->mat.diffuse.z = 0.50980392;
	obj->mat.specular.x = 0.50196078;
	obj->mat.specular.y = 0.50196078;
	obj->mat.specular.z = 0.50196078;
	obj->mat.shine = 32;
}

void			material_green_plastic(t_obj_list *obj)
{
	obj->mat.ambient.x = 0.0;
	obj->mat.ambient.y = 0.10;
	obj->mat.ambient.z = 0.0;
	obj->mat.diffuse.x = 0.1;
	obj->mat.diffuse.y = 0.35;
	obj->mat.diffuse.z = 0.1;
	obj->mat.specular.x = 0.45;
	obj->mat.specular.y = 0.55;
	obj->mat.specular.z = 0.45;
	obj->mat.shine = 32;
}
