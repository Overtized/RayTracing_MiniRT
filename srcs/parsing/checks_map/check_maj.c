/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:01:50 by lchiche           #+#    #+#             */
/*   Updated: 2026/03/26 16:39:59 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_ambiant_light(char **args, int nb_arg)
{
	static bool	already_saw = false;

	if (already_saw)
		return (ft_free_double_char(args),
			write_err("Error\n\tMore than one A : "));
	already_saw = true;
	if (nb_arg != 3)
		return (ft_free_double_char(args),
			write_err("Error\n\tWrong number of arguments : "));
	if (check_light_ratio(args[1]))
		return (ft_free_double_char(args), true);
	else if (check_rgb(args[2]))
		return (ft_free_double_char(args), true);
	ft_free_double_char(args);
	return (false);
}

bool	check_camera(char **args, int nb_arg)
{
	static bool	already_saw = false;

	if (already_saw)
		return (ft_free_double_char(args),
			write_err("Error\n\tMore than one C : "));
	already_saw = true;
	if (nb_arg != 4)
		return (ft_free_double_char(args),
			write_err("Error\n\tWrong number of arguments : "));
	if (check_pos(args[1]))
		return (ft_free_double_char(args), true);
	else if (check_orientation(args[2]))
		return (ft_free_double_char(args), true);
	else if (check_view_range(args[3]))
		return (ft_free_double_char(args), true);
	ft_free_double_char(args);
	return (false);
}

bool	check_light(char **args, int nb_arg)
{
	if (nb_arg != 4)
		return (ft_free_double_char(args),
			write_err("Error\n\tWrong number of arguments : "));
	if (check_pos(args[1]))
		return (ft_free_double_char(args), true);
	else if (check_light_ratio(args[2]))
		return (ft_free_double_char(args), true);
	else if (check_rgb(args[3]))
		return (ft_free_double_char(args), true);
	ft_free_double_char(args);
	return (false);
}
