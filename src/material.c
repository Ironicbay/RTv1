/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 11:22:10 by avanhers          #+#    #+#             */
/*   Updated: 2019/06/12 17:03:36 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void	init_name_material(char *name_mat[24])
{
	name_mat[0] = "emerald";
	name_mat[1] = "jade";
	name_mat[2] = "obsidian";
	name_mat[3] = "pearl";
	name_mat[4] = "ruby";
	name_mat[5] = "turquoise";
	name_mat[6] = "brass";
	name_mat[7] = "bronze";
	name_mat[8] = "chrome";
	name_mat[9] = "copper";
	name_mat[10] = "gold";
	name_mat[11] = "silver";
	name_mat[12] = "black_plastic";
	name_mat[13] = "cyan_plastic";
	name_mat[14] = "green_plastic";
	name_mat[15] = "red_plastic";
	name_mat[16] = "white_plastic";
	name_mat[17] = "yellow_plastic";
	name_mat[18] = "black_rubber";
	name_mat[19] = "cyan_rubber";
	name_mat[20] = "green_rubber";
	name_mat[21] = "red_rubber";
	name_mat[22] = "white_rubber";
	name_mat[23] = "yellow_rubber";
}

void	init_material(t_f_material f_mat[24])
{
	f_mat[0] = &material_emerald;
	f_mat[1] = &material_jade;
	f_mat[2] = &material_obsidian;
	f_mat[3] = &material_pearl;
	f_mat[4] = &material_ruby;
	f_mat[5] = &material_turquoise;
	f_mat[6] = &material_brass;
	f_mat[7] = &material_bronze;
	f_mat[8] = &material_chrome;
	f_mat[9] = &material_copper;
	f_mat[10] = &material_gold;
	f_mat[11] = &material_silver;
	f_mat[12] = &material_black_plastic;
	f_mat[13] = &material_cyan_plastic;
	f_mat[14] = &material_green_plastic;
	f_mat[15] = &material_red_plastic;
	f_mat[16] = &material_white_plastic;
	f_mat[17] = &material_yellow_plastic;
	f_mat[18] = &material_black_rubber;
	f_mat[19] = &material_cyan_rubber;
	f_mat[20] = &material_green_rubber;
	f_mat[21] = &material_red_rubber;
	f_mat[22] = &material_white_rubber;
	f_mat[23] = &material_yellow_rubber;
}
