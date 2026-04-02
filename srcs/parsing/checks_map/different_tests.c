/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   different_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:49:03 by lchiche           #+#    #+#             */
/*   Updated: 2026/03/27 23:16:09 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_rgb(char *arg)
{
	int		i;
	int		value;
	char	**rgb;

	i = 0;
	rgb = ft_split(arg, ',');
	if (!rgb)
		return (write_err("Error\n\tMalloc error : "));
	if (count_strs(rgb) != 3)
		return (ft_free_double_char(rgb),
			write_err("Error\n\tWrong number of RGB : "));
	while (i < 3)
	{
		if (ft_strlen(rgb[i]) > 3)
			return (ft_free_double_char(rgb),
				write_err("Error\n Overflow attempt on RGB : "));
		value = ft_atoi(rgb[i]);
		if (value < 0 || value > 255 || try_int_number(rgb[i]))
			return (ft_free_double_char(rgb),
				write_err("Error\n\tImpossible RGB value : "));
		i++;
	}
	ft_free_double_char(rgb);
	return (false);
}

bool	check_pos(char *arg)
{
	int		i;
	char	**pos;

	i = 0;
	pos = ft_split(arg, ',');
	if (!pos)
		return (write_err("Error\n\tMalloc error : "));
	if (count_strs(pos) != 3)
		return (ft_free_double_char(pos),
			write_err("Error\n\tWrong number of arguments : "));
	while (i < 3)
	{
		if (try_float_number(pos[i]))
			return (ft_free_double_char(pos),
				write_err("Error\n\tImpossible position value : "));
		i++;
	}
	ft_free_double_char(pos);
	return (false);
}

bool	check_orientation(char *arg)
{
	int		i;
	float	value;
	char	**orientation;

	i = 0;
	orientation = ft_split(arg, ',');
	if (!orientation)
		return (write_err("Error\n\tMalloc error : "));
	if (count_strs(orientation) != 3)
		return (ft_free_double_char(orientation),
			write_err("Error\n\tWrong number of arguments : "));
	while (i < 3)
	{
		value = ft_atof(orientation[i]);
		if (value < -1.0 || value > 1.0 || try_float_number(orientation[i]))
			return (ft_free_double_char(orientation),
				write_err("Error\n\tImpossible orientation value : "));
		i++;
	}
	if (ft_atof(orientation[0]) == 0.0 && ft_atof(orientation[1]) == 0.0
		&& ft_atof(orientation[2]) == 0.0)
		return (ft_free_double_char(orientation),
			write_err("Error\n\tNULL orientation value is impossible : "));
	ft_free_double_char(orientation);
	return (false);
}

bool	check_view_range(char *arg)
{
	int	value;

	if (ft_strlen(arg) > 3)
		return (write_err("Error\n overflow attempt on View Range : "));
	value = ft_atoi(arg);
	if (value < 0 || value > 180 || try_int_number(arg))
		return (write_err("Error\n\tImpossible field of view value : "));
	return (false);
}

bool	check_light_ratio(char *arg)
{
	float	value;

	value = ft_atof(arg);
	if (value < 0.0 || value > 1.0 || try_float_number(arg))
		return (write_err("Error\n\tImpossible light ratio value : "));
	return (false);
}
