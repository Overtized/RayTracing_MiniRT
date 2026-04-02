/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_view_transform.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:35:33 by mchanlia          #+#    #+#             */
/*   Updated: 2026/04/01 14:32:45 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static float	convert_degree_to_radians(int degree)
{
	float	radian;

	radian = (degree / 180.0) * M_PI;
	return (radian);
}

void	compute_basics_cam(t_camera *camera)
{
	t_point		to;
	t_point		up;
	t_matrix	inverted;

	ft_bzero (&inverted, sizeof(t_matrix));
	to = sum_two_points(camera->pos, camera->orientation);
	up = make_vector(0, 1, 0, 0);
	if (fabs(camera->orientation.p.y) > 0.999)
	{
		up.p.y = 0;
		up.p.z = 1;
	}
	camera->tranform = view_transform(camera->pos, to, point_to_vec3(up));
	invert_matrix(&camera->tranform, &inverted);
	camera->inv_tranform = inverted;
	return ;
}

void	compute_pixel_size(t_camera *camera)
{
	double	half_view;
	double	aspect;
	double	radians;

	radians = convert_degree_to_radians(camera->deg_range);
	half_view = tan(radians / 2);
	aspect = (double)WINDOW_X / (double)WINDOW_Y;
	if (aspect >= 1.0)
	{
		camera->half_width = half_view;
		camera->half_height = half_view / aspect;
	}
	else
	{
		camera->half_width = half_view * aspect;
		camera->half_height = half_view;
	}
	camera->pixel_size = (camera->half_width * 2) / WINDOW_X;
	return ;
}

static void	fill_orientation(t_matrix *orientation, t_vec3 *left,
	t_vec3 true_up, t_vec3 *forward )
{
	orientation->m[0][0] = left->x;
	orientation->m[0][1] = left->y;
	orientation->m[0][2] = left->z;
	orientation->m[1][0] = true_up.x;
	orientation->m[1][1] = true_up.y;
	orientation->m[1][2] = true_up.z;
	orientation->m[2][0] = -forward->x;
	orientation->m[2][1] = -forward->y;
	orientation->m[2][2] = -forward->z;
	return ;
}

t_matrix	view_transform(t_point from, t_point to, t_vec3 up)
{
	t_vec3		forward;
	t_vec3		left;
	t_matrix	orientation;
	t_matrix	translation_m;
	t_matrix	res;

	forward = normalize_vec3(point_to_vec3((sub_two_points(to, from))));
	left = vec3_cross_product (forward, normalize_vec3(up));
	orientation = identity_matrix();
	fill_orientation(&orientation, &left, normalize_vec3
		(vec3_cross_product(left, forward)), &forward);
	translation_m = translation(-from.p.x, -from.p.y, -from.p.z);
	multiply_matrices(&orientation, &translation_m, &res);
	return (res);
}
