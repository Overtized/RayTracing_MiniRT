/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverting_matrix_u.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:59:33 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/27 18:57:06 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	compute_determinant(t_matrix *m, bool *error)
{
	size_t	m_len;
	size_t	c;
	float	det;

	m_len = m->cols;
	c = 0;
	det = 0;
	if (m->rows == 2 && m->cols == 2)
		return (compute_2x2_determinant(m));
	else
	{
		while (c < m_len)
		{
			det = det + (m->m[0][c] * compute_cofactor(m, 0, c, error));
			if (*error)
				return (write_err("compute cofactor error"), 0);
			c++;
		}
	}
	return (det);
}

float	compute_2x2_determinant(t_matrix *m)
{
	float	res;

	res = 0;
	res = m->m[0][0] * m->m[1][1];
	res -= m->m[1][0] * m->m[0][1];
	return (res);
}

t_matrix	create_sub_m(t_matrix *m, size_t del_row,
	size_t del_col, bool *error)
{
	t_matrix	new;

	new = create_matrix();
	new.rows = m->rows - 1;
	new.cols = m->cols - 1;
	if (del_row >= m->rows || del_col >= m->cols)
	{
		*error = true;
		return (write_err("submatrix can't be bigger than input matrix"), new);
	}
	cp_sub_m(m, &new, del_row, del_col);
	return (new);
}

float	compute_minor(t_matrix *m, size_t row, size_t col, bool *error)
{
	float		minor;
	t_matrix	submatrix;

	minor = 0;
	submatrix = create_sub_m(m, row, col, error);
	if (*error)
		return (write_err("submatrice failure"), 0.0);
	minor = compute_determinant(&submatrix, error);
	return (minor);
}

float	compute_cofactor(t_matrix *m, size_t row, size_t col, bool *error)
{
	float	minor;

	minor = 0;
	minor = compute_minor(m, row, col, error);
	if (*error)
		return (write_err("compute minor failure"), 0.0);
	if ((row + col) % 2 != 0)
		return (-minor);
	return (minor);
}
