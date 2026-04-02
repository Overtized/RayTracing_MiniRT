/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:22:49 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/12 15:46:37 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	transpose_matrix(t_matrix *m)
{
	float	tmp;
	size_t	r;
	size_t	c;

	r = 0;
	tmp = 0;
	while (r < m->rows)
	{
		c = r + 1;
		while (c < m->cols)
		{
			tmp = m->m[r][c];
			m->m[r][c] = m->m[c][r];
			m->m[c][r] = tmp;
			c++;
		}
		r++;
	}
}
