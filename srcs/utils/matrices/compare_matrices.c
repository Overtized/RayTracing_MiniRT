/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_matrices.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:24:38 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/12 14:48:05 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	compare_matrices(t_matrix *m1, t_matrix *m2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < m1->rows)
	{
		j = 0;
		while (j < m1->cols)
		{
			if (m1->m[i][j] != m2->m[i][j])
				return (write_err("uneven matrices\n"), false);
			j++;
		}
		i++;
	}
	return (true);
}
