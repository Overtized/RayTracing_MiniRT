/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tranform_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 12:16:10 by mchanlia          #+#    #+#             */
/*   Updated: 2026/04/01 14:42:47 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_camera	*camera_rotate_y(t_camera *cam, float angle)
{
	float	rad;
	float	old_x;
	float	old_z;

	rad = angle * (M_PI / 180.0);
	old_x = cam->orientation.p.x;
	old_z = cam->orientation.p.z;
	cam->orientation.p.x = old_x * cos(rad) + old_z * sin(rad);
	cam->orientation.p.z = -old_x * sin(rad) + old_z * cos(rad);
	cam->orientation = normalize_vector(cam->orientation);
	return (cam);
}

t_camera	*camera_rotate_x(t_camera *cam, float angle)
{
	float	rad;
	float	old_y;
	float	old_z;

	rad = angle * (M_PI / 180.0);
	old_y = cam->orientation.p.y;
	old_z = cam->orientation.p.z;
	cam->orientation.p.y = old_y * cos(rad) - old_z * sin(rad);
	cam->orientation.p.z = old_y * sin(rad) + old_z * cos(rad);
	if (cam->orientation.p.y > 0.99)
		cam->orientation.p.y = 0.99;
	if (cam->orientation.p.y < -0.99)
		cam->orientation.p.y = -0.99;
	cam->orientation = normalize_vector(cam->orientation);
	return (cam);
}

t_camera	*camera_rotate_z(t_camera *cam, float angle)
{
	float		rad;
	t_matrix	roll_mat;
	t_matrix	new_transform;

	rad = angle * (M_PI / 180.0);
	roll_mat = rotate_z(rad);
	multiply_matrices(&cam->tranform, &roll_mat, &new_transform);
	cam->tranform = new_transform;
	invert_matrix(&cam->tranform, &cam->inv_tranform);
	return (cam);
}

t_camera	*reset_camera_position(t_camera *cam)
{
	cam->pos = cam->og_pos;
	cam->orientation = cam->og_orient;
	return (cam);
}

t_camera	*camera_translate(t_camera *cam, float x, float y, float z)
{
	cam->pos = transl_transf (x, y, z, cam->pos);
	return (cam);
}
