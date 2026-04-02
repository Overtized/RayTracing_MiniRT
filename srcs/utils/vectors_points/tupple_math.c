/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tupple_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:34:17 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:24:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_point	scale_tupple(t_point a, double scalar)
{
	t_point	c;

	c.p.x = a.p.x * scalar;
	c.p.y = a.p.y * scalar;
	c.p.z = a.p.z * scalar;
	c.p.w = a.p.w;
	c.color = a.color;
	return (c);
}

t_point	divide_tupple(t_point a, double divider)
{
	t_point	c;

	c.p.x = a.p.x / divider;
	c.p.y = a.p.y / divider;
	c.p.z = a.p.z / divider;
	c.p.w = a.p.w;
	c.color = a.color;
	return (c);
}

double	get_tupple_magnitude(t_point a)
{
	return (sqrt((a.p.x * a.p.x) + (a.p.y * a.p.y)
			+ (a.p.z * a.p.z)));
}
