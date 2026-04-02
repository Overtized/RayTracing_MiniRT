/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:59:09 by lchiche           #+#    #+#             */
/*   Updated: 2026/04/01 16:14:42 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "includes.h"

// # ----------------------------------------------- #
// # 					UTILS						 #
// # ----------------------------------------------- #

//object_utils
t_cont_n	*add_container_node(t_cont_n **lst, t_object *obj);
t_object	*new_object(t_objtype type, void *data, size_t obj_idx);
void		add_object(t_object **list, t_object *new);
void		add_light(t_light **list, t_light *new);
void		free_all_objects(t_object *obj);
void		del_obj_from_cont(t_cont_n **lst, t_object *target);
void		free_all_containers(t_cont_n **lst);
t_object	*get_cont_o(t_cont_n *container, t_object *target);
size_t		obj_lst_size(t_object *obj_lst);
t_object	*return_object_data(t_object *obj_list, t_objtype type);
t_sphere	*create_sphere(void);
t_plane		*create_plane(void);
t_object	*object_scaling(t_object *obj, float x, float y, float z);
t_object	*object_translate(t_object *obj, float x, float y, float z);
t_object	*set_default_transform(t_object *obj);

// objects

int			count_strs(char **strs);
void		truncate_at(char *str, const char *end);
bool		try_int_number(char *nb);
bool		try_float_number(char *nb);

// points
t_point		make_vector(float x, float y, float z, int color);
t_point		make_point(float x, float y, float z, int color);
t_point		copy_point(t_point point_a);
t_point		copy_vector(t_point point_a);
t_vec3		make_vec3(float x, float y, float z);
t_vec3		make_vec_error(void);
t_point		make_point_error(void);
t_vec3		point_to_vec3(t_point p);
t_point		vec3_to_point(t_vec3 vec3, int color);
double		vec3_dot_product(t_vec3 a, t_vec3 b);

t_point		sum_two_points(t_point a, t_point b);
bool		compare_points(t_point p1, t_point p2);
t_point		sub_two_points(t_point a, t_point b);
t_point		negate_tupple(t_point a);
t_vec3		negate_vec3(t_vec3 a);
t_point		scale_tupple(t_point a, double scalar);
t_point		divide_tupple(t_point a, double divider);
double		get_tupple_magnitude(t_point a);
t_point		normalize_vector(t_point a);
t_vec3		normalize_vec3(t_vec3 a);
double		tupple_dot_product(t_point a, t_point b);
t_point		cross_product(t_point a, t_point b);
t_vec3		vec3_cross_product(t_vec3 a, t_vec3 b);

// colors
t_color		make_color(double R_c, double G_c, double B_c);
t_color		sum_two_colors(t_color a, t_color b);
t_color		sum_three_colors(t_color a, t_color b, t_color c);
t_color		sub_two_colors(t_color a, t_color b);
t_color		multiply_color(t_color a, float scalar);
t_color		hadamard_product(t_color a, t_color b);

// matrices
t_matrix	create_matrix(void);
t_matrix	identity_matrix(void);
t_matrix	cpy_matrix(t_matrix *src_m);
t_matrix	create_sub_m(t_matrix *m, size_t del_r, size_t del_c, bool *error);
bool		compare_matrices(t_matrix *m1, t_matrix *m2);
void		cp_sub_m(t_matrix *old, t_matrix *new, size_t del_r, size_t del_c);
bool		multiply_matrices(t_matrix *m1, t_matrix *m2, t_matrix *res);

inline t_point	multiply_m_by_m(t_matrix *m, t_point t)
{
	t_point	res;

	res.p.x = m->m[0][0] * t.p.x + m->m[0][1] * t.p.y + m->m[0][2]
		* t.p.z + m->m[0][3] * t.p.w;
	res.p.y = m->m[1][0] * t.p.x + m->m[1][1] * t.p.y + m->m[1][2]
		* t.p.z + m->m[1][3] * t.p.w;
	res.p.z = m->m[2][0] * t.p.x + m->m[2][1] * t.p.y + m->m[2][2]
		* t.p.z + m->m[2][3] * t.p.w;
	res.p.w = m->m[3][0] * t.p.x + m->m[3][1] * t.p.y + m->m[3][2]
		* t.p.z + m->m[3][3] * t.p.w;
	res.color = t.color;
	res.error = false;
	return (res);
}

bool		multiply_matrix_identity(t_matrix *m, t_matrix *new);
t_point		multiply_tuple_identity(t_point tuple);
void		transpose_matrix(t_matrix *m);
bool		invert_matrix(t_matrix *m, t_matrix *new);
//invert_matrix_u
float		compute_2x2_determinant(t_matrix *m);
float		compute_determinant(t_matrix *m, bool *error);
float		compute_minor(t_matrix *m, size_t row, size_t col, bool *error);
float		compute_cofactor(t_matrix *m, size_t row, size_t col, bool *error);
// matrix transformation
t_point		transl_transf(double x, double y, double z, t_point input_tup);
t_point		transl_inv_transf(double x, double y, double z, t_point input_tup);
t_point		scale_m_transf(double x, double y, double z, t_point input_tup);
t_point		scale_inv_m_transf(double x, double y, double z, t_point input_tup);
t_point		reflect_m_transf(double x, double y, double z, t_point input_tup);
t_point		rotate_x_m_transf(float radians, t_point input_tup);
t_point		rotate_x_inv_m_transf(float radians, t_point input_tup);
t_point		rotate_y_m_transf(float radians, t_point input_tup);
t_point		rotate_y_inv_m_transf(float radians, t_point input_tup);
t_point		rotate_z_m_transf(float radians, t_point input_tup);
t_point		rotate_z_inv_m_transf(float radians, t_point input_tup);
t_point		shear_matrix_transf(double shear_tab[6], t_point input_tup);
t_point		shear_inv_matrix_transf(double shear_tab[6], t_point input_tup);
//transfo_u
t_matrix	scale(double x, double y, double z);
t_matrix	rotate_x(float radians);
t_matrix	rotate_y(float radians);
t_matrix	rotate_z(float radians);
t_matrix	shear(double shear_tab[6]);
t_matrix	translation(double x, double y, double z);

// raycasting
t_ray		create_ray(t_point origin, t_point direction);
t_ray		create_error_ray(void);
t_point		get_ray_position(t_ray ray, float time);
t_ray		clone_ray(t_ray *ray);

// ray intersection
t_it		*intersect(t_object *obj, t_ray *ray, bool *error);
void		add_intersection(t_it **list, t_it *new);
void		free_all_intersections(t_it *obj);
size_t		intersections_lst_size(t_it *obj_lst);
t_it		*get_lowest_hit(t_it *list_head);
void		transform_ray(t_matrix *m, t_ray *input_r, t_ray *local_r);
double		compare_range(t_it *inter);
t_it		*last_inter(t_it *list);
void		sort_internal_t(t_it *it);
void		sort_inter_list(t_it **list);

// pattern
t_pattern	new_patt(t_color ca, t_color cb, float scale, t_pat_type type);
t_pattern	create_checkerboard_pattern(float scale, t_pat_type type);
t_color		get_pattern_at_x(t_pattern *pattern, t_point *pos);
t_color		get_pattern_at_y(t_pattern *pattern, t_point *pos);
t_color		get_pattern_at_z(t_pattern *pattern, t_point *pos);
t_color		get_pattern_at_xyz(t_pattern *pattern, t_point *pos);
t_color		blend_color(float *fraction, t_color *ca, t_color *cb);

// # ----------------------------------------------- #
// # 					PRINTS						 #
// # ----------------------------------------------- #
void		print_intersect(t_it *intersect);
void		print_intersects(t_it *intersect);
void		print_p_attributes(t_point point, char *var_name);
void		print_scene(t_scene *scene);
void		print_color(t_color color);
void		print_matrix(t_matrix *m);
void		print_object(t_object *obj);
void		print_vec3(t_point v, char *name);
void		write_message(int fd, char *message, char *color);
bool		write_err(char *err);

// # ----------------------------------------------- #
// # 				GRAPHICAL WINDOW				 #
// # ----------------------------------------------- #

void		init_key_hook(t_vars *vars);
void		init_fct(t_vars *vars);
bool		create_image(t_data *img, t_vars *vars, t_scene *scene);
int			close_window(void *param);
bool		mainwindow(t_scene *scene);
void		put_one_pixel(t_data *data, int x, int y, int color);

// # ----------------------------------------------- #
// # 					PARSING						 #
// # ----------------------------------------------- #

//checks_map
bool		verify_all(int nb_arg, char **args);
bool		verify_map(char *map_name);
bool		check_ambiant_light(char **args, int nb_arg);
bool		check_camera(char **args, int nb_arg);
bool		check_light(char **args, int nb_arg);
bool		check_plane(char **args, int nb_arg);
bool		check_sphere(char **args, int nb_arg);
bool		check_cylinder_cone(char **args, int nb_arg);
bool		check_rgb(char *arg);
bool		check_pos(char *arg);
bool		check_orientation(char *arg);
bool		check_view_range(char *arg);
bool		check_light_ratio(char *arg);
bool		check_unfloat(char *arg);

// free
void		free_scene(t_scene *scene);
void		free_all_lights(t_light **lights);

//fill_struct
t_scene		*fill_scene(char **av);
bool		fill_ambiant_light(t_scene *scene, char **input);
bool		fill_camera(t_scene *scene, char **input);
bool		fill_light(t_scene *scene, char **input);
bool		fill_plane(t_scene *scene, char **input, size_t obj_idx);
bool		fill_sphere(t_scene *scene, char **input, size_t obj_idx);
bool		fill_cylinder(t_scene *scene, char **input, size_t obj_idx);
bool		fill_cone(t_scene *scene, char **input, size_t obj_idx);
bool		fill_light_ratio(float *light_ratio, char *input);
bool		fill_rgb(t_color *color, char *input);
bool		fill_vec3(t_vec3 *vec3, char *input);
bool		fill_view_range(float *deg_range, char *input);
bool		fill_unfloat(double *unfloat, char *input);

//refract/reflect
t_point		reflect(t_point in, t_point normal);
t_color		get_color_at(t_scene *scene, t_ray	*ray, int call_limit);
t_color		refract_c(t_scene *wrld, t_comps *comp, int call_l, t_color *color);
double		schlick_fresnel(t_comps	*comps);
t_color		reflected_color(t_scene *scene, t_comps *comps, int call_limit);

//intersects
bool		sp_inter(double *det, t_ray *ray, t_object *obj, t_it **it_list);
bool		pl_inter(t_ray *ray, t_object *obj, t_it **it_list);
bool		cy_inter(double *det, t_ray *ray, t_object *obj, t_it **it_list);
bool		co_inter(double *det, t_ray *ray, t_object *obj, t_it **it_list);

//get_inv_transfo
t_matrix	get_inv_transfo_sp(t_object *obj);
t_matrix	get_inv_transfo_pl(t_object *obj);
t_matrix	get_inv_transfo_cy(t_object *obj);
t_matrix	get_inv_transfo_co(t_object *obj);
t_matrix	get_inv_transfo_pattern(t_pattern *pattern);
t_color		get_patt_obj(t_pattern *pattern, t_point *world_p, t_object *obj);
t_matrix	get_translation_m(double x, double y, double z);
t_matrix	get_scaling_m(double x, double y, double z);

//shade
t_color		shade_hit(t_scene *scene, t_comps *comps, int call_limit);
t_color		color_point(t_light *light, t_comps *comps, t_color *surface_c);
t_l_on_obj	fill_l_on_obj(t_light *light, t_comps *comps);
t_color		comp_diff(t_color *effc, t_mat *mat, t_l_on_obj *att, t_color *spe);
t_color		comp_amb(t_scene *scene, t_color *surface_c, t_mat *materia);

//cam compute
void		compute_basics_cam(t_camera *camera);
t_matrix	view_transform(t_point from, t_point to, t_vec3 up);
void		compute_pixel_size(t_camera *camera);
// prepare_computation
bool		prep_comp(t_ray *ray, t_it *l_hit, t_comps *comps, t_it *it_list);
t_point		normal_at(t_object *obj, t_point point);
//materials
void		create_tab_materia(t_scene *scene);
t_mat		create_default_mat(void);
t_mat		create_glass_materia(void);
t_mat		create_opaque_materia(void);
void		choose_materia(t_object *obj_list, t_mat *materials);

//determine_n
bool		determine_n(t_it *list, t_it *l_hit, t_comps *comps);
double		get_last_n(t_cont_n *container);
bool		create_new_lst(t_it **new_lst, t_it *old_lst, t_comps *comps);
void		manage_cont_lst(t_cont_n **cont, t_it *cursor);

//main funcs
bool		color_at(t_scene *scene, t_ray *ray, t_color *color);
void		reset_color(t_color *color);
// miscs_u
double		custom_pow(double base, float exposant);
t_camera	*camera_translate(t_camera *cam, float x, float y, float z);
t_camera	*reset_camera_position(t_camera *cam);
t_camera	*camera_rotate_y(t_camera *cam, float angle);
t_camera	*camera_rotate_x(t_camera *cam, float angle);
t_camera	*camera_rotate_z(t_camera *cam, float angle);
int			angle_right(void *param);
int			angle_left(void *param);
int			angle_up(void *param);
int			angle_down(void *param);
int			move_right(void *param);
int			move_left(void *param);
int			move_up(void *param);
int			move_down(void *param);
int			angle_minus_z(void *param);
int			angle_plus_z(void *param);
int			step_in(void *param);
int			step_out(void *param);
int			reset_cam(void *param);
int			toggle_stripes(void *param);

#endif
