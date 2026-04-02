/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:05:49 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:24:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray	create_ray(t_point origin, t_point direction)
{
	t_ray	raycast;

	if (origin.p.w != 1 || direction.p.w != 0)
	{
		print_p_attributes(origin, "origin");
		print_p_attributes(direction, "dir");
		return (write_err("wrong point or vec values\n"), create_error_ray());
	}
	raycast.og = origin;
	raycast.dir = direction;
	raycast.curr = origin;
	raycast.error = false;
	return (raycast);
}

t_ray	create_error_ray(void)
{
	t_ray	error_ray;

	error_ray = create_ray(make_point_error(), make_point_error());
	error_ray.error = true;
	return (error_ray);
}

t_point	get_ray_position(t_ray ray, float time)
{
	t_point	dir_temp;

	if (ray.og.p.w != 1 || ray.dir.p.w != 0)
		return (write_err("wrong point or vec values\n"), make_point_error());
	dir_temp = scale_tupple(ray.dir, time);
	ray.curr = sum_two_points(ray.og, dir_temp);
	return (ray.curr);
}

t_ray	clone_ray(t_ray *ray)
{
	t_ray	new_ray;

	new_ray.og = copy_point(ray->og);
	new_ray.curr = copy_point (ray->curr);
	new_ray.dir = copy_vector(ray->dir);
	return (new_ray);
}
