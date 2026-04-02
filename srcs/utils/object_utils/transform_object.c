/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:24:35 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/29 19:00:18 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_object	*set_default_transform(t_object *obj)
{
	if (obj->type == OBJ_SPHERE)
		((t_sphere *)obj->data)->pos
			= multiply_tuple_identity(((t_sphere *)obj->data)->pos);
	else if (obj->type == OBJ_PLANE)
		((t_plane *)obj->data)->pos
			= multiply_tuple_identity(((t_plane *)obj->data)->pos);
	else if (obj->type == OBJ_CYLINDER)
		((t_cylinder *)obj->data)->pos
			= multiply_tuple_identity(((t_cylinder *)obj->data)->pos);
	else
		return (write_err ("unknown object error"), NULL);
	return (obj);
}

t_object	*object_translate(t_object *obj, float x, float y, float z)
{
	if (obj->type == OBJ_SPHERE)
		((t_sphere *)obj->data)->pos
			= transl_transf (x, y, z, ((t_sphere *)obj->data)->pos);
	else if (obj->type == OBJ_PLANE)
		((t_plane *)obj->data)->pos
			= transl_transf (x, y, z, ((t_plane *)obj->data)->pos);
	else if (obj->type == OBJ_CYLINDER)
		((t_cylinder *)obj->data)->pos
			= transl_transf (x, y, z, ((t_cylinder *)obj->data)->pos);
	else
		return (write_err ("unknown object error"), NULL);
	return (obj);
}

t_object	*object_scaling(t_object *obj, float x, float y, float z)
{
	if (obj->type == OBJ_SPHERE)
		((t_sphere *)obj->data)->pos
			= scale_m_transf (x, y, z, ((t_sphere *)obj->data)->pos);
	else if (obj->type == OBJ_PLANE)
		((t_plane *)obj->data)->pos
			= scale_m_transf (x, y, z, ((t_plane *)obj->data)->pos);
	else if (obj->type == OBJ_CYLINDER)
		((t_cylinder *)obj->data)->pos
			= scale_m_transf (x, y, z, ((t_cylinder *)obj->data)->pos);
	else
		return (write_err ("unknown object error"), NULL);
	return (obj);
}
