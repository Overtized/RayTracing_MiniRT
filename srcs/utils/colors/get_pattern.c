/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pattern.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:55:29 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:43:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	get_pattern_at_x(t_pattern *pattern, t_point *pos)
{
	if ((int)floor(pos->p.x) % 2 == 0)
		return (pattern->color_a);
	else
		return (pattern->color_b);
}

t_color	get_pattern_at_y(t_pattern *pattern, t_point *pos)
{
	if ((int)floor(pos->p.y) % 2 == 0)
		return (pattern->color_a);
	else
		return (pattern->color_b);
}

t_color	get_pattern_at_z(t_pattern *pattern, t_point *pos)
{
	if ((int)floor(pos->p.z) % 2 == 0)
		return (pattern->color_a);
	else
		return (pattern->color_b);
}

t_color	get_pattern_at_xyz(t_pattern *pattern, t_point *pos)
{
	float	fraction;
	double	distance;

	if (pattern->type == STRIPES)
	{
		if ((int)(floor(pos->p.x) + floor(pos->p.y)
			+ floor(pos->p.z)) % 2 == 0)
			return (pattern->color_a);
	}
	else if (pattern->type == GRADIENT)
	{
		fraction = (pos->p.x) + 0.5;
		if (fraction < 0)
			fraction = 0;
		else if (fraction > 1)
			fraction = 1;
		return (blend_color(&fraction, &pattern->color_a, &pattern->color_b));
	}
	else if (pattern->type == RING)
	{
		distance = sqrt(pos->p.x * pos->p.x + pos->p.z * pos->p.z);
		if ((int)(floor(distance + P_EPS)) % 2 == 0)
			return (pattern->color_a);
	}
	return (pattern->color_b);
}

t_color	get_patt_obj(t_pattern *pattern, t_point *world_p,
		t_object *obj)
{
	t_point	obj_p;
	t_point	pattern_p;

	world_p->p.w = 1;
	obj_p = multiply_m_by_m(&obj->inv_m, *world_p);
	pattern_p = multiply_m_by_m(&pattern->trans_inv_m, obj_p);
	pattern_p = vec3_to_point(pattern_p.p, 0);
	return (get_pattern_at_xyz(pattern, &pattern_p));
}
