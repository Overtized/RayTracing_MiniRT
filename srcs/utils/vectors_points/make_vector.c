/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:39:28 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:24:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_point	make_vector(float x, float y, float z, int hex_color)
{
	t_point	point;

	point = make_point(x, y, z, hex_color);
	point.p.w = 0;
	return (point);
}

t_point	copy_vector(t_point point_a)
{
	t_point	point_b;

	point_b = copy_point(point_a);
	point_b.p.w = 0;
	return (point_b);
}

t_vec3	make_vec3(float x, float y, float z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = 0;
	vec.error = false;
	return (vec);
}

t_vec3	make_vec_error(void)
{
	t_vec3	vec;

	vec.x = 0;
	vec.y = 0;
	vec.z = 0;
	vec.w = 0;
	vec.error = true;
	return (vec);
}
