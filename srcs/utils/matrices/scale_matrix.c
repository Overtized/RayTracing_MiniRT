/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 10:57:12 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:24:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	scale(double x, double y, double z)
{
	t_matrix	new_matrix;

	new_matrix = identity_matrix();
	new_matrix.m[0][0] = x;
	new_matrix.m[1][1] = y;
	new_matrix.m[2][2] = z;
	return (new_matrix);
}

t_point	scale_inv_m_transf(double x, double y, double z,
		t_point input_tup)
{
	t_point		new_t_object;
	t_matrix	temp;
	t_matrix	scale_matrix;

	scale_matrix = scale(x, y, z);
	if (!invert_matrix(&scale_matrix, &temp))
		return (write_err("scale inv failure"), make_point_error());
	scale_matrix = temp;
	if (input_tup.p.w == 1)
		new_t_object = make_point(input_tup.p.x, input_tup.p.y,
				input_tup.p.z, input_tup.color.hex);
	else
		new_t_object = make_vector(input_tup.p.x, input_tup.p.y,
				input_tup.p.z, input_tup.color.hex);
	new_t_object = multiply_m_by_m(&scale_matrix, new_t_object);
	return (new_t_object);
}

t_point	scale_m_transf(double x, double y, double z,
		t_point input_tup)
{
	t_point		new_t_object;
	t_matrix	scale_matrix;

	scale_matrix = scale(x, y, z);
	if (input_tup.p.w == 1)
		new_t_object = make_point(input_tup.p.x, input_tup.p.y,
				input_tup.p.z, input_tup.color.hex);
	else
		new_t_object = make_vector(input_tup.p.x, input_tup.p.y,
				input_tup.p.z, input_tup.color.hex);
	new_t_object = multiply_m_by_m(&scale_matrix, new_t_object);
	return (new_t_object);
}
