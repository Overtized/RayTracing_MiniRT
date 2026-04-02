/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_tuple_identity.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:10:17 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 00:39:51 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_point	multiply_tuple_identity(t_point tuple)
{
	t_point		new;
	t_matrix	id;

	id = identity_matrix();
	new = multiply_m_by_m(&id, tuple);
	return (new);
}
