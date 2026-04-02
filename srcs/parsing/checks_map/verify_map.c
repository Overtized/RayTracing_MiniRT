/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:34:23 by lchiche           #+#    #+#             */
/*   Updated: 2026/03/27 19:29:39 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	verify_line(char *line)
{
	int		nb_arg;
	char	**splited_l;

	truncate_at(line, "\n");
	splited_l = ft_split(line, ' ');
	if (!splited_l)
		return (write_err("Error\n\tMalloc error : "));
	nb_arg = count_strs(splited_l);
	if (!ft_strcmp("A", splited_l[0]))
		return (check_ambiant_light(splited_l, nb_arg));
	else if (!ft_strcmp("C", splited_l[0]))
		return (check_camera(splited_l, nb_arg));
	else if (!ft_strcmp("L", splited_l[0]))
		return (check_light(splited_l, nb_arg));
	else if (!ft_strcmp("pl", splited_l[0]))
		return (check_plane(splited_l, nb_arg));
	else if (!ft_strcmp("sp", splited_l[0]))
		return (check_sphere(splited_l, nb_arg));
	else if (!ft_strcmp("cy", splited_l[0]) || !ft_strcmp("co", splited_l[0]))
		return (check_cylinder_cone(splited_l, nb_arg));
	free(splited_l);
	return (write_err("Error\n\tUnknown object : "));
}

bool	verify_map(char *map_name)
{
	int		fd;
	char	*line_map;
	bool	is_empty;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (write_err("Error\n\tMap doesn't exist or not readable !\n"));
	is_empty = true;
	line_map = get_next_line(fd);
	while (line_map)
	{
		if (line_map[0] && line_map[0] != '\n')
		{
			is_empty = false;
			if (verify_line(line_map))
				return (write_message(2, line_map, P_DIM), write_err("\n"),
					free(line_map), get_next_line(-42), close(fd), true);
		}
		free(line_map);
		line_map = get_next_line(fd);
	}
	if (is_empty)
		return (get_next_line(-42), close(fd),
			write_err("Error\n\tMap is empty!\n"));
	return (get_next_line(-42), close(fd), false);
}
