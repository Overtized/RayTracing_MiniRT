/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:35:39 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/12 17:27:23 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	create_matrix(void)
{
	t_matrix	new_m;

	new_m.rows = 4;
	new_m.cols = 4;
	return (new_m);
}

t_matrix	identity_matrix(void)
{
	t_matrix	m;

	m = create_matrix();
	ft_memset(&m.m, 0, sizeof(m.m));
	m.m[0][0] = 1.0;
	m.m[1][1] = 1.0;
	m.m[2][2] = 1.0;
	m.m[3][3] = 1.0;
	return (m);
}

t_matrix	cpy_matrix(t_matrix *src_m)
{
	int			i;
	int			j;
	t_matrix	cpy_m;

	i = 0;
	j = 0;
	cpy_m = create_matrix();
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			cpy_m.m[i][j] = src_m->m[i][j];
			j++;
		}
		i++;
	}
	return (cpy_m);
}
