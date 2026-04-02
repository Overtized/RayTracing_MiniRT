/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:16:31 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:24:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_sphere	*create_sphere(void)
{
	t_sphere	*new_sphere;
	t_vec3		coordinate;

	new_sphere = malloc(1 * sizeof(t_sphere));
	if (!new_sphere)
		return (write_err(" malloc error"), NULL);
	coordinate.x = rand() % 10;
	coordinate.y = rand() % 10;
	coordinate.z = rand() % 10;
	coordinate.w = 1;
	new_sphere->color = make_color(0, 1, 0);
	new_sphere->diameter = 2;
	new_sphere->pos.p = coordinate;
	return (new_sphere);
}
