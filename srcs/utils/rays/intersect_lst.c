/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:04:12 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 00:45:45 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	add_intersection(t_it **list, t_it *new)
{
	if (!list || !new)
		return ;
	new->next = *list;
	*list = new;
}

t_it	*last_inter(t_it *list)
{
	t_it	*tmp;

	tmp = list;
	while (tmp)
		tmp = tmp->next;
	return (tmp);
}

void	free_all_intersections(t_it *obj)
{
	t_it	*cursor;

	if (!obj)
		return ;
	while (obj)
	{
		cursor = obj;
		obj = obj->next;
		free(cursor);
	}
	obj = NULL;
}

size_t	intersections_lst_size(t_it *obj_lst)
{
	size_t	counter;
	t_it	*tmp;

	if (!obj_lst)
		return (-1);
	counter = 0;
	tmp = obj_lst;
	while (tmp != NULL)
	{
		counter++;
		tmp = tmp->next;
	}
	return (counter);
}
