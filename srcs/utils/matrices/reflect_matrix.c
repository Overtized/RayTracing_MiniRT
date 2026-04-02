/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:07:11 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/27 19:00:47 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	check_ranges(float value, int *flag)
{
	if (value < -1 || value > 1)
		return (false);
	if (value == -1)
	{
		if (*flag == 1)
			return (false);
		*flag = 1;
	}
	return (true);
}

t_point	reflect_m_transf(double x, double y, double z,
		t_point in_tup)
{
	int		flag;
	t_point	new_tup;

	flag = 0;
	if (!check_ranges(x, &flag) || !check_ranges(y, &flag)
		|| !check_ranges(z, &flag))
		return (write_err ("wrong values"), make_point_error());
	new_tup = scale_m_transf(x, y, z, in_tup);
	if (new_tup.error)
		return (write_err ("wrong values"), new_tup);
	return (new_tup);
}
