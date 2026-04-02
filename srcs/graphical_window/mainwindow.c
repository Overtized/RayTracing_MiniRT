/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainwindow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:34:14 by lchiche           #+#    #+#             */
/*   Updated: 2026/04/01 14:38:05 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	render_loop(t_vars *mlx)
{
	if (mlx->need_redraw)
	{
		if (mlx->img.img)
			mlx_destroy_image(mlx->mlx, mlx->img.img);
		if (!create_image(&(mlx)->img, mlx, mlx->scene))
		{
			mlx->error = true;
			mlx_loop_end(mlx->mlx);
			return (1);
		}
		mlx->need_redraw = false;
	}
	return (0);
}

bool	mainwindow(t_scene *scene)
{
	t_vars	vars;

	ft_memset(&vars, 0, sizeof(t_vars));
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (false);
	vars.need_redraw = true;
	vars.win = mlx_new_window(vars.mlx, WINDOW_X, WINDOW_Y, "MINI_RT 1500x750");
	if (!vars.win)
		return (free(vars.mlx), false);
	vars.scene = scene;
	vars.error = false;
	mlx_loop_hook(vars.mlx, render_loop, &vars);
	init_key_hook(&vars);
	mlx_loop(vars.mlx);
	if (vars.img.img)
		mlx_destroy_image(vars.mlx, vars.img.img);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	if (vars.error)
		return (false);
	return (true);
}
