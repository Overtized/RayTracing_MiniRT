/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:34:53 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:24:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_point	make_point(float x, float y, float z, int hex_color)
{
	t_point	point;

	point.p.x = x;
	point.p.y = y;
	point.p.z = z;
	point.p.w = 1;
	point.color.hex = hex_color;
	point.color.r = (hex_color >> 16) & 0xFF;
	point.color.g = (hex_color >> 8) & 0xFF;
	point.color.b = hex_color & 0xFF;
	point.error = false;
	return (point);
}

t_point	make_point_error(void)
{
	t_point	point;

	ft_memset(&point, 0, sizeof(t_point));
	point.error = true;
	return (point);
}

t_point	copy_point(t_point point_a)
{
	t_point	point_b;

	point_b.color = point_a.color;
	point_b.p.w = point_a.p.w;
	point_b.p.x = point_a.p.x;
	point_b.p.y = point_a.p.y;
	point_b.p.z = point_a.p.z;
	point_b.error = point_a.error;
	return (point_b);
}
