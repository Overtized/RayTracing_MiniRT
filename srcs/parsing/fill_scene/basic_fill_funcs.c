/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_fill_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:56:26 by lchiche           #+#    #+#             */
/*   Updated: 2026/03/27 19:29:49 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	fill_light_ratio(float *light_ratio, char *input)
{
	*light_ratio = ft_atof(input);
	return (false);
}

bool	fill_rgb(t_color *color, char *input)
{
	char	**rgb;

	rgb = ft_split(input, ',');
	if (!rgb)
		return (true);
	color->r = ft_atoi(rgb[0]) / 255.0;
	color->g = ft_atoi(rgb[1]) / 255.0;
	color->b = ft_atoi(rgb[2]) / 255.0;
	ft_free_double_char(rgb);
	return (false);
}

bool	fill_vec3(t_vec3 *vec3, char *input)
{
	char	**vectors;

	vectors = ft_split(input, ',');
	if (!vectors)
		return (true);
	vec3->x = ft_atof(vectors[0]);
	vec3->y = ft_atof(vectors[1]);
	vec3->z = ft_atof(vectors[2]);
	ft_free_double_char(vectors);
	return (false);
}

bool	fill_view_range(float *deg_range, char *input)
{
	*deg_range = ft_atof(input);
	return (false);
}

bool	fill_unfloat(double *unfloat, char *input)
{
	*unfloat = ft_atof(input);
	return (false);
}
