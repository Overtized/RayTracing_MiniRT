/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inv_transfo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:36:15 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:24:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
// ici si on veut scale un objet pour l aplatir par ex on peut utiliser
//la fonction scale de scale matrix pour elargir et aplatir 
t_matrix	get_inv_transfo_sp(t_object *obj)
{
	t_matrix	m_scale ;
	t_matrix	m_trans ;
	t_matrix	m_total ;
	t_matrix	m_inverse ;
	t_sphere	*s;

	s = (t_sphere *)obj->data;
	m_scale = get_scaling_m(s->diameter / 2, s->diameter / 2, s->diameter / 2);
	m_trans = get_translation_m(s->pos.p.x, s->pos.p.y, s->pos.p.z);
	multiply_matrices(&m_trans, &m_scale, &m_total);
	invert_matrix(&m_total, &m_inverse);
	return (m_inverse);
}

t_matrix	get_inv_transfo_pl(t_object *obj)
{
	t_matrix	identity;
	t_matrix	inverse;

	identity = identity_matrix();
	invert_matrix(&identity, &inverse);
	(void)obj;
	return (inverse);
}

t_matrix	get_inv_transfo_cy(t_object *obj)
{
	t_cylinder	*cy;
	t_matrix	mat[4];
	t_matrix	tmp_m[4];
	float		a[2];
	float		ground_dist;

	cy = (t_cylinder *)obj->data;
	a[0] = atan2(-cy->orientation.p.x, cy->orientation.p.y);
	ground_dist = sqrt(cy->orientation.p.x * cy->orientation.p.x
			+ cy->orientation.p.y * cy->orientation.p.y);
	a[1] = atan2(cy->orientation.p.z, ground_dist);
	mat[0] = get_scaling_m
		(cy->diameter / 2.0, cy->height / 2.0, cy->diameter / 2.0);
	mat[2] = rotate_z(a[0]);
	mat[1] = rotate_x(a[1]);
	mat[3] = get_translation_m(cy->pos.p.x, cy->pos.p.y, cy->pos.p.z);
	multiply_matrices(&mat[2], &mat[0], &tmp_m[0]);
	multiply_matrices(&mat[1], &tmp_m[0], &tmp_m[1]);
	multiply_matrices(&mat[3], &tmp_m[1], &tmp_m[2]);
	if (!invert_matrix(&tmp_m[2], &tmp_m[3]))
		return (identity_matrix());
	return (tmp_m[3]);
}

t_matrix	get_inv_transfo_co(t_object *obj)
{
	t_cone		*co;
	t_matrix	mat[5];
	t_matrix	tmp_m[5];
	float		a[2];
	float		ground_dist;

	co = (t_cone *)obj->data;
	a[0] = atan2(-co->orientation.p.x, co->orientation.p.y);
	ground_dist = sqrt(co->orientation.p.x * co->orientation.p.x
			+ co->orientation.p.y * co->orientation.p.y);
	a[1] = atan2(co->orientation.p.z, ground_dist);
	mat[0] = get_scaling_m(co->diameter / 2.0, co->height, co->diameter / 2.0);
	mat[4] = get_translation_m(0, 0, 0);
	mat[2] = rotate_z(a[0]);
	mat[1] = rotate_x(a[1]);
	mat[3] = get_translation_m(co->pos.p.x, co->pos.p.y, co->pos.p.z);
	multiply_matrices(&mat[4], &mat[0], &tmp_m[0]);
	multiply_matrices(&mat[2], &tmp_m[0], &tmp_m[1]);
	multiply_matrices(&mat[1], &tmp_m[1], &tmp_m[2]);
	multiply_matrices(&mat[3], &tmp_m[2], &tmp_m[3]);
	if (!invert_matrix(&tmp_m[3], &tmp_m[4]))
		return (identity_matrix());
	return (tmp_m[4]);
}

t_matrix	get_inv_transfo_pattern(t_pattern *pattern)
{
	t_matrix	m_scale;
	t_matrix	m_inv;

	m_scale = get_scaling_m(pattern->scale, pattern->scale, pattern->scale);
	if (!invert_matrix(&m_scale, &m_inv))
	{
		return (identity_matrix());
	}
	return (m_inv);
}
