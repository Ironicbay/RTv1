/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 09:52:14 by avanhers          #+#    #+#             */
/*   Updated: 2019/06/04 09:55:19 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

t_vect	vect_scal_op(t_vect u, double a, char op)
{
	t_vect res;

	if (op == '*')
	{
		res.x = a * u.x;
		res.y = a * u.y;
		res.z = a * u.z;
	}
	if (op == '/')
	{
		res.x = u.x / a;
		res.y = u.y / a;
		res.z = u.z / a;
	}
	if (op == '+')
	{
		res.x = u.x + a;
		res.y = u.y + a;
		res.z = u.z + a;
	}
	return (res);
}
