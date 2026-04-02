/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truncate_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiche <lchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 00:17:11 by lchiche           #+#    #+#             */
/*   Updated: 2026/03/03 00:17:11 by lchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	truncate_at(char *str, const char *end)
{
	size_t	len_str;
	size_t	len_end;

	if (!str || !end)
		return ;
	len_str = strlen(str);
	len_end = strlen(end);
	if (len_str >= len_end)
	{
		if (strcmp(str + len_str - len_end, end) == 0)
			str[len_str - len_end] = '\0';
	}
}
