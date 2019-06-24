/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:05:19 by acostaz           #+#    #+#             */
/*   Updated: 2019/06/12 16:01:43 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

t_screen	init_screen(t_point cam, double dist, t_base base)
{
	t_screen result;

	result.heigth = 2 * dist * tan(0.785398);
	result.width = result.heigth * WIN_W / WIN_H;
	result.center.x = cam.x - base.n.x * dist;
	result.center.y = cam.y - base.n.y * dist;
	result.center.z = cam.z - base.n.z * dist;
	result.point1.x = result.center.x - (base.u.x * result.width) / 2
		- (base.v.x * result.heigth) / 2;
	result.point1.y = result.center.y - (base.u.y * result.width) / 2
		- (base.v.y * result.heigth) / 2;
	result.point1.z = result.center.z - (base.u.z * result.width) / 2
		- (base.v.z * result.heigth) / 2;
	return (result);
}

t_point		pixel_to_point(t_pixel p, t_base base, t_screen screen)
{
	t_point result;

	result.x = screen.point1.x + base.u.x * p.i * screen.width / WIN_W
		+ base.v.x * p.j * screen.heigth / WIN_H;
	result.y = screen.point1.y + base.u.y * p.i * screen.width / WIN_W
		+ base.v.y * p.j * screen.heigth / WIN_H;
	result.z = screen.point1.z + base.u.z * p.i * screen.width / WIN_W
		+ base.v.z * p.j * screen.heigth / WIN_H;
	return (result);
}

void		*make_everything(void *e)
{
	t_pixel		p;
	t_point		pixel;
	t_ray		ray;
	t_surface	surface;

	ray.point = ((t_env*)e)->cam;
	p.j = 0;
	while (p.j < NB_THREADS && pthread_self() != ((t_env*)e)->threads[p.j])
		p.j++;
	while (p.j < WIN_H && (p.i = -1))
	{
		while (++p.i < WIN_W)
		{
			pixel = pixel_to_point(p, ((t_env*)e)->base_cam,
					((t_env*)e)->screen);
			ray.vector = norm_vector(make_vector(((t_env*)e)->cam, pixel));
			surface = hit_object((t_env*)e, ray);
			if (surface.t < HUGE)
				image_put_pixel(((t_env*)e)->img.image, p,
						((t_env*)e)->img.size_line, surface.color.number);
		}
		p.j += NB_THREADS;
	}
	pthread_exit(0);
}
