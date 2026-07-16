/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:54:37 by lchiche           #+#    #+#             */
/*   Updated: 2026/07/16 05:48:05 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	fill_line(t_scene *scene, char *input, size_t	*obj_idx) // fill supported structures/objects with filedescriptor parsed informations
{
	char	**split_l;

	truncate_at(input, "\n");
	split_l = ft_split(input, ' ');
	if (!split_l)
		return (write_err("Error\n\tMalloc error"));
	if (!ft_strcmp("A", split_l[0]))
		return (fill_ambiant_light(scene, split_l));
	else if (!ft_strcmp("C", split_l[0]))
		return (fill_camera(scene, split_l));
	else if (!ft_strcmp("L", split_l[0]))
		return (fill_light(scene, split_l));
	else
	{
		(*obj_idx)++;
		if (!ft_strcmp("pl", split_l[0]))
			return (fill_plane(scene, split_l, *obj_idx)); // fill the object pattern
		if (!ft_strcmp("sp", split_l[0]))
			return (fill_sphere(scene, split_l, *obj_idx));
		if (!ft_strcmp("cy", split_l[0]))
			return (fill_cylinder(scene, split_l, *obj_idx));
		if (!ft_strcmp("co", split_l[0]))
			return (fill_cone(scene, split_l, *obj_idx));
	}
	return (free(split_l), true);
}

t_scene	*fill_scene(char **av)
{
	int				fd;
	char			*line_map;
	t_scene			*scene;
	static size_t	obj_idx;

	obj_idx = -1;
	fd = open(av[1], O_RDONLY);
	if (fd == -1) // redundant couldve stored an open fd to retrieve it faster
		return (write_err("Error\n\tMap empty or not readable !\n"), NULL);
	scene = ft_calloc(1, sizeof(t_scene)); // scene allocation
	if (!scene)
		return (close(fd), write_err("Error\n\tMalloc error"), NULL);
	line_map = get_next_line(fd);
	while (line_map) // go line over line
	{
		if (line_map[0] && line_map[0] != '\n')
		{
			if (fill_line(scene, line_map, &obj_idx))
				return (write_err("Error\n\t malloc error"), free_scene(scene),
					free(line_map), get_next_line(-42), close(fd), NULL);
		}
		free(line_map);
		line_map = get_next_line(fd);
	}
	return (get_next_line(-42), close(fd), scene); // safely free allocated useless mem and return the scene
}
