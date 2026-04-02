/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 16:17:50 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:24:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_plane	*create_plane(void)
{
	t_plane	*new_plane;

	new_plane = malloc(1 * sizeof(t_plane));
	if (!new_plane)
		return (write_err(" malloc error"), NULL);
	new_plane->transform = identity_matrix();
	new_plane->pos = make_point(0, 0, 0, GREEN);
	new_plane->color = new_plane->pos.color;
	new_plane->orientation.p.x = 0;
	new_plane->orientation.p.y = 1;
	new_plane->orientation.p.z = 0;
	new_plane->orientation.p.w = 0;
	return (new_plane);
}
