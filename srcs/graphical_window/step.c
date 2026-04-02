/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 11:49:44 by mchanlia          #+#    #+#             */
/*   Updated: 2026/04/01 14:57:39 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	check_change(t_point a, t_point b)
{
	return (fabs(a.p.x - b.p.x) < 0.00001
		&& fabs(a.p.y - b.p.y) < 0.00001
		&& fabs(a.p.z - b.p.z) < 0.00001);
}

int	step_in(void *param)
{
	t_vars	*vars;
	t_scene	*scene;

	vars = (t_vars *)param;
	scene = vars->scene;
	camera_translate(scene->camera, 0, 0, 5);
	compute_basics_cam(scene->camera);
	compute_pixel_size(scene->camera);
	vars->need_redraw = true;
	return (0);
}

int	step_out(void *param)
{
	t_vars	*vars;
	t_scene	*scene;

	vars = (t_vars *)param;
	scene = vars->scene;
	camera_translate(scene->camera, 0, 0, -5);
	compute_basics_cam(scene->camera);
	compute_pixel_size(scene->camera);
	vars->need_redraw = true;
	return (0);
}

int	reset_cam(void *param)
{
	t_vars	*vars;
	t_scene	*scene;

	vars = (t_vars *)param;
	scene = vars->scene;
	if (!check_change(scene->camera->pos, scene->camera->og_pos)
		|| !check_change(scene->camera->orientation
			, scene->camera->og_orient))
	{
		reset_camera_position(scene->camera);
		compute_basics_cam(scene->camera);
		compute_pixel_size(scene->camera);
		vars->need_redraw = true;
	}
	return (0);
}

int	toggle_stripes(void *param)
{
	t_vars		*vars;
	t_scene		*scene;
	t_object	*obj;
	static bool	pressed = true;

	vars = (t_vars *)param;
	scene = vars->scene;
	obj = scene->objects;
	pressed = !pressed;
	while (obj)
	{
		obj->has_pattern = pressed;
		obj = obj->next;
	}
	vars->need_redraw = true;
	return (0);
}
