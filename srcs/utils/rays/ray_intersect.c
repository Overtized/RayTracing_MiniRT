/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:27:37 by mchanlia          #+#    #+#             */
/*   Updated: 2026/04/01 13:41:05 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	pl_inter(t_ray *ray, t_object *obj, t_it **it_list)
{
	double	denom;
	double	t;
	t_plane	*plane;
	t_it	*new_it;

	plane = (t_plane *)obj->data;
	denom = tupple_dot_product(ray->dir, plane->normal);
	if (fabs(denom) < P_EPS)
		return (true);
	t = tupple_dot_product
		(sub_two_points(plane->pos, ray->og), plane->normal) / denom;
	if (t < P_EPS)
		return (true);
	new_it = malloc(1 * sizeof(t_it));
	if (!new_it)
		return (write_err("plane intersect malloc failure\n"), false);
	new_it->obj = obj;
	new_it->count = 1;
	new_it->t[0] = t;
	new_it->t[1] = t;
	add_intersection(it_list, new_it);
	return (true);
}

bool	sp_inter(double *det, t_ray *ray, t_object *obj, t_it **it_list)
{
	t_it	*new_it;
	t_point	sphere_to_ray;
	double	comp_var[3];

	sphere_to_ray = sub_two_points(ray->og, make_point(0, 0, 0, GREEN));
	comp_var[0] = tupple_dot_product(ray->dir, ray->dir);
	comp_var[1] = 2.0 * tupple_dot_product(ray->dir, sphere_to_ray);
	comp_var[2] = tupple_dot_product(sphere_to_ray, sphere_to_ray) - 1;
	*det = (comp_var[1] * comp_var[1]) - (4.0 * comp_var[0] * comp_var[2]);
	if (*det > 0)
	{
		new_it = malloc(1 * sizeof(t_it));
		if (!new_it)
			return (write_err("sphere intersect malloc failure\n"), false);
		new_it->obj = obj;
		new_it->count = 2;
		new_it->t[0] = (-comp_var[1] - sqrt(*det)) / (2.0 * comp_var[0]);
		new_it->t[1] = (-comp_var[1] + sqrt(*det)) / (2.0 * comp_var[0]);
		add_intersection(it_list, new_it);
	}
	return (true);
}

static bool	handle_non_pl(t_object *obj, t_ray *world_ray, t_it **it_list)
{
	t_ray	local_ray;
	double	determinant;

	local_ray.error = false;
	transform_ray(&obj->inv_m, world_ray, &local_ray);
	if (local_ray.error)
		return (write_err("transform object failure\n"), false);
	if (obj->type == OBJ_SPHERE)
	{
		if (!sp_inter(&determinant, &local_ray, obj, it_list))
			return (write_err("sphere intersect failure"), false);
	}
	else if (obj->type == OBJ_CYLINDER)
	{
		if (!cy_inter(&determinant, &local_ray, obj, it_list))
			return (write_err("cylinder intersect failure"), false);
	}
	else if (obj->type == OBJ_CONE)
	{
		if (!co_inter(&determinant, &local_ray, obj, it_list))
			return (write_err("cone intersect failure"), false);
	}
	return (true);
}

t_it	*intersect(t_object *obj, t_ray *world_ray, bool *error)
{
	t_it	*it_list;

	it_list = NULL;
	while (obj)
	{
		if (obj->type == OBJ_PLANE)
		{
			if (!pl_inter(world_ray, obj, &it_list))
				return (write_err("plane intersect fail"), *error = true, NULL);
		}
		else if (obj->type == OBJ_SPHERE || obj->type == OBJ_CYLINDER
			|| obj->type == OBJ_CONE)
		{
			if (!handle_non_pl(obj, world_ray, &it_list))
				return (*error = true, NULL);
		}
		obj = obj->next;
	}
	sort_inter_list(&it_list);
	return (it_list);
}
