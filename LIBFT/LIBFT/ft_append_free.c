/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:43:24 by lchiche           #+#    #+#             */
/*   Updated: 2026/02/23 14:49:43 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*append_free(char *base_str, const char *add_str)
{
	char	*result;

	if (!add_str)
	{
		add_str = ft_strdup("");
		if (!add_str)
			return (NULL);
	}
	if (!base_str)
	{
		result = ft_strdup(add_str);
		if (!result)
			return (NULL);
		return (result);
	}
	result = ft_strjoin(base_str, add_str);
	if (base_str)
		free(base_str);
	if (!result)
		return (NULL);
	return (result);
}
