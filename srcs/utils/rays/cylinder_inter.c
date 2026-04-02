/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_inter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:42:38 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 16:30:27 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	intersect_caps(t_cylinder *cyl, t_ray *ray, t_it *new_it)
{
	double	t;
	double	x;
	double	z;

	if (fabs(ray->dir.p.y) < P_EPS || !cyl->closed)
		return ;
	t = (-cyl->h - ray->og.p.y) / ray->dir.p.y;
	x = ray->og.p.x + t * ray->dir.p.x;
	z = ray->og.p.z + t * ray->dir.p.z;
	if ((x * x + z * z) <= (1.0 + P_EPS))
		new_it->t[new_it->count++] = t;
	t = (cyl->h - ray->og.p.y) / ray->dir.p.y;
	x = ray->og.p.x + t * ray->dir.p.x;
	z = ray->og.p.z + t * ray->dir.p.z;
	if ((x * x + z * z) <= (1.0 + P_EPS))
		new_it->t[new_it->count++] = t;
}

static bool	basic_obj_setup(t_it **new_it, t_object *obj, t_cylinder **cyl)
{
	*new_it = malloc(sizeof(t_it));
	if (!*new_it)
		return (write_err("cylinder intersect malloc failure\n"), false);
	(*new_it)->obj = obj;
	(*new_it)->count = 0;
	*cyl = (t_cylinder *)obj->data;
	return (true);
}

static void	compute_y(t_inter_comp *c, t_cylinder *cy, t_it *new_it, t_ray *ray)
{
	c->y[0] = ray->og.p.y + c->t[0] * ray->dir.p.y;
	if (c->y[0] > -cy->h - P_EPS && c->y[0] < cy->h + P_EPS)
		new_it->t[new_it->count++] = c->t[0];
	c->y[1] = ray->og.p.y + c->t[1] * ray->dir.p.y;
	if (c->y[1] > -cy->h - P_EPS && c->y[1] < cy->h + P_EPS)
		new_it->t[new_it->count++] = c->t[1];
}

bool	cy_inter(double *det, t_ray *ray, t_object *obj, t_it **it_list)
{
	t_it			*new;
	t_cylinder		*cyl;
	t_inter_comp	c;

	new = NULL;
	cyl = NULL;
	if (!basic_obj_setup(&new, obj, &cyl))
		return (false);
	c.v[0] = (ray->dir.p.x * ray->dir.p.x) + (ray->dir.p.z * ray->dir.p.z);
	if (fabs(c.v[0]) >= P_EPS)
	{
		c.v[1] = 2 * (ray->dir.p.x * ray->og.p.x + ray->dir.p.z * ray->og.p.z);
		c.v[2] = (ray->og.p.x * ray->og.p.x) + (ray->og.p.z * ray->og.p.z) - 1;
		*det = c.v[1] * c.v[1] - 4 * c.v[0] * c.v[2];
		if (*det < 0)
			return (free(new), true);
		c.t[0] = (-c.v[1] - sqrt(*det)) / (2 * c.v[0]);
		c.t[1] = (-c.v[1] + sqrt(*det)) / (2 * c.v[0]);
		compute_y(&c, cyl, new, ray);
	}
	intersect_caps(cyl, ray, new);
	if (new->count > 0)
		return (sort_internal_t(new), add_intersection(it_list, new), true);
	return (free(new), true);
}
