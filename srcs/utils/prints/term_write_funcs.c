/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_write_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:54:56 by lchiche           #+#    #+#             */
/*   Updated: 2026/03/28 00:30:52 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	write_message(int fd, char *message, char *color)
{
	if (color)
	{
		if ((write(fd, color, ft_strlen(color))) == -1)
			write_err(" stdandard out stream is corrupted\n");
		if ((write(fd, message, ft_strlen(message))) == -1)
			write_err(" stdandard out stream is corrupted\n");
		if ((write(fd, P_RESET, ft_strlen(P_RESET))) == -1)
			write_err(" stdandard out stream is corrupted\n");
	}
	else
		if (write(fd, message, ft_strlen(message)) == -1)
			write_err(" stdandard out stream is corrupted\n");
}

bool	write_err(char *err)
{
	write_message(2, err, P_RED);
	return (true);
}
