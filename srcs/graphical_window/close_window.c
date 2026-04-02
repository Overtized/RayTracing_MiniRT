/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:30:51 by lchiche           #+#    #+#             */
/*   Updated: 2026/03/26 16:43:51 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	close_window(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	mlx_loop_end(vars->mlx);
	return (0);
}
