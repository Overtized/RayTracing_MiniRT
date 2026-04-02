/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:24:16 by lchiche           #+#    #+#             */
/*   Updated: 2026/03/28 00:37:22 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_all_lights(t_light **lights)
{
	t_light	*cursor;
	t_light	*curr_next;

	if (!lights || !*lights)
		return ;
	cursor = *lights;
	while (cursor)
	{
		curr_next = cursor->next;
		free(cursor);
		cursor = curr_next;
	}
	*lights = NULL;
	return ;
}
