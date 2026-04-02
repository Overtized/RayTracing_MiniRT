/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tupple_vec_product.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:32:37 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:24:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	tupple_dot_product(t_point a, t_point b)
{
	double	result;

	result = (a.p.x * b.p.x) + (a.p.y * b.p.y) + (a.p.z * b.p.z);
	return (result);
}

double	vec3_dot_product(t_vec3 a, t_vec3 b)
{
	double	result;

	result = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	return (result);
}

t_vec3	vec3_cross_product(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

t_point	cross_product(t_point a, t_point b)
{
	t_point	result;

	result.p.w = 0;
	result.p.x = a.p.y * b.p.z - a.p.z * b.p.y;
	result.p.y = a.p.z * b.p.x - a.p.x * b.p.z;
	result.p.z = a.p.x * b.p.y - a.p.y * b.p.x;
	result.color = a.color;
	return (result);
}

double	custom_pow(double base, float exposant)
{
	double	res;
	int		i;

	if (exposant == 0)
		return (1.0);
	if (base == 0)
		return (0.0);
	res = 1.0;
	i = 0;
	while (i < (int)exposant)
	{
		res = base * base;
		i++;
	}
	return (res);
}
