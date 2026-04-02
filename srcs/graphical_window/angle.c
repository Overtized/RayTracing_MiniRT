/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 11:50:10 by mchanlia          #+#    #+#             */
/*   Updated: 2026/04/01 14:42:38 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	angle_right(void *param)
{
	t_vars	*vars;
	t_scene	*scene;

	vars = (t_vars *)param;
	scene = vars->scene;
	camera_rotate_y(scene->camera, 4);
	compute_basics_cam(scene->camera);
	compute_pixel_size(scene->camera);
	vars->need_redraw = true;
	return (0);
}

int	angle_left(void *param)
{
	t_vars	*vars;
	t_scene	*scene;

	vars = (t_vars *)param;
	scene = vars->scene;
	camera_rotate_y(scene->camera, -4);
	compute_basics_cam(scene->camera);
	compute_pixel_size(scene->camera);
	vars->need_redraw = true;
	return (0);
}

int	angle_up(void *param)
{
	t_vars	*vars;
	t_scene	*scene;

	vars = (t_vars *)param;
	scene = vars->scene;
	camera_rotate_x(scene->camera, -4);
	compute_basics_cam(scene->camera);
	compute_pixel_size(scene->camera);
	vars->need_redraw = true;
	return (0);
}

int	angle_down(void *param)
{
	t_vars	*vars;
	t_scene	*scene;

	vars = (t_vars *)param;
	scene = vars->scene;
	camera_rotate_x(scene->camera, 4);
	compute_basics_cam(scene->camera);
	compute_pixel_size(scene->camera);
	vars->need_redraw = true;
	return (0);
}
