/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_z.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:47:06 by maxence           #+#    #+#             */
/*   Updated: 2026/04/01 13:59:24 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	angle_minus_z(void *param)
{
	t_vars	*vars;
	t_scene	*scene;

	vars = (t_vars *)param;
	scene = vars->scene;
	camera_rotate_z(scene->camera, -4);
	compute_pixel_size(scene->camera);
	vars->need_redraw = true;
	return (0);
}

int	angle_plus_z(void *param)
{
	t_vars	*vars;
	t_scene	*scene;

	vars = (t_vars *)param;
	scene = vars->scene;
	camera_rotate_z(scene->camera, 4);
	compute_pixel_size(scene->camera);
	vars->need_redraw = true;
	return (0);
}
