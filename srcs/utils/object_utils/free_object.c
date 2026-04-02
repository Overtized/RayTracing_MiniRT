/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:24:16 by lchiche           #+#    #+#             */
/*   Updated: 2026/03/28 00:37:29 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_all_objects(t_object *obj)
{
	t_object	*cursor;

	if (!obj)
		return ;
	while (obj)
	{
		cursor = obj->next;
		if (obj->data)
		{
			free(obj->data);
			obj->data = NULL;
		}
		free(obj);
		obj = cursor;
	}
	obj = NULL;
	return ;
}
