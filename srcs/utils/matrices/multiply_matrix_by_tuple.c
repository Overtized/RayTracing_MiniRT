/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrix_by_tuple.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:56:29 by mchanlia          #+#    #+#             */
/*   Updated: 2026/04/01 16:14:10 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// t_point	multiply_m_by_m(t_matrix *m, t_point t)
// {
// 	t_point	res;

// 	res.p.x = m->m[0][0] * t.p.x + m->m[0][1] * t.p.y + m->m[0][2]
// 		* t.p.z + m->m[0][3] * t.p.w;
// 	res.p.y = m->m[1][0] * t.p.x + m->m[1][1] * t.p.y + m->m[1][2]
// 		* t.p.z + m->m[1][3] * t.p.w;
// 	res.p.z = m->m[2][0] * t.p.x + m->m[2][1] * t.p.y + m->m[2][2]
// 		* t.p.z + m->m[2][3] * t.p.w;
// 	res.p.w = m->m[3][0] * t.p.x + m->m[3][1] * t.p.y + m->m[3][2]
// 		* t.p.z + m->m[3][3] * t.p.w;
// 	res.color = t.color;
// 	res.error = false;
// 	return (res);
// }
