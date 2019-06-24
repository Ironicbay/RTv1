/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:37:21 by acostaz           #+#    #+#             */
/*   Updated: 2019/06/24 16:32:49 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

int			process_win(void *param)
{
	t_env	*e;
	int		i;
	int		rc;

	e = (t_env*)param;
	i = -1;
	ft_bzero(e->img.image, WIN_W * WIN_H * 4);
	e->base_cam = create_base_cam(e->cam, e->focus);
	e->screen = init_screen(e->cam, 100, e->base_cam);
	while (++i < NB_THREADS)
	{
		if ((rc = pthread_create(&e->threads[i], NULL, make_everything, e)))
			ft_error("pthread_create error");
	}
	i = -1;
	while (++i < NB_THREADS)
		if (pthread_join(e->threads[i], NULL))
			ft_error("pthread_join error");
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_addr, 0, 0);
	return (0);
}

int			press_key(int key, void *param)
{
	t_env	*e;

	e = (t_env*)param;
	if (key == KEY_ESC)
		list_del(e, 0);
	if (key == KEY_PAD_1 || key == KEY_PAD_4)
		e->cam.x += key == KEY_PAD_4 ? 5 : -5;
	if (key == KEY_PAD_2 || key == KEY_PAD_5)
		e->cam.y += key == KEY_PAD_5 ? 5 : -5;
	if (key == KEY_PAD_3 || key == KEY_PAD_6)
		e->cam.z += key == KEY_PAD_6 ? 5 : -5;
	if (key >= KEY_PAD_1 && key <= KEY_PAD_6)
	{
		ft_putstr("(");
		ft_putnbr(e->cam.x);
		ft_putstr(", ");
		ft_putnbr(e->cam.y);
		ft_putstr(", ");
		ft_putnbr(e->cam.z);
		ft_putendl(")");
		process_win(e);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
		print_usage();
	init_material(e.choose_material);
	init_name_material(e.name_material);
	parsing(&e, av[1]);
	if (!((e.mlx = mlx_init())))
		list_del(&e, 5);
	if (!(e.win = mlx_new_window(e.mlx, WIN_W, WIN_H, "RTv1")))
		list_del(&e, 6);
	create_image(&e);
	init_pass_inter(e.pass_inter);
	init_get_normal(e.pass_normal);
	process_win(&e);
	mlx_hook(e.win, KEYPRESS, KEYPRESSMASK, press_key, &e);
	mlx_loop(e.mlx);
	return (0);
}
