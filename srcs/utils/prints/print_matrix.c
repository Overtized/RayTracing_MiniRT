/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:23:17 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/12 14:53:47 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	make_it_tab(t_matrix *m)
{
	size_t	x;
	size_t	y;

	if (!m)
		return ;
	x = 0;
	y = 0;
	while (x < m->rows)
	{
		y = 0;
		while (y < m->cols)
		{
			printf(P_GREEN"%0.2f "P_RESET, m->m[x][y]);
			fflush(stdout);
			y++;
		}
		printf("\n");
		x++;
	}
	printf("\n");
}

void	print_matrix(t_matrix *m)
{
	size_t	x;
	size_t	y;

	if (!m)
		return ;
	x = 0;
	y = 0;
	while (x < m->rows)
	{
		y = 0;
		while (y < m->cols)
		{
			write_message(1, " for row / column ", P_BLUE);
			printf(P_GREEN"[%zu] [%zu] "P_RESET, x, y);
			fflush(stdout);
			write_message(1, "value is ", P_BLUE);
			printf(P_GREEN"%0.2f \n"P_RESET, m->m[x][y]);
			fflush(stdout);
			y++;
		}
		printf("\n");
		x++;
	}
	printf("\n");
	make_it_tab(m);
}
