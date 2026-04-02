/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:07:09 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 00:03:21 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_double_char(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (write(1, str[i], ft_strlen(str[i])) == -1)
			write(2, "error, stream corrupted\n", 25);
		if (write(1, "\n", 2) == -1)
			write(2, "error, stream corrupted\n", 25);
		i++;
	}
	return ;
}
