/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:10:05 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/27 19:41:02 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	color_at(t_scene *scene, t_ray *ray, t_color *color)
{
	t_it		*cross ;
	t_it		*best_hit;
	t_comps		comps;
	int			limit;
	bool		error;

	limit = 5;
	error = false;
	cross = intersect(scene->objects, ray, &error);
	if (error)
		return (free_all_intersections(cross), false);
	if (!cross)
		return (reset_color(color), true);
	best_hit = get_lowest_hit(cross);
	if (!best_hit)
	{
		free_all_intersections(cross);
		return (reset_color(color), true);
	}
	if (!prep_comp(ray, best_hit, &comps, cross))
		return (free_all_intersections(cross), false);
	*color = shade_hit(scene, &comps, limit);
	free_all_intersections(cross);
	return (true);
}
