/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:25:32 by lchiche           #+#    #+#             */
/*   Updated: 2026/03/28 14:28:53 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_color(t_color color)
{
	printf("Hex Color value :  0x%X \033", color.hex);
	printf("\033[48;2;%d;%d;%dm \033[0m\n", (int)(color.r * 255.99),
		(int)(color.g * 255.99), (int)(color.b * 255.99));
}

static void	print_cyl_co(t_object *obj)
{
	t_cylinder	*cy;
	t_cone		*co;

	if (obj->type == OBJ_CYLINDER)
	{
		cy = (t_cylinder *)obj->data;
		write_message(1, "CYLINDER\n", P_GREEN);
		print_vec3(cy->pos, "Position");
		print_vec3(cy->orientation, "Orientation");
		printf("Diameter : %.2f\tHeight : %.2f\n", cy->diameter, cy->height);
	}
	else if (obj->type == OBJ_CONE)
	{
		co = (t_cone *)obj->data;
		write_message(1, "CONE\n", P_GREEN);
		print_vec3(co->pos, "Position");
		print_vec3(co->orientation, "Orientation");
		printf("Diameter : %.2f\tHeight : %.2f\n", co->diameter, co->height);
	}
	print_color(obj->color);
}

void	print_object(t_object *obj)
{
	t_plane		*pl;
	t_sphere	*sp;

	write_message(1, "\nOBJECT : ", P_BLUE);
	if (obj->type == OBJ_PLANE)
	{
		pl = (t_plane *)obj->data;
		write_message(1, "PLANE\n", P_GREEN);
		print_vec3(pl->pos, "Position");
		print_vec3(pl->orientation, "Orientation");
	}
	else if (obj->type == OBJ_SPHERE)
	{
		sp = (t_sphere *)obj->data;
		write_message(1, "SPHERE\n", P_GREEN);
		print_vec3(sp->pos, "Position");
		printf("Diameter : %.2f\n", sp->diameter);
	}
	else if (obj->type == OBJ_CYLINDER || obj->type == OBJ_CONE)
		print_cyl_co(obj);
}

static void	print_maj(t_scene *scene)
{
	if (scene->camera)
	{
		write_message(1, "CAMERA\n", P_GREEN);
		print_vec3(scene->camera->pos, "Position");
		print_vec3(scene->camera->orientation, "Orientation");
		printf("View angle : %f°\n", scene->camera->deg_range);
	}
	if (scene->ambient_light)
	{
		write_message(1, "AMBIENT LIGHT\n", P_GREEN);
		printf("Light ratio %.1f\n", scene->ambient_light->light_ratio);
		print_color(scene->ambient_light->color);
	}
	if (scene->light)
	{
		write_message(1, "LIGHT\n", P_GREEN);
		print_vec3(scene->light->pos, "Position");
		printf("Light ratio %.1f\n", scene->light->light_ratio);
		print_color(scene->light->color);
	}
}

void	print_scene(t_scene *scene)
{
	t_object	*cursor;
	char		**type_tab;

	type_tab = ft_calloc(4, sizeof(char *));
	if (!type_tab)
		return ;
	type_tab[0] = "sphere";
	type_tab[1] = "plane";
	type_tab[2] = "cylinder";
	type_tab[3] = "cone";
	write_message(1, "\n===== SCENE =====\n\n", P_YELLOW);
	write_message(1, "\nOBJECT : ", P_BLUE);
	print_maj(scene);
	cursor = scene->objects;
	while (cursor)
	{
		print_object(cursor);
		printf(P_YELLOW"%s  idx : %zu\n" P_RESET, type_tab[cursor->type],
			cursor->obj_index);
		cursor = cursor->next;
	}
	printf("\n\ntotal object count = %zu\n", obj_lst_size(scene->objects));
	free(type_tab);
}
