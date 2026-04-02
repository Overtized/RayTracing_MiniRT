/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:42:49 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:50:33 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	intersect_cone_caps(t_cone *cone, t_ray *ray, t_it *new_it)
{
	double	t;
	double	x;
	double	z;

	if (!cone->closed || fabs(ray->dir.p.y) < P_EPS)
		return ;
	t = (-1.0 - ray->og.p.y) / ray->dir.p.y;
	x = ray->og.p.x + t * ray->dir.p.x;
	z = ray->og.p.z + t * ray->dir.p.z;
	if ((x * x + z * z) <= (1.0 + P_EPS))
		new_it->t[new_it->count++] = t;
}

static bool	basic_obj_setup(t_it **new_it, t_object *obj, t_cone **cone)
{
	*new_it = malloc(sizeof(t_it));
	if (!*new_it)
		return (write_err("cone intersect malloc failure\n"), false);
	(*new_it)->obj = obj;
	(*new_it)->count = 0;
	*cone = (t_cone *)obj->data;
	return (true);
}

static void	check_caps(t_inter_comp *c, t_ray *ray, t_it *new)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		{
			c->y[i] = ray->og.p.y + c->t[i] * ray->dir.p.y;
			if (c->y[i] <= P_EPS && c->y[i] >= -1.0 - P_EPS)
				new->t[new->count++] = c->t[i];
		}
		i++;
	}
}

static void	compute_inters(t_inter_comp *c, t_ray *ray, t_it *new, double *det)
{
	if (fabs(c->v[0]) < P_EPS)
	{
		if (fabs(c->v[1]) > P_EPS)
		{
			c->t[0] = -c->v[2] / (2 * c->v[1]);
			c->y[0] = ray->og.p.y + c->t[0] * ray->dir.p.y;
			if (c->y[0] <= P_EPS && c->y[0] >= -1.0 - P_EPS)
				new->t[new->count++] = c->t[0];
		}
	}
	else
	{
		*det = c->v[1] * c->v[1] - 4 * c->v[0] * c->v[2];
		if (*det >= 0)
		{
			c->t[0] = (-c->v[1] - sqrt(*det)) / (2 * c->v[0]);
			c->t[1] = (-c->v[1] + sqrt(*det)) / (2 * c->v[0]);
			check_caps(c, ray, new);
		}
	}
}

bool	co_inter(double *det, t_ray *ray, t_object *obj, t_it **it_list)
{
	t_inter_comp	c;
	t_it			*new;
	t_cone			*cone;

	new = NULL;
	cone = NULL;
	if (!basic_obj_setup(&new, obj, &cone))
		return (false);
	c.v[0] = (ray->dir.p.x * ray->dir.p.x) + (ray->dir.p.z * ray->dir.p.z)
		- (ray->dir.p.y * ray->dir.p.y);
	c.v[1] = 2 * (ray->dir.p.x * ray->og.p.x + ray->dir.p.z * ray->og.p.z
			- ray->dir.p.y * ray->og.p.y);
	c.v[2] = (ray->og.p.x * ray->og.p.x) + (ray->og.p.z * ray->og.p.z)
		- (ray->og.p.y * ray->og.p.y);
	compute_inters(&c, ray, new, det);
	intersect_cone_caps(cone, ray, new);
	if (new->count > 0)
		return (sort_internal_t(new), add_intersection(it_list, new), true);
	return (free(new), true);
}
