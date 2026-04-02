/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tupples_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 23:49:04 by lchiche           #+#    #+#             */
/*   Updated: 2026/03/28 15:24:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_point	negate_tupple(t_point a)
{
	t_point	b;

	b.p.x = -a.p.x;
	b.p.y = -a.p.y;
	b.p.z = -a.p.z;
	b.p.w = -a.p.w;
	b.color = a.color;
	return (b);
}

t_vec3	negate_vec3(t_vec3 a)
{
	t_vec3	b;

	b.x = -a.x;
	b.y = -a.y;
	b.z = -a.z;
	b.w = 0;
	return (b);
}

t_point	vec3_to_point(t_vec3 vec3, int color)
{
	t_point	point;

	point.p.x = vec3.x;
	point.p.y = vec3.y;
	point.p.z = vec3.z;
	point.color.r = color << 16;
	point.color.g = color << 8;
	point.color.b = color;
	point.color.hex = color;
	point.p.w = 1;
	return (point);
}

t_vec3	point_to_vec3(t_point p)
{
	t_vec3	vec;

	vec.x = p.p.x;
	vec.y = p.p.y;
	vec.z = p.p.z;
	vec.w = 0;
	return (vec);
}
