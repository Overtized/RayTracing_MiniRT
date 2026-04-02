/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_apply_mat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:21:13 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/29 19:41:25 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	apply_intensity(t_object *cursor, t_mat *materials)
{
	t_sphere	*sp;

	cursor->materia = materials[2];
	if (cursor->type == OBJ_SPHERE)
	{
		sp = (t_sphere *)cursor->data;
		if (sp->color.r == 1.0 && sp->color.g == 1.0 && sp->color.b == 1.0)
		{
			cursor->has_pattern = false;
			cursor->materia = materials[1];
		}
		else
			cursor->materia.intensity = sp->color;
	}
	else if (cursor->type == OBJ_PLANE)
		cursor->materia.intensity = ((t_plane *)cursor->data)->color;
	else if (cursor->type == OBJ_CYLINDER)
		cursor->materia.intensity = ((t_cylinder *)cursor->data)->color;
	else if (cursor->type == OBJ_CONE)
		cursor->materia.intensity = ((t_cone *)cursor->data)->color;
}

static void	check_special_case(t_object *cursor)
{
	t_cylinder	*cy;
	t_cone		*co;

	if (cursor->type == OBJ_CYLINDER)
	{
		cy = (t_cylinder *)cursor->data;
		if ((cy->color.r == 1.0 && cy->color.g == 1.0 && cy->color.b == 1.0)
			&& cy->orientation.p.z == 1)
			cy->closed = false;
	}
	else if (cursor->type == OBJ_CONE)
	{
		co = (t_cone *)cursor->data;
		if ((co->color.r == 1.0 && co->color.g == 1.0 && co->color.b == 1.0)
			&& co->orientation.p.z == 1)
			co->closed = false;
	}
}

void	choose_materia(t_object *obj_list, t_mat *materials)
{
	t_object	*cursor;

	cursor = obj_list;
	while (cursor)
	{
		if (cursor->type == OBJ_PLANE)
			cursor->pattern = create_checkerboard_pattern(1, STRIPES);
		else if (cursor->type == OBJ_CYLINDER)
			cursor->pattern = new_patt(make_color(1, 0, 0),
					make_color(0.2, 1, 0.8), 1, GRADIENT);
		else if (cursor->type == OBJ_CONE)
			cursor->pattern = new_patt(make_color(1, 0, 0),
					make_color(0.2, 1, 1), 1, GRADIENT);
		else if (cursor->type == OBJ_SPHERE)
			cursor->pattern = new_patt(make_color(1, 0, 0),
					make_color(0.2, 1, 0.8), 1, GRADIENT);
		cursor->has_pattern = true;
		apply_intensity(cursor, materials);
		check_special_case(cursor);
		cursor = cursor->next;
	}
}
