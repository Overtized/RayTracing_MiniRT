/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:32:16 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:43:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	compare_range(t_it *inter)
{
	double	best_hit;
	size_t	i;

	i = 0;
	if (!inter)
		return (INFINITY);
	best_hit = inter->t[0];
	while (i < inter->count)
	{
		if (inter->t[i] < best_hit)
			best_hit = inter->t[i];
		i++;
	}
	return (best_hit);
}

t_it	*get_lowest_hit(t_it *list)
{
	t_it	*tmp;
	double	min_t;
	double	curr_t;

	min_t = INFINITY;
	tmp = NULL;
	while (list)
	{
		curr_t = compare_range(list);
		if (curr_t > P_EPS && curr_t < min_t)
		{
			min_t = curr_t;
			tmp = list;
		}
		list = list->next;
	}
	return (tmp);
}

static void	swap_data(t_it *node_a, t_it *node_b)
{
	t_it	tmp;
	int		i;

	tmp.count = node_a->count;
	tmp.obj = node_a->obj;
	i = -1;
	while (++i < 4)
		tmp.t[i] = node_a->t[i];
	node_a->count = node_b->count;
	node_a->obj = node_b->obj;
	i = -1;
	while (++i < 4)
		node_a->t[i] = node_b->t[i];
	node_b->count = tmp.count;
	node_b->obj = tmp.obj;
	i = -1;
	while (++i < 4)
		node_b->t[i] = tmp.t[i];
}

void	sort_inter_list(t_it **list)
{
	bool	swapped;
	t_it	*tmp;

	if (!list || !*list)
		return ;
	swapped = true;
	while (swapped)
	{
		swapped = false;
		tmp = *list;
		while (tmp && tmp->next)
		{
			if (compare_range(tmp->next) < compare_range(tmp))
			{
				swap_data(tmp, tmp->next);
				swapped = true;
			}
			tmp = tmp->next;
		}
	}
}

void	sort_internal_t(t_it *it)
{
	size_t	i;
	size_t	j;
	double	temp;

	i = 0;
	while (i < it->count)
	{
		j = i + 1;
		while (j < it->count)
		{
			if (it->t[i] > it->t[j])
			{
				temp = it->t[i];
				it->t[i] = it->t[j];
				it->t[j] = temp;
			}
			j++;
		}
		i++;
	}
}
