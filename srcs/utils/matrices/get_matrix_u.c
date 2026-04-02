/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:54:05 by maxence           #+#    #+#             */
/*   Updated: 2026/03/28 00:14:41 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	get_translation_m(double x, double y, double z)
{
	t_matrix	res;

	res = identity_matrix();
	res.m[0][3] = x;
	res.m[1][3] = y;
	res.m[2][3] = z;
	res.m[3][3] = 1;
	return (res);
}

t_matrix	get_scaling_m(double x, double y, double z)
{
	t_matrix	res;

	res = identity_matrix();
	res.m[0][0] = x;
	res.m[1][1] = y;
	res.m[2][2] = z;
	res.m[3][3] = 1;
	return (res);
}
