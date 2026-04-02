/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:21:12 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:24:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	shear(double shear_tab[6])
{
	t_matrix	new_matrix;

	new_matrix = identity_matrix();
	new_matrix.m[0][1] = shear_tab[0];
	new_matrix.m[0][2] = shear_tab[1];
	new_matrix.m[1][0] = shear_tab[2];
	new_matrix.m[1][2] = shear_tab[3];
	new_matrix.m[2][0] = shear_tab[4];
	new_matrix.m[2][1] = shear_tab[5];
	return (new_matrix);
}

t_point	shear_inv_matrix_transf(double shear_tab[6], t_point input_tup)
{
	t_point		new_t_object;
	t_matrix	temp;
	t_matrix	shear_matrix;

	shear_matrix = shear(shear_tab);
	if (!invert_matrix(&shear_matrix, &temp))
		return (write_err("shear inv failure"), make_point_error());
	shear_matrix = temp;
	if (input_tup.p.w)
		new_t_object = make_point(input_tup.p.x, input_tup.p.y,
				input_tup.p.z, input_tup.color.hex);
	else
		new_t_object = make_vector(input_tup.p.x, input_tup.p.y,
				input_tup.p.z, input_tup.color.hex);
	new_t_object = multiply_m_by_m(&shear_matrix, new_t_object);
	return (new_t_object);
}

t_point	shear_matrix_transf(double shear_tab[6], t_point input_tup)
{
	t_point		new_t_object;
	t_matrix	shear_matrix;

	shear_matrix = shear(shear_tab);
	if (input_tup.p.w == 1)
		new_t_object = make_point(input_tup.p.x, input_tup.p.y,
				input_tup.p.z, input_tup.color.hex);
	else
		new_t_object = make_vector(input_tup.p.x, input_tup.p.y,
				input_tup.p.z, input_tup.color.hex);
	new_t_object = multiply_m_by_m(&shear_matrix, new_t_object);
	return (new_t_object);
}
