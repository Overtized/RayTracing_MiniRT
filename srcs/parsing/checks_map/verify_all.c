/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiche <lchiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:55:44 by lchiche           #+#    #+#             */
/*   Updated: 2026/03/03 01:07:15 by lchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	check_map_rt(char *map_name)
{
	size_t	length;

	length = ft_strlen(map_name);
	if (length < 4)
		return (true);
	if (ft_strncmp(&map_name[length - 3], ".rt", 3)
		|| !ft_strncmp(&map_name[length - 4], "/.rt", 4))
		return (true);
	return (false);
}

static void	tests_intro(char *map_name)
{
	write_message(1, P_CLEAR_SCREEN"\nTests on map is going...\n\n", P_BOLD);
	write_message(1, "Map's name : ", P_BOLD);
	write_message(1, map_name, P_DIM);
	write_message(1, "\n-> ", P_BOLD);
}

bool	verify_all(int nb_arg, char **args)
{
	if (nb_arg != 2)
		return (write_err("\n[program_name] [path_to_map.rt]\n"));
	tests_intro(args[1]);
	if (check_map_rt(args[1]))
		return (write_err("Error\n\tInvalid map name !\n"));
	if (verify_map(args[1]))
		return (1);
	write_message(1, "Success\n\tMap is valid !\n", P_GREEN);
	return (false);
}
