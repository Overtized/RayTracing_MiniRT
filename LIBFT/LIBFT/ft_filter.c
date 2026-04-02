/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:34:12 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 00:02:59 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*filter(char *ret, char target)
{
	size_t	ret_len;
	int		i;
	int		j;
	char	*new_str;

	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	ret_len = ft_strlen(ret);
	new_str = malloc(sizeof(char) * ret_len + 1);
	if (!new_str)
		return (NULL);
	while (ret[i])
	{
		if (ret[i] != target)
		{
			new_str[j] = ret[i];
			j++;
		}
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}
