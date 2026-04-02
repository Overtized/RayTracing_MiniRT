/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:55:05 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 00:37:57 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_object	*return_object_data(t_object *obj_list, t_objtype type)
{
	t_object	*obj_list_cursor;

	obj_list_cursor = obj_list;
	while (obj_list_cursor)
	{
		if (obj_list_cursor->type == type)
			return (obj_list_cursor);
		obj_list_cursor = obj_list_cursor->next;
	}
	write_err("can't find specific object\n");
	return (obj_list_cursor);
}
