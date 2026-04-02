/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:48:52 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:24:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static double	make_last_comp(double r0, double cos)
{
	double	x0;
	double	x5;

	x0 = (1 - cos);
	x5 = x0 * x0 * x0 * x0 * x0;
	return (r0 + (1 - r0) * x5);
}

double	schlick_fresnel(t_comps	*comps)
{
	double	cos;
	double	cos_t;
	double	n;
	double	sin_2t;
	double	r0;

	cos = vec3_dot_product(comps->eye_vec, comps->normal_vec);
	if (comps->n[0] > comps->n[1])
	{
		n = comps->n[0] / comps->n[1];
		sin_2t = (n * n) * (1.0 - (cos * cos));
		if (sin_2t > 1.0)
			return (1.0);
		cos_t = sqrt(1.0 - sin_2t);
		cos = cos_t;
	}
	r0 = ((comps->n[0] - comps->n[1]) / (comps->n[0] + comps->n[1]));
	r0 = r0 * r0;
	return (make_last_comp(r0, cos));
}

static t_point	get_ray_dir(t_comps *comps, double n_ratio, double cos_i,
		double cos_t)
{
	t_point	term1;
	t_point	term2;
	t_point	dir;

	term1 = scale_tupple
		(vec3_to_point (comps->normal_vec, 0), (n_ratio * cos_i - cos_t));
	term2 = scale_tupple
		(vec3_to_point(comps->eye_vec, 0), n_ratio);
	dir = sub_two_points(term1, term2);
	dir.p.w = 0;
	return (dir);
}

t_color	refract_c(t_scene *scene, t_comps *comps,
	int call_limit, t_color *color)
{
	double	n_ratio;
	double	cos_i;
	double	sin_2t;
	double	cos_t;
	t_ray	refracted_ray;

	if (comps->obj->materia.transparency == 0 || call_limit <= 0)
		return (*color = make_color(0.0, 0.0, 0.0));
	n_ratio = comps->n[0] / comps->n[1];
	cos_i = vec3_dot_product(comps->eye_vec, comps->normal_vec);
	sin_2t = (n_ratio * n_ratio) * (1 - (cos_i * cos_i));
	if (sin_2t > 1)
		return (*color = make_color(0.0, 0.0, 0.0));
	cos_t = sqrt(1.0 - sin_2t);
	refracted_ray = create_ray ((comps->under_p),
			get_ray_dir(comps, n_ratio, cos_i, cos_t));
	if (refracted_ray.error)
		return (*color = make_color(0.0, 0.0, 0.0));
	*color = multiply_color
		(get_color_at(scene, &refracted_ray, call_limit),
			comps->obj->materia.transparency);
	return (*color);
}
