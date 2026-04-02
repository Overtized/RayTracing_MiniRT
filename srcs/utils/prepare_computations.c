/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:28:43 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:43:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_point	position(t_ray *ray, double l_t)
{
	t_point	p;

	p.color.hex = 0xFFFFFF;
	p = sum_two_points(ray->og, scale_tupple (ray->dir, l_t));
	p.p.w = 1;
	p.error = false;
	return (p);
}

bool	prep_comp(t_ray *ray, t_it *l_hit, t_comps *comps, t_it *it_list)
{
	t_point	offset;

	comps->lowest_t = compare_range(l_hit);
	comps->obj = l_hit->obj;
	comps->obj_type = l_hit->obj->type;
	comps->hit_p = position(ray, comps->lowest_t);
	comps->eye_vec = negate_vec3(point_to_vec3(ray->dir));
	comps->normal_vec = point_to_vec3(normal_at(comps->obj, comps->hit_p));
	comps->inside_obj = false;
	if (vec3_dot_product(comps->normal_vec, comps->eye_vec) < 0)
	{
		comps->inside_obj = true;
		comps->normal_vec = negate_vec3(comps->normal_vec);
	}
	offset = scale_tupple(vec3_to_point(comps->normal_vec, 0), P_EPS);
	comps->over_p = sum_two_points(comps->hit_p, offset);
	comps->over_p.p.w = 1;
	if (!determine_n(it_list, l_hit, comps))
		return (false);
	comps->under_p = sub_two_points(comps->hit_p, offset);
	comps->under_p.p.w = 1;
	comps->reflect_v = point_to_vec3
		(reflect(ray->dir, vec3_to_point(comps->normal_vec, 0)));
	comps->ray_dir = ray->dir;
	return (true);
}
