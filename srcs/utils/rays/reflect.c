/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:21:45 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:24:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	get_color_at(t_scene *scene, t_ray	*ray, int call_limit)
{
	t_it	*cross ;
	t_it	*best_hit;
	t_comps	comps;
	t_color	color_at;
	bool	error;

	error = false;
	cross = intersect(scene->objects, ray, &error);
	if (error || !cross)
		return (make_color(0.0, 0.0, 0.0));
	best_hit = get_lowest_hit(cross);
	if (!best_hit)
		return (free_all_intersections(cross), make_color(0.0, 0.0, 0.0));
	if (!prep_comp(ray, best_hit, &comps, cross))
		return (free_all_intersections(cross), make_color(0.0, 0.0, 0.0));
	color_at = shade_hit(scene, &comps, call_limit);
	free_all_intersections(cross);
	return (color_at);
}

t_point	reflect(t_point in, t_point normal)
{
	t_point	reflected;

	normal = scale_tupple(scale_tupple(normal, 2),
			tupple_dot_product(in, normal));
	reflected = sub_two_points(in, normal);
	reflected.p.w = 0;
	reflected = normalize_vector(reflected);
	return (reflected);
}

t_color	reflected_color(t_scene *scene, t_comps *comps, int call_limit)
{
	t_ray	reflect_ray;
	t_color	base_reflected_c;
	t_point	conv_ref_v;

	if (comps->obj->materia.reflective == 0.0 || call_limit <= 0)
		return (make_color(0.0, 0.0, 0.0));
	else
	{
		conv_ref_v = vec3_to_point(comps->reflect_v, 0);
		conv_ref_v.p.w = 0;
		reflect_ray = create_ray(comps->over_p, conv_ref_v);
		base_reflected_c = get_color_at (scene, &reflect_ray, call_limit);
		return (multiply_color(base_reflected_c,
				comps->obj->materia.reflective));
	}
}
