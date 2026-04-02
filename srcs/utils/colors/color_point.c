/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:28:03 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/27 23:59:01 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_light	get_perso_light(t_light *light, t_color *surface_c)
{
	t_light	res;

	res.pos = light->pos;
	res.color.r = light->color.r * surface_c->r;
	res.color.g = light->color.g * surface_c->g;
	res.color.b = light->color.b * surface_c->b;
	res.color = multiply_color(res.color, light->light_ratio);
	return (res);
}

t_color	comp_amb(t_scene *scene, t_color *surface_c, t_mat *materia)
{
	float	factor;
	t_color	ambient;

	factor = scene->ambient_light->light_ratio * materia->amb_ratio;
	ambient.r = surface_c->r * scene->ambient_light->color.r;
	ambient.g = surface_c->g * scene->ambient_light->color.g;
	ambient.b = surface_c->b * scene->ambient_light->color.b;
	ambient = multiply_color(ambient, factor);
	return (ambient);
}

static t_color	compute_specular(double *reflect_dot_eye, t_mat *materia,
	t_color *light_color)
{
	double	factor;
	double	reflect_dot;
	t_color	specular;

	reflect_dot = *reflect_dot_eye;
	if (reflect_dot > 1)
		reflect_dot = 1;
	if (reflect_dot < 0)
		reflect_dot = 0;
	factor = custom_pow(reflect_dot, materia->shiny);
	specular = multiply_color(multiply_color(*light_color, materia->spe_ratio),
			factor);
	return (specular);
}

t_color	comp_diff(t_color *effective_color, t_mat *materia,
	t_l_on_obj *properties, t_color *specular)
{
	double	light_dot_n;
	double	reflect_dot_eye;
	t_color	diffuse;
	t_point	reflectv;

	diffuse = make_color(0, 0, 0);
	light_dot_n = tupple_dot_product(properties->l_p, properties->n_p);
	if (light_dot_n < 0)
		return (make_color(0, 0, 0));
	diffuse = multiply_color(multiply_color(*effective_color,
				materia->dif_ratio), light_dot_n);
	reflectv = reflect(negate_tupple(properties->l_p), properties->n_p);
	reflect_dot_eye = tupple_dot_product(reflectv, properties->e_p);
	if (reflect_dot_eye <= 0)
		*specular = make_color(0, 0, 0);
	else
		*specular = compute_specular(&reflect_dot_eye, materia,
				effective_color);
	return (diffuse);
}

t_color	color_point(t_light *light, t_comps *comps, t_color *surface_color)
{
	t_color		final;
	t_color		specular;
	t_color		effective_color;
	t_l_on_obj	pixel_light_attributes;

	specular = make_color(0, 0, 0);
	pixel_light_attributes = fill_l_on_obj(light, comps);
	effective_color = get_perso_light(light, surface_color).color;
	final = comp_diff(&effective_color, &comps->obj->materia,
			&pixel_light_attributes, &specular);
	final = sum_two_colors(final, specular);
	return (final);
}
