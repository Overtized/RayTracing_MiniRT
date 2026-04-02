/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 23:15:39 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/27 23:16:04 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_unfloat(char *arg)
{
	float	value;

	value = ft_atof(arg);
	if (value < 0.0 || try_float_number(arg))
		return (write_err("Error\n\tImpossible unsigned float value : "));
	return (false);
}
