/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:57:30 by lchiche           #+#    #+#             */
/*   Updated: 2026/03/29 19:39:05 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	fill_plane(t_scene *scene, char **input, size_t obj_idx)
{
	t_object	*new_obj;
	t_plane		*new_plane;

	new_plane = ft_calloc(1, sizeof(t_plane));
	if (!new_plane)
		return (ft_free_double_char(input), true);
	if (fill_vec3(&new_plane->pos.p, input[1]))
		return (free(new_plane), ft_free_double_char(input), true);
	else if (fill_vec3(&new_plane->orientation.p, input[2]))
		return (free(new_plane), ft_free_double_char(input), true);
	else if (fill_rgb(&new_plane->color, input[3]))
		return (free(new_plane), ft_free_double_char(input), true);
	ft_free_double_char(input);
	new_plane->transform = identity_matrix();
	new_plane->normal = normalize_vector(new_plane->orientation);
	new_obj = new_object(OBJ_PLANE, new_plane, obj_idx);
	if (!new_obj)
		return (free(new_plane), true);
	new_obj->has_pattern = false;
	new_obj->inv_m = get_inv_transfo_pl(new_obj);
	new_obj->trans_inv_m = cpy_matrix(&new_obj->inv_m);
	transpose_matrix(&new_obj->trans_inv_m);
	add_object(&scene->objects, new_obj);
	return (false);
}

bool	fill_sphere(t_scene *scene, char **input, size_t obj_idx)
{
	t_object	*new_obj;
	t_sphere	*new_sphere;

	new_sphere = ft_calloc(1, sizeof(t_sphere));
	if (!new_sphere)
		return (ft_free_double_char(input), true);
	if (fill_vec3(&new_sphere->pos.p, input[1]))
		return (free(new_sphere), ft_free_double_char(input), true);
	else if (fill_unfloat(&new_sphere->diameter, input[2]))
		return (free(new_sphere), ft_free_double_char(input), true);
	else if (fill_rgb(&new_sphere->color, input[3]))
		return (free(new_sphere), ft_free_double_char(input), true);
	ft_free_double_char(input);
	new_obj = new_object(OBJ_SPHERE, new_sphere, obj_idx);
	if (!new_obj)
		return (free(new_sphere), true);
	new_obj->has_pattern = false;
	new_obj->inv_m = get_inv_transfo_sp(new_obj);
	new_obj->trans_inv_m = cpy_matrix(&new_obj->inv_m);
	add_object(&scene->objects, new_obj);
	return (false);
}

bool	fill_cylinder(t_scene *scene, char **input, size_t obj_idx)
{
	t_object	*new_obj;
	t_cylinder	*new_cylender;

	new_cylender = ft_calloc(1, sizeof(t_cylinder));
	if (!new_cylender)
		return (ft_free_double_char(input), true);
	if (fill_vec3(&new_cylender->pos.p, input[1])
		|| fill_vec3(&new_cylender->orientation.p, input[2]))
		return (free(new_cylender), ft_free_double_char(input), true);
	else if (fill_unfloat(&new_cylender->diameter, input[3])
		|| fill_unfloat(&new_cylender->height, input[4]))
		return (free(new_cylender), ft_free_double_char(input), true);
	else if (fill_rgb(&new_cylender->color, input[5]))
		return (free(new_cylender), ft_free_double_char(input), true);
	ft_free_double_char(input);
	new_cylender->h = new_cylender->height / 2;
	new_cylender->closed = true;
	new_obj = new_object(OBJ_CYLINDER, new_cylender, obj_idx);
	if (!new_obj)
		return (free(new_cylender), true);
	new_obj->has_pattern = false;
	new_obj->inv_m = get_inv_transfo_cy(new_obj);
	new_obj->trans_inv_m = cpy_matrix(&new_obj->inv_m);
	transpose_matrix(&new_obj->trans_inv_m);
	return (add_object(&scene->objects, new_obj), false);
}

bool	fill_cone(t_scene *scene, char **input, size_t obj_idx)
{
	t_object	*new_obj;
	t_cone		*new_cone;

	new_cone = ft_calloc(1, sizeof(t_cone));
	if (!new_cone)
		return (ft_free_double_char(input), true);
	if (fill_vec3(&new_cone->pos.p, input[1])
		|| fill_vec3(&new_cone->orientation.p, input[2]))
		return (free(new_cone), ft_free_double_char(input), true);
	else if (fill_unfloat(&new_cone->diameter, input[3])
		|| fill_unfloat(&new_cone->height, input[4]))
		return (free(new_cone), ft_free_double_char(input), true);
	else if (fill_rgb(&new_cone->color, input[5]))
		return (free(new_cone), ft_free_double_char(input), true);
	ft_free_double_char(input);
	new_cone->closed = true;
	new_cone->h = new_cone->height / 2;
	new_obj = new_object(OBJ_CONE, new_cone, obj_idx);
	if (!new_obj)
		return (free(new_cone), true);
	new_obj->has_pattern = false;
	new_obj->inv_m = get_inv_transfo_co(new_obj);
	new_obj->trans_inv_m = cpy_matrix(&new_obj->inv_m);
	transpose_matrix(&new_obj->trans_inv_m);
	return (add_object(&scene->objects, new_obj), false);
}
