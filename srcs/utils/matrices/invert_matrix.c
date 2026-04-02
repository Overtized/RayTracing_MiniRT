/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:23:07 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/26 17:32:37 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	make_cofactor_matrix(t_matrix *m, t_matrix *new, bool *error)
{
	size_t	r;
	size_t	c;

	r = 0;
	while (r < m->rows)
	{
		c = 0;
		while (c < m->cols)
		{
			new->m[r][c] = compute_cofactor(m, r, c, error);
			if (*error)
				return (false);
			c++;
		}
		r++;
	}
	return (true);
}

static void	invert(t_matrix *m, t_matrix *new,
	float og_determinant, bool *error)
{
	size_t	r;
	size_t	c;

	if (!make_cofactor_matrix(m, new, error) || *error)
	{
		write_err ("error making cofactor matrix");
		return ;
	}
	transpose_matrix(new);
	r = 0;
	while (r < m->rows)
	{
		c = 0;
		while (c < m->cols)
		{
			new->m[r][c] /= og_determinant;
			c++;
		}
		r++;
	}
}

bool	invert_matrix(t_matrix *m, t_matrix *new)
{
	float		det;
	bool		error;

	error = false;
	*new = create_matrix();
	det = compute_determinant(m, &error);
	if (!det || error)
		return (write_err("matrix is not invertible\n"), false);
	invert(m, new, det, &error);
	if (error)
		return (write_err("invert matrix failed"), false);
	return (true);
}
