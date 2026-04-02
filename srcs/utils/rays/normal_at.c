/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 09:55:52 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:43:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	normal_at_cy_co(t_object *obj, t_point *local_p,
	t_point *local_normal, double dist)
{
	if (obj->type == OBJ_CYLINDER)
	{
		if (local_p->p.y >= (((t_cylinder *)(obj->data))->h - P_EPS)
			&& dist <= 1.0 + P_EPS)
			*local_normal = make_vector(0, 1, 0, 0);
		else if (local_p->p.y <= (-((t_cylinder *)(obj->data))->h
			+ P_EPS) && dist <= 1.0 + P_EPS)
			*local_normal = make_vector(0, -1, 0, 0);
		else
			*local_normal = normalize_vector
				(make_vector(local_p->p.x, 0, local_p->p.z, 0));
	}
	else if (obj->type == OBJ_CONE)
	{
		if (local_p->p.y <= -1.0 + P_EPS
			&& dist <= 1.0 + P_EPS)
			*local_normal = make_vector(0, -1, 0, 0);
		else
			*local_normal = normalize_vector
				(make_vector(local_p->p.x, sqrt(dist), local_p->p.z, 0));
	}
}

t_point	normal_at(t_object *obj, t_point world_p)
{
	t_point	local_p;
	t_point	local_normal;
	t_point	world_normal;
	double	dist;

	if (obj->type == OBJ_PLANE)
		return (normalize_vector(((t_plane *)obj->data)->normal));
	local_p = multiply_m_by_m(&obj->inv_m, world_p);
	local_p.p.w = 1;
	dist = (local_p.p.x * local_p.p.x) + (local_p.p.z * local_p.p.z);
	if (obj->type == OBJ_SPHERE)
		local_normal = normalize_vector
			(make_vector(local_p.p.x, local_p.p.y, local_p.p.z, GREEN));
	normal_at_cy_co(obj, &local_p, &local_normal, dist);
	local_normal.p.w = 0;
	world_normal = multiply_m_by_m(&obj->trans_inv_m, local_normal);
	world_normal.p.w = 0;
	return (normalize_vector(world_normal));
}
