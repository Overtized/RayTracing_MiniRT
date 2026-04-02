/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:10:48 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 16:07:21 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	safe_write(char *str, char *arg)
{
	if (str)
	{
		if (write(1, str, ft_strlen(str)) == -1)
			write(2, "error, stream corrupted\n", 25);
		if (arg)
		{
			if (write(1, arg, ft_strlen(arg)) == -1)
				write(2, "error, stream corrupted\n", 25);
		}
		if (errno != 0)
		{
			write(2, " \n", 3);
			strerror(errno);
		}
		if (write(1, "\n", 2) == -1)
			write(2, "error, stream corrupted\n", 25);
	}
	return ;
}
