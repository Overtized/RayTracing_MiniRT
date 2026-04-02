/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrix_identity.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:10:26 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/12 16:49:47 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	multiply_matrix_identity(t_matrix *m, t_matrix *new)
{
	t_matrix	id;

	id = identity_matrix();
	if (!multiply_matrices(m, &id, new))
		return (write_err("can't multiply matrices"), false);
	return (true);
}
