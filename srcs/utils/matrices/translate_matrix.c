/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:22:53 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/31 14:58:20 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	translation(double x, double y, double z)
{
	t_matrix	new_matrix;

	new_matrix = identity_matrix();
	new_matrix.m[0][3] = x;
	new_matrix.m[1][3] = y;
	new_matrix.m[2][3] = z;
	return (new_matrix);
}

t_point	transl_inv_transf(double x, double y, double z,
		t_point input_tup)
{
	t_point		new_t_object;
	t_matrix	temp;
	t_matrix	translation_matrix;

	translation_matrix = translation(x, y, z);
	if (!invert_matrix(&translation_matrix, &temp))
		return (write_err("translate inv failure"), make_point_error());
	translation_matrix = temp;
	if (input_tup.p.w == 1)
		new_t_object = make_point(input_tup.p.x, input_tup.p.y,
				input_tup.p.z, input_tup.color.hex);
	else
		new_t_object = make_vector(input_tup.p.x, input_tup.p.y,
				input_tup.p.z, input_tup.color.hex);
	new_t_object = multiply_m_by_m(&translation_matrix,
			new_t_object);
	return (new_t_object);
}

t_point	transl_transf(double x, double y, double z,
		t_point input_tup)
{
	t_point		new_t_object;
	t_matrix	translation_matrix;

	translation_matrix = translation(x, y, z);
	if (input_tup.p.w == 1)
		new_t_object = make_point(input_tup.p.x, input_tup.p.y,
				input_tup.p.z, input_tup.color.hex);
	else
		new_t_object = make_vector(input_tup.p.x, input_tup.p.y,
				input_tup.p.z, input_tup.color.hex);
	new_t_object = multiply_m_by_m(&translation_matrix,
			new_t_object);
	return (new_t_object);
}
