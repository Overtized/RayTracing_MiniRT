/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 00:26:35 by lchiche           #+#    #+#             */
/*   Updated: 2026/03/31 14:35:38 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_objtype
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER,
	OBJ_CONE
}	t_objtype;

typedef enum t_pat_type
{
	STRIPES,
	GRADIENT,
	RING
}	t_pat_type;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			ll;
	int			endian;
	double		scale;
}	t_data;

typedef struct s_vars	t_vars;

typedef void			(*t_fct)(t_vars *vars);

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
	int		hex;
}	t_color;

typedef struct s_matrix
{
	double	m[4][4];
	size_t	rows;
	size_t	cols;
}	t_matrix;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
	double	w;
	bool	error;
}	t_vec3;

typedef struct s_point
{
	t_vec3			p;
	t_color			color;
	bool			error;
}	t_point;

typedef struct s_ray
{
	t_point	og;
	t_point	dir;
	t_point	curr;
	bool	error;
}	t_ray;

typedef struct s_mat
{
	t_color	intensity;
	float	amb_ratio;
	float	dif_ratio;
	float	spe_ratio;
	float	shiny;
	float	reflective;
	float	refractive_index;
	float	transparency;
}	t_mat;

typedef struct s_pattern
{
	t_matrix	trans_inv_m;
	t_color		color_a;
	t_color		color_b;
	float		scale;
	t_pat_type	type;
}	t_pattern;

typedef struct s_on_obj
{
	double	t;
	t_point	p_p;
	t_point	l_p;
	t_point	n_p;
	t_point	e_p;
	t_point	r_p;
}	t_l_on_obj;

typedef struct s_ambient_light
{
	float	light_ratio;
	t_color	color;
}	t_ambient_light;

typedef struct s_camera
{
	t_point		pos;
	t_point		orientation;
	t_point		og_pos;
	t_point		og_orient;
	float		deg_range;
	double		half_width;
	double		half_height;
	double		pixel_size;
	t_matrix	tranform;
	t_matrix	inv_tranform;
}	t_camera;

typedef struct s_light
{
	t_color			color;
	t_point			pos;
	struct s_light	*next;
	float			light_ratio;
}	t_light;

typedef struct s_sphere
{
	t_point	pos;
	double	diameter;
	t_color	color;
}	t_sphere;

typedef struct s_plane
{
	t_point		pos;
	t_point		orientation;
	t_color		color;
	t_matrix	transform;
	t_point		normal;
}	t_plane;

typedef struct s_cylinder
{
	t_point	pos;
	t_point	orientation;
	double	diameter;
	double	height;
	t_color	color;
	bool	closed;
	double	h;
}	t_cylinder;

typedef struct s_cone
{
	t_point	pos;
	t_point	orientation;
	double	diameter;
	double	height;
	t_color	color;
	bool	closed;
	double	h;
}	t_cone;

typedef struct s_object
{
	t_objtype		type;
	t_mat			materia;
	t_pattern		pattern;
	bool			has_pattern;
	t_color			color;
	size_t			obj_index;
	void			*data;
	t_matrix		inv_m;
	t_matrix		trans_inv_m;
	struct s_object	*next;
}	t_object;

typedef struct s_cont_n
{
	t_object		*obj;
	struct s_cont_n	*next;
}	t_cont_n;

typedef struct s_comps
{
	t_object		*obj;
	t_objtype		obj_type;
	double			lowest_t;
	t_point			hit_p;
	t_vec3			eye_vec;
	t_vec3			normal_vec;
	t_vec3			reflect_v;
	t_point			over_p;
	t_point			under_p;
	t_point			ray_dir;
	bool			inside_obj;
	double			n[2];
}	t_comps;

typedef struct s_inter_comp
{
	double	v[3];
	double	t[2];
	double	y[2];
}	t_inter_comp;

typedef struct s_it
{
	size_t			count;
	double			t[4];
	t_object		*obj;
	struct s_it		*next;
}	t_it;

typedef struct s_scene
{
	t_light			*light;
	t_camera		*camera;
	t_object		*objects;
	t_ambient_light	*ambient_light;
	t_mat			materials[3];
}	t_scene;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	bool			need_redraw;
	t_fct			tab_fct[0xFFFF];
	t_data			img;
	t_scene			*scene;
	bool			error;
}	t_vars;

#endif
