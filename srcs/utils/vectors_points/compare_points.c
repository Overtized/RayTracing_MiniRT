/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:36:29 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:43:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	compare_points(t_point p1, t_point p2)
{
	bool	x_equality;
	bool	y_equality;
	bool	z_equality;

	x_equality = false;
	y_equality = false;
	z_equality = false;
	if (fabs(p1.p.x - p2.p.x) < P_EPS)
		x_equality = true;
	if (fabs(p1.p.y - p2.p.y) < P_EPS)
		y_equality = true;
	if (fabs(p1.p.z - p2.p.z) < P_EPS)
		z_equality = true;
	if (x_equality && y_equality && z_equality)
		return (true);
	return (false);
}
