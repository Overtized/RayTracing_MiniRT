/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 11:48:42 by mchanlia          #+#    #+#             */
/*   Updated: 2026/04/01 14:45:53 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	move_left(void *param)
{
	t_vars	*vars;
	t_scene	*scene;

	vars = (t_vars *)param;
	scene = vars->scene;
	camera_translate(scene->camera, -5, 0, 0);
	compute_basics_cam(scene->camera);
	compute_pixel_size(scene->camera);
	vars->need_redraw = true;
	return (0);
}

int	move_right(void *param)
{
	t_vars	*vars;
	t_scene	*scene;

	vars = (t_vars *)param;
	scene = vars->scene;
	camera_translate(scene->camera, 5, 0, 0);
	compute_basics_cam(scene->camera);
	compute_pixel_size(scene->camera);
	vars->need_redraw = true;
	return (0);
}

int	move_up(void *param)
{
	t_vars	*vars;
	t_scene	*scene;

	vars = (t_vars *)param;
	scene = vars->scene;
	camera_translate(scene->camera, 0, 5, 0);
	compute_basics_cam(scene->camera);
	compute_pixel_size(scene->camera);
	vars->need_redraw = true;
	return (0);
}

int	move_down(void *param)
{
	t_vars	*vars;
	t_scene	*scene;

	vars = (t_vars *)param;
	scene = vars->scene;
	camera_translate(scene->camera, 0, -5, 0);
	compute_basics_cam(scene->camera);
	compute_pixel_size(scene->camera);
	vars->need_redraw = true;
	return (0);
}
