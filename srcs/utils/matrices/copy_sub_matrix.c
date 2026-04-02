/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_sub_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:44:43 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/27 19:24:52 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	cp_sub_m(t_matrix *old, t_matrix *new, size_t del_r, size_t del_c)
{
	size_t	m_row;
	size_t	m_col;
	size_t	new_r;
	size_t	new_c;

	m_row = -1;
	new_r = 0;
	while (++m_row < old->rows)
	{
		if (m_row == del_r)
			continue ;
		m_col = -1;
		new_c = 0;
		while (++m_col < old->cols)
		{
			if (m_col == del_c)
				continue ;
			new->m[new_r][new_c] = old->m[m_row][m_col];
			new_c++;
		}
		new_r++;
	}
}
