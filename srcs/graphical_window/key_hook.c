/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:31:47 by lchiche           #+#    #+#             */
/*   Updated: 2026/03/30 09:54:30 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
//LISTE DES KEYCODES : https://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h

// void	init_fct(t_vars *vars)
// {
// 	ft_memset(vars->tab_fct, 0, sizeof(vars->tab_fct));
// 	vars->tab_fct[ESCAPE] = (void *)close_window;
// 	vars->tab_fct[W] = (void *) step_in;// +z
// 	vars->tab_fct[S] = (void *) step_out;// -z
// 	vars->tab_fct[A] = (void *) move_left;// -x
// 	vars->tab_fct[D] = (void *) move_right;// +x
// 	vars->tab_fct[Q] = (void *) angle_left;// angle left
// 	vars->tab_fct[E] = (void *) angle_right;// angle right
// 	vars->tab_fct[T] = (void *) angle_up;// angle up
// 	vars->tab_fct[G] = (void *) angle_down;// angle down
// 	vars->tab_fct[R] = (void *) move_up;// +y
// 	vars->tab_fct[F] = (void *) move_down;// -y
// 	vars->tab_fct[C] = (void *) reset_cam;// reset
// }

void	init_fct(t_vars *vars)
{
	ft_memset(vars->tab_fct, 0, sizeof(vars->tab_fct));
	vars->tab_fct[ESCAPE] = (void *)close_window;
	vars->tab_fct[W] = (void *) step_in;
	vars->tab_fct[S] = (void *) step_out;
	vars->tab_fct[A] = (void *) move_left;
	vars->tab_fct[D] = (void *) move_right;
	vars->tab_fct[Q] = (void *) angle_left;
	vars->tab_fct[E] = (void *) angle_right;
	vars->tab_fct[T] = (void *) angle_up;
	vars->tab_fct[G] = (void *) angle_down;
	vars->tab_fct[Y] = (void *) angle_minus_z;
	vars->tab_fct[H] = (void *) angle_plus_z;
	vars->tab_fct[R] = (void *) move_up;
	vars->tab_fct[F] = (void *) move_down;
	vars->tab_fct[C] = (void *) reset_cam;
	vars->tab_fct[P] = (void *) toggle_stripes;
}

int	key_hook(int keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (!vars->tab_fct[keycode])
		return (0);
	vars->tab_fct[keycode](vars);
	return (0);
}

void	init_key_hook(t_vars *vars)
{
	init_fct(vars);
	mlx_hook(vars->win, ESCAPE_CROSS, 0, close_window, vars);
	mlx_key_hook(vars->win, key_hook, vars);
}
// vars->tab_fct[I] = (void *)zoom_in;
// vars->tab_fct[O] = (void *)zoom_out;
// vars->tab_fct[P] = (void *)change_proj;
// vars->tab_fct[U] = (void *)level_up;
// vars->tab_fct[D] = (void *)level_down;
// vars->tab_fct[LEFT] = (void *)move_left;
// vars->tab_fct[RIGHT] = (void *)move_right;
// vars->tab_fct[UP] = (void *)move_up;
// vars->tab_fct[DOWN] = (void *)move_down;
// vars->tab_fct[M] = (void *)reset_proj;
// vars->tab_fct[C] = (void *)change_color;
// vars->tab_fct[X] = (void *)rotate_x;
// vars->tab_fct[Y] = (void *)rotate_y;
// vars->tab_fct[Z] = (void *)rotate_z;
// ici la fonction pour bouger la cam et set need redraw a true
// mlx_hook(vars->win, 2, 1L<<0, handle_press, vars);
// mlx_hook(vars->win, 3, 1L<<1, handle_release, vars);