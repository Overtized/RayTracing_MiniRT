/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:15:56 by mchanlia          #+#    #+#             */
/*   Updated: 2026/04/01 13:41:00 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	transform_ray(t_matrix *m, t_ray *input_r, t_ray *local_r)
{
	local_r->og.p.w = 1;
	local_r->og = multiply_m_by_m(m, input_r->og);
	if (local_r->og.error)
	{
		write_err ("multiply matrice error\n");
		return ;
	}
	local_r->dir.p.w = 0;
	local_r->dir = multiply_m_by_m(m, input_r->dir);
	if (local_r->dir.error)
		write_err ("multiply matrice error\n");
	return ;
}
