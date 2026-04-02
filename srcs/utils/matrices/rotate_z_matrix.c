/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_z_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:00:06 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:24:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	rotate_z(float radians)
{
	t_matrix	new_matrix;

	new_matrix = identity_matrix();
	new_matrix.m[0][0] = cos(radians);
	new_matrix.m[0][1] = -sin(radians);
	new_matrix.m[1][0] = sin(radians);
	new_matrix.m[1][1] = cos(radians);
	return (new_matrix);
}

t_point	rotate_z_inv_m_transf(float radians, t_point input_tup)
{
	t_point		new_t_object;
	t_matrix	temp;
	t_matrix	rotation_matrix;

	rotation_matrix = rotate_z(radians);
	if (!invert_matrix(&rotation_matrix, &temp))
		return (make_point_error());
	rotation_matrix = temp;
	if (input_tup.p.w == 1)
		new_t_object = make_point(input_tup.p.x, input_tup.p.y,
				input_tup.p.z, input_tup.color.hex);
	else
		new_t_object = make_vector(input_tup.p.x, input_tup.p.y,
				input_tup.p.z, input_tup.color.hex);
	new_t_object = multiply_m_by_m(&rotation_matrix, new_t_object);
	return (new_t_object);
}

t_point	rotate_z_m_transf(float radians, t_point input_tup)
{
	t_point		new_t_object;
	t_matrix	rotation_matrix;

	rotation_matrix = rotate_z(radians);
	if (input_tup.p.w == 1)
		new_t_object = make_point(input_tup.p.x, input_tup.p.y,
				input_tup.p.z, input_tup.color.hex);
	else
		new_t_object = make_vector(input_tup.p.x, input_tup.p.y,
				input_tup.p.z, input_tup.color.hex);
	new_t_object = multiply_m_by_m(&rotation_matrix, new_t_object);
	return (new_t_object);
}
