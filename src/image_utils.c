/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:19:24 by acostaz           #+#    #+#             */
/*   Updated: 2019/06/19 11:37:40 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void		image_put_pixel(char *img_data, t_pixel pos, int width, int color)
{
	if (pos.i >= 0 && pos.i < WIN_W && pos.j >= 0 && pos.j < WIN_H)
		*(int *)&img_data[(pos.j * width) + (pos.i * 4)] = color;
}

void		print_usage(void)
{
	ft_putendl("Zero of several arguments given");
	exit(EXIT_FAILURE);
}

void		create_image(t_env *e)
{
	if (!((e->img.img_addr = mlx_new_image(e->mlx, WIN_W, WIN_H))))
		list_del(e, 7);
	e->img.image = mlx_get_data_addr(e->img.img_addr, &e->img.bpp,\
			&e->img.size_line, &e->img.endian);
	if (!(e->img.image))
		list_del(e, 2);
}
