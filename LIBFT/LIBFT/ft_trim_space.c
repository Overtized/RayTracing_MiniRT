/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 09:43:40 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 16:06:35 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_trim_spaces(int (*function)(int c), char *s1)
{
	char	*s1trimmed;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	if (!s1)
	{
		safe_write("must take an input string", NULL);
		return (NULL);
	}
	while (function(s1[start]) == true)
		start++;
	while (end > start && function(s1[end]) == true)
		end--;
	s1trimmed = malloc((sizeof(char) * (end - start) + 1));
	if (!s1trimmed)
		return (safe_write("Error\nMalloc failed", NULL), NULL);
	while (start < end)
		s1trimmed[i++] = s1[start++];
	s1trimmed[i] = '\0';
	return (s1trimmed);
}
