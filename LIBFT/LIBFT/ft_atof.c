/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:23:39 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 00:01:24 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	handle_sign(char **nptr, int *sign)
{
	if (**nptr == '+' || **nptr == '-')
	{
		if (**nptr == '-')
			*sign *= -1;
		(*nptr)++;
	}
}

float	ft_atof(char *nptr)
{
	float	result;
	float	divisor;
	int		sign;

	result = 0;
	sign = 1;
	divisor = 10.0;
	if (!nptr)
		return (-1);
	while (ft_isspace(*nptr))
		nptr++;
	handle_sign(&nptr, &sign);
	while (ft_isdigit(*nptr))
		result = (result * 10) + (*nptr++ - '0');
	if (*nptr == '.')
	{
		nptr++;
		while (ft_isdigit(*nptr))
		{
			result += (*nptr++ - '0') / divisor;
			divisor *= 10.0;
		}
	}
	return (result * sign);
}
