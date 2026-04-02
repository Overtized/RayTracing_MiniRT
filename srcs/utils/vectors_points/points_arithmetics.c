/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_arithmetics.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:13:54 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:43:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_point	sum_two_points(t_point a, t_point b)
{
	t_point	c;

	c.p.x = a.p.x + b.p.x;
	c.p.y = a.p.y + b.p.y;
	c.p.z = a.p.z + b.p.z;
	c.color = a.color;
	c.p.w = a.p.w + b.p.w;
	return (c);
}

t_point	sub_two_points(t_point a, t_point b)
{
	t_point	c;

	c.p.x = a.p.x - b.p.x;
	c.p.y = a.p.y - b.p.y;
	c.p.z = a.p.z - b.p.z;
	c.p.w = a.p.w - b.p.w;
	c.color = a.color;
	return (c);
}

t_point	normalize_vector(t_point a)
{
	double	vector_magnitude;
	t_point	c;

	vector_magnitude = get_tupple_magnitude(a);
	if (vector_magnitude < P_EPS)
	{
		c.p.x = 0;
		c.p.y = 0;
		c.p.z = 1;
		c.p.w = 0;
		return (c);
	}
	c.p.x = a.p.x / vector_magnitude;
	c.p.y = a.p.y / vector_magnitude;
	c.p.z = a.p.z / vector_magnitude;
	c.p.w = 0;
	c.color = a.color;
	return (c);
}

t_vec3	normalize_vec3(t_vec3 a)
{
	float	vector_magnitude;
	t_vec3	c;

	vector_magnitude = get_tupple_magnitude(vec3_to_point(a, 0));
	if (vector_magnitude < P_EPS)
	{
		c.x = 0;
		c.y = 0;
		c.z = 1;
		c.w = 0;
		return (c);
	}
	c.x = a.x / vector_magnitude;
	c.y = a.y / vector_magnitude;
	c.z = a.z / vector_magnitude;
	c.w = 0;
	return (c);
}
