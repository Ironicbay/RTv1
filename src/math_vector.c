/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 14:16:17 by avanhers          #+#    #+#             */
/*   Updated: 2019/06/11 15:58:54 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

t_vect	make_vector(t_point a, t_point b)
{
	t_vect	result;

	result.x = b.x - a.x;
	result.y = b.y - a.y;
	result.z = b.z - a.z;
	return (result);
}

double	dot_product(t_vect u, t_vect v)
{
	double result;

	result = u.x * v.x + u.y * v.y + u.z * v.z;
	return (result);
}

t_vect	vect_product(t_vect u, t_vect v)
{
	t_vect result;

	result.x = u.y * v.z - v.y * u.z;
	result.y = u.z * v.x - v.z * u.x;
	result.z = u.x * v.y - v.x * u.y;
	return (result);
}

t_vect	norm_vector(t_vect u)
{
	t_vect	result;
	double	length;

	length = sqrt(dot_product(u, u));
	result.x = u.x / length;
	result.y = u.y / length;
	result.z = u.z / length;
	return (result);
}

t_vect	vect_op(t_vect u, t_vect v, char op)
{
	t_vect	res;

	if (op == '+')
	{
		res.x = u.x + v.x;
		res.y = u.y + v.y;
		res.z = u.z + v.z;
	}
	if (op == '-')
	{
		res.x = u.x - v.x;
		res.y = u.y - v.y;
		res.z = u.z - v.z;
	}
	if (op == '*')
	{
		res.x = u.x * v.x;
		res.y = u.y * v.y;
		res.z = u.z * v.z;
	}
	return (res);
}
