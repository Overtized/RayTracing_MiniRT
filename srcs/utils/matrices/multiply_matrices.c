/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:48:30 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/12 16:47:56 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static float	do_the_math(t_matrix *m1, t_matrix *m2, size_t row, size_t col)
{
	float	res;
	size_t	j;

	res = 0;
	j = 0;
	while (j < m1->cols)
	{
		res += m1->m[row][j] * m2->m[j][col];
		j++;
	}
	return (res);
}

bool	multiply_matrices(t_matrix *m1, t_matrix *m2, t_matrix *res)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (m1->rows != m2->rows || m1->cols != m2->cols)
		return (write_err("error matrices sizes unequivalent\n"), false);
	*res = create_matrix();
	while (i < m1->rows)
	{
		j = 0;
		while (j < m2->cols)
		{
			res->m[i][j] = do_the_math(m1, m2, i, j);
			j++;
		}
		i++;
	}
	return (true);
}
