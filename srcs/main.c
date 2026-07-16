/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:33:46 by lchiche           #+#    #+#             */
/*   Updated: 2026/07/16 06:02:08 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "includes.h"

int	main(int ac, char **av)
{
	t_scene	*scene;

	if (verify_all(ac, av)) // parsing check
		return (1);
	write_message(1, "\nIT'S SHOWTIME !\n", P_MAGENTA);
	scene = fill_scene(av); // filling of the scene
	if (!scene)
		return (free_scene(scene), 1);
	create_tab_materia(scene); // create materia aand object visual/physical properties
	write_message(1, "\nLaunching RayTracer !\n", P_YELLOW);
	if (!mainwindow(scene)) // main loop
		return (write_err("mainwindow function fail\n"), free_scene(scene), 1);
	write_message(1, "\nClosing RayTracer... See You Soon !\n\n", P_YELLOW);
	free_scene(scene); // free logic
	return (0);
}
