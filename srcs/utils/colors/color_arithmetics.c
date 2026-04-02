/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_arithmetics.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:27:52 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 00:06:30 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	sum_two_colors(t_color a, t_color b)
{
	t_color	c;

	c.r = a.r + b.r;
	c.g = a.g + b.g;
	c.b = a.b + b.b;
	if (c.r < 0)
		c.r = 0;
	else if (c.r > 255)
		c.r = 255;
	if (c.g < 0)
		c.g = 0;
	else if (c.g > 255)
		c.g = 255;
	if (c.b < 0)
		c.b = 0;
	else if (c.b > 255)
		c.b = 255;
	return (c);
}

t_color	sum_three_colors(t_color a, t_color b, t_color d)
{
	t_color	c;

	c.r = a.r + b.r + d.r;
	c.g = a.g + b.g + d.g;
	c.b = a.b + b.b + d.b;
	if (c.r < 0)
		c.r = 0;
	else if (c.r > 255)
		c.r = 255;
	if (c.g < 0)
		c.g = 0;
	else if (c.g > 255)
		c.g = 255;
	if (c.b < 0)
		c.b = 0;
	else if (c.b > 255)
		c.b = 255;
	return (c);
}

t_color	sub_two_colors(t_color a, t_color b)
{
	t_color	c;

	c.r = a.r - b.r;
	c.g = a.g - b.g;
	c.b = a.b - b.b;
	if (c.r < 0)
		c.r = 0;
	else if (c.r > 255)
		c.r = 255;
	if (c.g < 0)
		c.g = 0;
	else if (c.g > 255)
		c.g = 255;
	if (c.b < 0)
		c.b = 0;
	else if (c.b > 255)
		c.b = 255;
	return (c);
}

t_color	multiply_color(t_color a, float scalar)
{
	double	rgb[3];
	t_color	c;

	rgb[0] = a.r * scalar;
	rgb[1] = a.g * scalar;
	rgb[2] = a.b * scalar;
	if (rgb[0] < 0)
		rgb[0] = 0;
	else if (rgb[0] > 255.0f)
		rgb[0] = 255.0f;
	if (rgb[1] < 0)
		rgb[1] = 0;
	else if (rgb[1] > 255.0f)
		rgb[1] = 255.0f;
	if (rgb[2] < 0)
		rgb[2] = 0;
	else if (rgb[2] > 255.0f)
		rgb[2] = 255.0f;
	c.r = rgb[0];
	c.g = rgb[1];
	c.b = rgb[2];
	return (c);
}

t_color	hadamard_product(t_color a, t_color b)
{
	t_color	c;

	c.r = a.r * b.r;
	c.g = a.g * b.g;
	c.b = a.b * b.b;
	if (c.r < 0)
		c.r = 0;
	else if (c.r > 255)
		c.r = 255;
	if (c.g < 0)
		c.g = 0;
	else if (c.g > 255)
		c.g = 255;
	if (c.b < 0)
		c.b = 0;
	else if (c.b > 255)
		c.b = 255;
	return (c);
}
