/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_lst_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:01:18 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 00:37:47 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

size_t	obj_lst_size(t_object *obj_lst)
{
	t_object	*tmp;
	size_t		counter;

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
