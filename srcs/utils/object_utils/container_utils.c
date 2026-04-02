/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:47:38 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 00:36:40 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_object	*get_cont_o(t_cont_n *container, t_object *target)
{
	t_cont_n	*cursor;

	cursor = container;
	while (cursor)
	{
		if (cursor->obj == target)
			return (cursor->obj);
		cursor = cursor->next;
	}
	return (NULL);
}

t_cont_n	*add_container_node(t_cont_n **lst, t_object *obj)
{
	t_cont_n	*new;

	new = malloc(1 * sizeof(t_cont_n));
	if (!new)
		return (NULL);
	new->obj = obj;
	new->next = *lst;
	*lst = new;
	return (new);
}

void	del_obj_from_cont(t_cont_n **lst, t_object *target)
{
	t_cont_n	*tmp;
	t_cont_n	*prev;

	tmp = *lst;
	prev = NULL;
	while (tmp)
	{
		if (tmp->obj == target)
		{
			if (prev)
				prev->next = tmp->next;
			else
				*lst = tmp->next;
			free(tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void	free_all_containers(t_cont_n **lst)
{
	t_cont_n	*next;
	t_cont_n	*cursor;

	if (!lst || !*lst)
		return ;
	cursor = *lst;
	while (cursor)
	{
		next = cursor->next;
		free(cursor);
		cursor = next;
	}
	*lst = NULL;
	return ;
}
