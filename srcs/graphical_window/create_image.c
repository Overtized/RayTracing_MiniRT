/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:36:49 by lchiche           #+#    #+#             */
/*   Updated: 2026/07/16 05:56:22 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	color_to_hex(t_color c)
{
	int	r;
	int	g;
	int	b;

	r = (int)(c.r * 255.99);
	if (r > 255)
		r = 255;
	if (r < 0)
		r = 0;
	g = (int)(c.g * 255.99);
	if (g > 255)
		g = 255;
	if (g < 0)
		g = 0;
	b = (int)(c.b * 255.99);
	if (b > 255)
		b = 255;
	if (b < 0)
		b = 0;
	return (r << 16 | g << 8 | b);
}

static void	camera_ray(t_camera *cam, int x, int y, t_ray *ray)
{
	double	world_x;
	double	world_y;
	t_point	pixel_c;
	t_point	pixel_w_sp;
	t_point	origin_w_sp;

	world_x = cam->half_width - (x + 0.5) * cam->pixel_size;
	world_y = cam->half_height - (y + 0.5) * cam->pixel_size;
	pixel_c = make_point(world_x, world_y, -1, 0);
	pixel_w_sp = multiply_m_by_m(&cam->inv_tranform, pixel_c);
	origin_w_sp = multiply_m_by_m(&cam->inv_tranform, make_point(0, 0, 0, 0));
	ray->og = origin_w_sp;
	ray->dir = normalize_vector(sub_two_points(pixel_w_sp, origin_w_sp));
	return ;
}

static bool	fill_image(t_data *img, t_scene *scene)
{
	int		x;
	int		y;
	t_ray	ray;
	t_color	color;

	y = -1;
	ray = create_ray(make_point(0, 0, 0, GREEN), make_vector(0, 0, 0, GREEN)); // make an initial ray vector
	while (++y < WINDOW_Y) // cover the whole image from top to bottom, left to right
	{
		x = -1;
		while (++x < WINDOW_X)
		{
			reset_color(&color); // color ressetting for garbage values
			if (x == 0 && y % 10 == 0)
				printf("Calcul de la ligne Y : %d / %d\n", y, WINDOW_Y);
			camera_ray(scene->camera, x, y, &ray); // point the ray in the camera facing direction
			if (ray.error)
				return (write_err("ray error"), false);
			if (!color_at(scene, &ray, &color)) // color the pixel based on the ray reaction or non reaction to things in its way (things get interesting here)
				return (write_err("color at function failure\n"), false);
			put_one_pixel(img, x, y, color_to_hex(color)); // put the pixel out on display
		}
	}
	return (true);
}

bool	create_image(t_data *img, t_vars *vars, t_scene *scene) // classic minilibx pipeline make a new image get its address value and put it to display
{
	if (!scene || !scene->camera)
		return (write_err("Error: No camera found in scene.\n"), false);
	img->img = mlx_new_image(vars->mlx, WINDOW_X, WINDOW_Y);
	if (!img || !img->img)
		return (write_err("mlx_new_image failure\n"), false);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->ll, &img->endian);
	if (!img || !img->addr)
		return (write_err("get_data_addr failure\n"), false);
	if (!fill_image(img, scene)) // this is where magic happens
		return (write_err("fill image failure\n"), false);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (true);
}
