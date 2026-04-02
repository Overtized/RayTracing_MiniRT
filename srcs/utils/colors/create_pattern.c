/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pattern.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:13:12 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/27 19:16:43 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_pattern	new_patt(t_color ca, t_color cb, float scale,
		t_pat_type type)
{
	t_matrix	m_scale;
	t_pattern	pattern;

	pattern.scale = scale;
	pattern.color_a = ca;
	pattern.color_b = cb;
	pattern.trans_inv_m = get_inv_transfo_pattern(&pattern);
	pattern.type = type;
	if (type == GRADIENT)
		m_scale = get_scaling_m(2.0, 2.0, 2.0);
	else
		m_scale = get_scaling_m(scale, scale, scale);
	invert_matrix(&m_scale, &pattern.trans_inv_m);
	return (pattern);
}

t_pattern	create_checkerboard_pattern(float scale, t_pat_type type)
{
	t_pattern	pattern;

	pattern.scale = scale;
	pattern.color_a = make_color(1, 1, 1);
	pattern.color_b = make_color(0, 0, 0);
	pattern.trans_inv_m = get_inv_transfo_pattern(&pattern);
	pattern.type = type;
	return (pattern);
}
