/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_n_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 13:14:23 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 13:16:20 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_it	*create_single_inter(double t, t_object *obj)
{
	t_it	*new;

	new = malloc(1 * sizeof(t_it));
	if (!new)
		return (NULL);
	new->count = 1;
	new->t[0] = t;
	new->t[1] = t;
	new->t[2] = t;
	new->t[3] = t;
	new->obj = obj;
	new->next = NULL;
	return (new);
}

static t_it	*split_its(t_it *old_list)
{
	t_it	*new_list;
	t_it	*curr;
	t_it	*single_inter1;
	t_it	*single_inter2;

	curr = old_list;
	new_list = NULL;
	while (curr)
	{
		single_inter1 = create_single_inter(curr->t[0], curr->obj);
		if (!single_inter1)
			return (write_err("malloc failure in split inter\n"),
				free_all_intersections(new_list), NULL);
		add_intersection(&new_list, single_inter1);
		if (curr->count == 2 && curr->t[0] != curr->t[1])
		{
			single_inter2 = create_single_inter(curr->t[1], curr->obj);
			if (!single_inter2)
				return (write_err("malloc failure in split inter\n"),
					free_all_intersections(new_list), NULL);
			add_intersection(&new_list, single_inter2);
		}
		curr = curr->next;
	}
	return (sort_inter_list(&new_list), new_list);
}

double	get_last_n(t_cont_n *container)
{
	t_cont_n	*tmp;

	if (!container)
		return (1.0);
	tmp = container;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->obj->materia.refractive_index);
}

bool	create_new_lst(t_it **new_lst, t_it *old_lst, t_comps *comps)
{
	comps->n[0] = 1.0;
	comps->n[1] = 1.0;
	if (old_lst)
	{
		*new_lst = split_its(old_lst);
		if (!*new_lst)
			return (write_err("split_inter_failure"), false);
	}
	return (true);
}

void	manage_cont_lst(t_cont_n **cont, t_it *cursor)
{
	if (get_cont_o(*cont, cursor->obj))
		del_obj_from_cont(cont, cursor->obj);
	else
		add_container_node(cont, cursor->obj);
}
