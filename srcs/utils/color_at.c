/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:10:05 by mchanlia          #+#    #+#             */
/*   Updated: 2026/07/16 05:58:30 by mchanlia         ###   ########.fr       */
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
	cross = intersect(scene->objects, ray, &error); // find all intersection of the ray with something along its path
	if (error)
		return (free_all_intersections(cross), false); // free logic
	if (!cross)
		return (reset_color(color), true); // no intersections
	best_hit = get_lowest_hit(cross); // only the lowest hit matters others will not be seen unless object is transparent
	if (!best_hit)
	{
		free_all_intersections(cross);
		return (reset_color(color), true);
	}
	if (!prep_comp(ray, best_hit, &comps, cross)) // optimization function that does some computation beforehands that will ease the flow later on
		return (free_all_intersections(cross), false);
	*color = shade_hit(scene, &comps, limit); // apply physics to the hit based on light properties, position of the object, angle, materia and much more
	free_all_intersections(cross);
	return (true);
}
