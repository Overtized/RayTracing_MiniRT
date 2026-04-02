/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:06:32 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 12:55:54 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_intersects(t_it *intersect)
{
	t_it		*tmp;
	static int	counter = 0;
	int			i;

	i = 0;
	if (!intersect)
		return ;
	if (++counter % 10000 != 0)
		return ;
	printf(P_CYAN"\n=== DEBUG PIXEL N°%d ===\n"P_RESET, counter);
	tmp = intersect;
	while (tmp)
	{
		printf(P_YELLOW" Maillon n°%d [Adresse: %p]\n", i++, (void *)tmp);
		printf("\t Objet pointe vers : %p\n", (void *)tmp->obj);
		printf("\t T0: %.2f | T1: %.2f\n", tmp->t[0], tmp->t[1]);
		printf("\t Next maillon: %p\n", (void *)tmp->next);
		printf(" ----------------\n" P_RESET);
		tmp = tmp->next;
	}
	printf(P_CYAN"TOTAL MAILLONS: %d\n"P_RESET, i);
	printf(P_CYAN"==============================\n\n"P_RESET);
}

void	print_intersect(t_it *intersect)
{
	static int		counter = 0;
	int				i;

	i = 0;
	if (!intersect)
		return ;
	if (++counter % 10000 != 0)
		return ;
	printf(P_CYAN"\n=== DEBUG PIXEL N°%d ===\n"P_RESET, counter);
	printf(P_YELLOW" Maillon n°%d [Adresse: %p]\n", i++, (void *)intersect);
	printf("\t Objet pointe vers : %p\n", (void *)intersect->obj);
	printf("\t T0: %.2f | T1: %.2f\n", intersect->t[0], intersect->t[1]);
	printf(" ----------------\n" P_RESET);
	printf(P_CYAN"TOTAL MAILLONS: %d\n"P_RESET, i);
	printf(P_CYAN"==============================\n\n"P_RESET);
}
