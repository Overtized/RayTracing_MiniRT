/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_l_on_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:44:06 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 00:43:35 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_l_on_obj	fill_l_on_obj(t_light *light, t_comps *comps)
{
	t_l_on_obj	res;

	res.t = comps->lowest_t;
	res.p_p = comps->hit_p;
	res.n_p = vec3_to_point(comps->normal_vec, 0);
	res.e_p = vec3_to_point(comps->eye_vec, 0);
	res.l_p = normalize_vector(sub_two_points(light->pos, comps->over_p));
	res.r_p = reflect(negate_tupple(res.l_p), res.n_p);
	return (res);
}
