/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:48:14 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:43:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	determine_n(t_it *list, t_it *l_hit, t_comps *comps)
{
	t_it		*cursor;
	t_it		*new_lst;
	t_cont_n	*cont;

	cont = NULL;
	new_lst = NULL;
	if (!create_new_lst(&new_lst, list, comps))
		return (false);
	cursor = new_lst;
	while (cursor)
	{
		if (cursor->obj == l_hit->obj
			&& fabs(cursor->t[0] - comps->lowest_t) < P_EPS)
			comps->n[0] = get_last_n(cont);
		manage_cont_lst(&cont, cursor);
		if (cursor->obj == l_hit->obj
			&& fabs(cursor->t[0] - comps->lowest_t) < P_EPS)
		{
			comps->n[1] = get_last_n(cont);
			break ;
		}
		cursor = cursor->next;
	}
	return (free_all_containers(&cont), free_all_intersections(new_lst), true);
}
