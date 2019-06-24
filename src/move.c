/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 11:52:38 by avanhers          #+#    #+#             */
/*   Updated: 2019/06/13 14:50:23 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void		translate(t_point *initial, char *line)
{
	t_vect	u;
	int		i;

	i = 0;
	u.x = ft_atof(line);
	while (line[i])
		if (line[i++] == ' ')
		{
			u.y = ft_atof(line + i);
			break ;
		}
	while (line[i] != ' ')
		i++;
	u.z = ft_atof(line + i);
	initial->x += u.x;
	initial->y += u.y;
	initial->z += u.z;
}

static void	rotate_y(t_vect *original, double theta)
{
	double	tmp_x;

	theta = deg_to_rad(theta);
	tmp_x = original->x * cos(theta) + original->z * sin(theta);
	original->z = -original->x * sin(theta) + original->z * cos(theta);
	original->x = tmp_x;
}

static void	rotate_x(t_vect *original, double theta)
{
	double	tmp_y;

	theta = deg_to_rad(theta);
	tmp_y = original->y * cos(theta) + original->z * sin(theta);
	original->z = -original->y * sin(theta) + original->z * cos(theta);
	original->y = tmp_y;
}

static void	rotate_z(t_vect *original, double theta)
{
	double	tmp_x;

	theta = deg_to_rad(theta);
	tmp_x = original->x * cos(theta) - original->y * sin(theta);
	original->y = original->x * sin(theta) + original->y * cos(theta);
	original->x = tmp_x;
}

void		rotate(t_vect *original, char *line)
{
	t_vect	theta;
	int		i;

	i = 0;
	theta.x = ft_atof(line);
	while (line[i])
		if (line[i++] == ' ')
		{
			theta.y = ft_atof(line + i);
			break ;
		}
	while (line[i] != ' ')
		i++;
	theta.z = ft_atof(line + i);
	rotate_x(original, theta.x);
	rotate_y(original, theta.y);
	rotate_z(original, theta.z);
}
