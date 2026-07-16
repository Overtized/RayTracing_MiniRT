/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:44:38 by mchanlia          #+#    #+#             */
/*   Updated: 2026/07/16 06:00:25 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	is_shadowed(t_scene *scene, t_point *point, t_light *current_light) // math
{
	t_ray	test_ray;
	t_point	dir;
	t_it	*it[2];
	double	ts[2];
	bool	error;

	error = false;
	ts[0] = get_tupple_magnitude
		(sub_two_points(current_light->pos, *point));
	dir = normalize_vector(sub_two_points(current_light->pos, *point));
	test_ray = create_ray(*point, dir);
	if (test_ray.error)
		return (false);
	it[0] = intersect(scene->objects, &test_ray, &error);
	if (error)
		return (write_err("function is shadowed failure\n"), false);
	it[1] = get_lowest_hit(it[0]);
	ts[1] = compare_range(it[1]);
	if (ts[1] > P_EPS && ts[1] < ts[0])
		return (free_all_intersections(it[0]), true);
	return (free_all_intersections(it[0]), false);
}

static t_color	compute_reflectance(t_color *colors, t_comps *comps)
{
	double	reflectance;

	reflectance = schlick_fresnel(comps);
	colors[3] = sum_two_colors(multiply_color(colors[1], reflectance),
			multiply_color(colors[2], 1.0 - reflectance));
	return (sum_two_colors(colors[0], colors[3]));
}

t_color	shade_hit(t_scene *scene, t_comps *comps, int ref_lim)
{
	t_color	colors[4];
	t_light	*current_light;

	colors[0] = comps->obj->materia.intensity;
	if (comps->obj->has_pattern)
		colors[0] = get_patt_obj(&comps->obj->pattern,
				&comps->over_p, comps->obj); // check for pattern on object (stripes for example)
	colors[0] = comp_amb(scene, &colors[0], &comps->obj->materia); // compute ambiant light
	current_light = scene->light;
	while (current_light)
	{
		if (!is_shadowed(scene, &comps->over_p, current_light)) // is the object positioned in a shadowed area ? if so it will have consequences
			colors[0] = sum_two_colors (colors[0],
					color_point(current_light, comps, &colors[0]));
		current_light = current_light->next;
	}
	colors[1] = reflected_color(scene, comps, ref_lim - 1); // reflected
	refract_c(scene, comps, ref_lim - 1, &colors[2]); // refracted
	if (comps->obj->materia.reflective > 0.0
		&& comps->obj->materia.transparency > 0.0)
		return (compute_reflectance(colors, comps)); // reflectance value
	return (sum_two_colors(colors[0], colors[1])); // final value
}
