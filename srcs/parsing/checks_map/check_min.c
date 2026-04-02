/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:02:28 by lchiche           #+#    #+#             */
/*   Updated: 2026/03/27 19:28:44 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_plane(char **args, int nb_arg)
{
	if (nb_arg != 4)
		return (ft_free_double_char(args),
			write_err("Error\n\tWrong number of arguments : "));
	if (check_pos(args[1]))
		return (ft_free_double_char(args), true);
	else if (check_orientation(args[2]))
		return (ft_free_double_char(args), true);
	else if (check_rgb(args[3]))
		return (ft_free_double_char(args), true);
	ft_free_double_char(args);
	return (false);
}

bool	check_sphere(char **args, int nb_arg)
{
	if (nb_arg != 4)
		return (ft_free_double_char(args),
			write_err("Error\n\tWrong number of arguments : "));
	if (check_pos(args[1]))
		return (ft_free_double_char(args), true);
	else if (check_unfloat(args[2]))
		return (ft_free_double_char(args),
			write_err(" diameter : "));
	else if (check_rgb(args[3]))
		return (ft_free_double_char(args), true);
	ft_free_double_char(args);
	return (false);
}

bool	check_cylinder_cone(char **args, int nb_arg)
{
	if (nb_arg != 6)
		return (ft_free_double_char(args),
			write_err("Error\n\tWrong number of arguments : "));
	if (check_pos(args[1]))
		return (ft_free_double_char(args), true);
	else if (check_orientation(args[2]))
		return (ft_free_double_char(args), true);
	else if (check_unfloat(args[3]))
		return (ft_free_double_char(args),
			write_err(" diameter : "));
	else if (check_unfloat(args[4]))
		return (ft_free_double_char(args), write_err(" height : "));
	else if (check_rgb(args[5]))
		return (ft_free_double_char(args), true);
	ft_free_double_char(args);
	return (false);
}
