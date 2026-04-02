/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:26:24 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 00:12:59 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	make_color(double R_c, double G_c, double B_c)
{
	t_color	color;

	if (R_c < 0.0)
		R_c = 0.0;
	else if (R_c > 1.0)
		R_c = 1.0;
	if (G_c < 0.0)
		G_c = 0.0;
	else if (G_c > 1.0)
		G_c = 1.0;
	if (B_c < 0.0)
		B_c = 0.0;
	else if (B_c > 1.0)
		B_c = 1.0;
	color.r = R_c;
	color.g = G_c;
	color.b = B_c;
	return (color);
}

void	reset_color(t_color *color)
{
	color->r = 0.0;
	color->g = 0.0;
	color->b = 0.0;
	color->hex = 0;
	return ;
}
