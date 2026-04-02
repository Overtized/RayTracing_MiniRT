/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_materials.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:23:13 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 12:45:35 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_mat	create_default_mat(void)
{
	t_mat	new;

	new.intensity = make_color(1, 1, 1);
	new.amb_ratio = 0.2;
	new.dif_ratio = 0.8;
	new.spe_ratio = 0.3;
	new.reflective = 0.5;
	new.transparency = 0.0;
	new.refractive_index = AIR;
	new.shiny = 20.0;
	return (new);
}

t_mat	create_glass_materia(void)
{
	t_mat	new;

	new.intensity = make_color(1, 1, 1);
	new.amb_ratio = 0.0;
	new.dif_ratio = 0.005;
	new.spe_ratio = 0.9;
	new.reflective = 0.4;
	new.transparency = 0.9;
	new.refractive_index = GLASS;
	new.shiny = 200.0;
	return (new);
}

t_mat	create_opaque_materia(void)
{
	t_mat	new;

	new.intensity = make_color(1, 1, 1);
	new.amb_ratio = 0.4;
	new.dif_ratio = 0.8;
	new.spe_ratio = 1.0;
	new.reflective = 0.0;
	new.transparency = 0.0;
	new.refractive_index = DIAMOND;
	new.shiny = 20.0;
	return (new);
}

void	create_tab_materia(t_scene *scene)
{
	scene->materials[0] = create_default_mat();
	scene->materials[1] = create_glass_materia();
	scene->materials[2] = create_opaque_materia();
	choose_materia(scene->objects, scene->materials);
}
