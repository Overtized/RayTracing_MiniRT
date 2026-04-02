/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_maj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:57:13 by lchiche           #+#    #+#             */
/*   Updated: 2026/04/01 14:42:26 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	fill_ambiant_light(t_scene *scene, char **input)
{
	scene->ambient_light = ft_calloc(1, sizeof(t_ambient_light));
	if (!scene->ambient_light)
		return (ft_free_double_char(input), true);
	if (fill_light_ratio(&scene->ambient_light->light_ratio, input[1]))
		return (ft_free_double_char(input), true);
	else if (fill_rgb(&scene->ambient_light->color, input[2]))
		return (ft_free_double_char(input), true);
	ft_free_double_char(input);
	return (false);
}

bool	fill_camera(t_scene *scene, char **input)
{
	scene->camera = ft_calloc(1, sizeof(t_camera));
	if (!scene->camera)
		return (ft_free_double_char(input), true);
	scene->camera->pos.p.w = 1;
	if (fill_vec3(&scene->camera->pos.p, input[1]))
		return (ft_free_double_char(input), true);
	else if (fill_vec3(&scene->camera->orientation.p, input[2]))
		return (ft_free_double_char(input), true);
	else if (fill_view_range(&scene->camera->deg_range, input[3]))
		return (ft_free_double_char(input), true);
	scene->camera->og_pos = scene->camera->pos;
	scene->camera->og_orient = scene->camera->orientation;
	compute_basics_cam(scene->camera);
	compute_pixel_size(scene->camera);
	ft_free_double_char(input);
	return (false);
}

bool	fill_light(t_scene *scene, char **input)
{
	t_light	*new_light;

	new_light = ft_calloc(1, sizeof(t_light));
	if (!new_light)
		return (ft_free_double_char(input), true);
	new_light->pos.p.w = 1;
	if (fill_vec3(&new_light->pos.p, input[1]))
		return (ft_free_double_char(input), free(new_light), true);
	else if (fill_light_ratio(&new_light->light_ratio, input[2]))
		return (ft_free_double_char(input), free(new_light), true);
	else if (fill_rgb(&new_light->color, input[3]))
		return (ft_free_double_char(input), free(new_light), true);
	ft_free_double_char(input);
	add_light(&scene->light, new_light);
	return (false);
}
