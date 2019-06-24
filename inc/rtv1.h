/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:34:59 by acostaz           #+#    #+#             */
/*   Updated: 2019/06/21 15:50:56 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/inc/libft.h"
# include "../mlx/inc/mlx.h"
# include "key_mapping.h"
# include <math.h>
# include <stdlib.h>
# include <pthread.h>

# define WIN_W 1200
# define WIN_H 800

# define NB_THREADS 8

# define KEYPRESS 2
# define KEYRELEASE 3

# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)

# define REDCROSS 17
# define REDCROSSMASK (1L<<17)

# define EPS 0.00000001
# define MAX 1000

typedef struct			s_pixel
{
	int					i;
	int					j;
}						t_pixel;

typedef struct			s_point
{
	double				x;
	double				y;
	double				z;
}						t_point;

typedef struct			s_vect
{
	double				x;
	double				y;
	double				z;
}						t_vect;

typedef struct			s_tuple
{
	double				a;
	double				b;
}						t_tuple;

typedef union			u_color
{
	unsigned int		number;
	unsigned char		channel[4];
}						t_color;

typedef struct			s_img
{
	void				*img_addr;
	char				*image;
	int					bpp;
	int					size_line;
	int					endian;
}						t_img;

typedef struct			s_material
{
	t_vect				ambient;
	t_vect				diffuse;
	t_vect				specular;
	double				shine;
}						t_material;

typedef struct			s_obj_list
{
	int					type;
	t_material			mat;
	void				*object;
	size_t				object_size;
	struct s_obj_list	*next;
}						t_obj_list;

typedef struct			s_light_list
{
	t_point				origin;
	t_color				color;
	double				amb;
	double				diff;
	double				spec;
	struct s_light_list	*next;
}						t_light_list;

typedef struct			s_surface
{
	t_obj_list			*obj;
	double				t;
	t_vect				normal;
	t_point				intersection;
	t_material			mat;
	double				shadow;
	t_color				color;
}						t_surface;

typedef struct			s_ray
{
	t_point				point;
	t_vect				vector;
}						t_ray;

typedef struct			s_sphere
{
	t_point				origin;
	double				radius;
}						t_sphere;

typedef struct			s_plane
{
	t_point				origin;
	t_vect				normal;
}						t_plane;

typedef struct			s_cylinder
{
	t_point				origin;
	t_vect				direction;
	double				radius;
}						t_cylinder;

typedef struct			s_cone
{
	t_point				origin;
	t_vect				direction;
	double				angle;
}						t_cone;

typedef struct			s_base
{
	t_point				origin;
	t_vect				u;
	t_vect				v;
	t_vect				n;
}						t_base;

typedef struct			s_screen
{
	double				d;
	double				heigth;
	double				width;
	t_point				center;
	t_point				point1;
}						t_screen;

typedef t_surface		(*t_passerelle)(t_obj_list *lst_ptr, t_ray ray);
typedef void			(*t_pass_normal)(t_surface *surface);
typedef void			(*t_f_material)(t_obj_list *obj);

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	t_img				img;
	t_obj_list			*obj_list;
	int					fd;
	t_point				cam;
	t_point				focus;
	t_base				base_cam;
	t_screen			screen;
	pthread_t			threads[NB_THREADS];
	t_light_list		*light_list;
	int					light_num;
	t_passerelle		pass_inter[4];
	t_pass_normal		pass_normal[4];
	t_f_material		choose_material[24];
	char				*name_material[24];
}						t_env;

/*
************************************list.c**************************************
*/

void					list_append(t_env *e, char *type);
void					list_light_append(t_env *e);
void					list_del(t_env *e, int err);
void					close_program(t_env *e, int err);

/*
*********************************math_vector.c**********************************
*/

t_vect					make_vector (t_point a, t_point b);
double					dot_product(t_vect u, t_vect v);
t_vect					vect_product(t_vect u, t_vect v);
t_vect					norm_vector(t_vect u);
t_vect					vect_op(t_vect u, t_vect v, char op);
t_vect					vect_scal_op(t_vect u, double a, char op);

