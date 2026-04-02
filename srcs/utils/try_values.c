/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiche <lchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 23:34:44 by lchiche           #+#    #+#             */
/*   Updated: 2026/03/02 23:34:44 by lchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	try_int_number(char *nb)
{
	int		i;
	bool	is_number;

	i = 0;
	is_number = false;
	if (!nb)
		return (false);
	while (nb[i])
	{
		if ((is_number && nb[i] == '-') || (!ft_isdigit(nb[i]) && nb[i] != '-'))
			return (true);
		if (ft_isdigit(nb[i]))
			is_number = true;
		i++;
	}
	return (false);
}

bool	try_float_number(char *nb)
{
	int		i;
	bool	is_number;
	bool	is_point;

	i = 0;
	is_number = false;
	is_point = false;
	if (!nb)
		return (false);
	while (nb[i])
	{
		if ((is_number && nb[i] == '-') || (!ft_isdigit(nb[i]) && nb[i] != '-'
				&& nb[i] != '.') || (!is_number && nb[i] == '.')
			|| (is_point && nb[i] == '.'))
			return (true);
		if (ft_isdigit(nb[i]))
			is_number = true;
		if (nb[i] == '.')
			is_point = true;
		i++;
	}
	return (false);
}