/*
**********************************math_base.c***********************************
*/

double					solve_quadratic(double a, double b, double c);
double					distance(t_point a, t_point b);
t_base					create_base_cam(t_point cam, t_point coi);
t_point					coord_new_base(t_point p, t_base b);

/*
********************************intersection.c**********************************
*/

double					is_inter_line_sphere(t_ray line, t_sphere sphere);
double					is_inter_line_plane(t_ray line, t_plane plane);
double					is_inter_line_cylinder(t_ray line, t_cylinder cyl);
double					is_inter_line_cone(t_ray line, t_cone cone);

/*
************************************util.c**************************************
*/

double					deg_to_rad(double angle);
t_point					vect_to_point(t_vect u);
t_vect					point_to_vect(t_point p);

/*
*********************************image_util.c***********************************
*/

void					image_put_pixel(char *img_data, t_pixel pos, int width,
																int color);
void					print_usage(void);
void					create_image(t_env *e);

/*
**********************************material.c************************************
*/
void					material_emerald(t_obj_list *obj);
void					material_jade(t_obj_list *obj);
void					material_obsidian(t_obj_list *obj);
void					material_pearl(t_obj_list *obj);
void					material_ruby(t_obj_list *obj);

void					material_turquoise(t_obj_list *obj);
void					material_brass(t_obj_list *obj);
void					material_bronze(t_obj_list *obj);
void					material_chrome(t_obj_list *obj);
void					material_copper(t_obj_list *obj);

void					material_gold(t_obj_list *obj);
void					material_silver(t_obj_list *obj);
void					material_black_plastic(t_obj_list *obj);
void					material_cyan_plastic(t_obj_list *obj);
void					material_green_plastic(t_obj_list *obj);

void					material_red_plastic(t_obj_list *obj);
void					material_white_plastic(t_obj_list *obj);
void					material_yellow_plastic(t_obj_list *obj);
void					material_black_rubber(t_obj_list *obj);
void					material_cyan_rubber(t_obj_list *obj);

void					material_green_rubber(t_obj_list *obj);
void					material_red_rubber(t_obj_list *obj);
void					material_white_rubber(t_obj_list *obj);
void					material_yellow_rubber(t_obj_list *obj);

/*
*************************************ray.c**************************************
*/

void					compute_shading(t_env *e, t_ray shadow_ray, t_surface
													*surface);
void					compute_shadow(t_env *e, t_ray shadow_ray, t_surface
													*surface, t_point light);
void					compute_shine(t_ray shadow_ray, t_ray ray, t_surface
													*surface);

/*
***********************************parsing.c************************************
*/

void					make_cone(t_env *e, char **line);
void					make_sphere(t_env *e, char **line);
void					make_cylinder(t_env *e, char **line);
void					make_plane(t_env *e, char **line);
void					make_light(t_env *e);
void					add_coords(t_point *point, char *line);
void					add_color(t_color *color, char *line);
void					add_normal(t_vect *normal, char *line);
void					choose_material(t_env *e, t_obj_list *obj, char *str);
void					check_value_sizes(t_env *e);

/*
***********************************default.c************************************
*/

void					default_sphere(t_sphere *sphere);
void					default_plane(t_plane *plane);
void					default_cylinder(t_cylinder *cyl);
void					default_cone(t_cone *cone);
void					default_light(t_light_list *light);

/*
************************************move.c**************************************
*/

void					translate(t_point *initial, char *line);
void					rotate(t_vect *original, char *line);

void					*make_everything(void *e);

void					init_get_normal(t_pass_normal func[4]);
void					init_pass_inter(t_passerelle func[4]);
void					init_material(t_f_material func[24]);
void					init_name_material(char *name[24]);
void					parsing(t_env *e, char *arg);

t_surface				hit_object(t_env *e, t_ray ray);
t_screen				init_screen(t_point cam, double dist, t_base base);

#endif
