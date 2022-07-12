/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:19:03 by lzaccome          #+#    #+#             */
/*   Updated: 2022/07/11 09:53:00 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*********************************/
/*          D E F I N E          */
/*********************************/

// FOV_ANGLE = 60 * (PI / 180)

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define WINDOW_WIDTH 1500
# define WINDOW_HEIGHT 1000
# define PI 3.1415926535
# define MINIMAP_SCALE_FACTOR 0.5
# define TILE_SIZE 32
# define FOV_ANGLE 1.0471975512
# define WALL_STRIP 1
# define EAST "textures/east.xpm"
# define NORTH "textures/north.xpm"
# define WEST "textures/west.xpm"
# define SOUTH "textures/south.xpm"

/*********************************/
/*       L I B R A R I E S       */
/*********************************/

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

/*********************************/
/*      S T R U C T U R E S      */
/*********************************/

typedef struct s_error	t_error;
typedef struct s_txtr	t_txtr;

enum e_errcode
{
	E_INV_FMT = 1,
	E_OP_F,
	E_INIT_MAP,
	E_INIT_MLX,
	E_LOAD_IMG,
	E_LOAD_CLR,
	E_CLONE,
	E_INV_SHP,
	E_OPEN_MAP,
	E_BIG_MAP,
	E_CHAR_PATT,
	E_SPAWN_ERR,
	E_NO_DATA,
	E_MLC_ERR,
};

typedef struct s_raycast
{
	float	wall_hitx;
	float	wall_hity;
	float	hrz_wall_hitx;
	float	hrz_wall_hity;
	float	vrt_wall_hitx;
	float	vrt_wall_hity;
	float	v_distance;
	float	h_distance;
	float	distance;
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	float	next_htouchx;
	float	next_htouchy;
	float	next_vtouchx;
	float	next_vtouchy;
	float	*rays_angle;
	float	*rays;
	float	*tab_hrz_x;
	float	*tab_hrz_y;
	float	wallstrip_height;
	int		found_vhit;
	int		found_hhit;
	int		*was_hit_vrt;
	int		up;
	int		down;
	int		right;
	int		left;
	int		num_rays;
}					t_raycast;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		h;
	int		w;
}				t_img;

typedef struct s_txt {
	t_img	east;
	t_img	north;
	t_img	west;
	t_img	south;
}				t_txt;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_txt	txt;
	int		x;
	int		y;
}				t_data;

typedef struct s_txtr
{
	void	*img;
	int		cnt;
}				t_txtr;

typedef struct s_stuff
{
	int			file_line;
	int			line_count;
	int			line_len;
	int			p_cnt;
	int			y_start;
	int			y_end;
	float		px;
	float		py;
	float		pdx;
	float		pdy;
	float		pa;
	char		start_angle;
	int			map_width;
	int			map_height;
	char		**file;
	int			i;
	t_txtr		no_txtr;
	t_txtr		so_txtr;
	t_txtr		we_txtr;
	t_txtr		ea_txtr;
	int			f_rgb;
	int			f_cnt;
	int			c_rgb;
	int			c_cnt;
	int			**map;
	t_raycast	*raycast;
}				t_stuff;

typedef struct s_combo {
	t_data		*mlx;
	t_stuff		*stuff;
	t_img		*img;
	int			**map;
	int			count;
}				t_combo;

typedef struct s_rect {
	float	x;
	float	y;
	float	width;
	float	height;
}				t_rect;

typedef struct s_error
{
	enum e_errcode	id;
	char			*err_msg;
}				t_error;

static t_error const	g_error[] = {
{.id = E_INV_FMT, .err_msg = "Error\nInvalid file format or extension\n"},
{.id = E_OP_F, .err_msg = "Error\nOpen failed\n"},
{.id = E_INIT_MAP, .err_msg = "Error\nTroubles while reading or init Map\n"},
{.id = E_INIT_MLX, .err_msg = "Error\nMlx initializaton failed\n"},
{.id = E_LOAD_IMG, .err_msg = "Error\nTroubles while loading or init image\n"},
{.id = E_LOAD_CLR, .err_msg = "Error\nTroubles while loading or init color\n"},
{.id = E_CLONE, .err_msg = "Error\nData can't be set twice\n"},
{.id = E_INV_SHP, .err_msg = "Error\nMap has an invalid shape\n"},
{.id = E_OPEN_MAP, .err_msg = "Error\nMap open\n"},
{.id = E_BIG_MAP, .err_msg = "Error\nMap too big for the window\n"},
{.id = E_CHAR_PATT, .err_msg = "Error\nFound an invalid char pattern\n"},
{.id = E_SPAWN_ERR, .err_msg = "Error\nNumber of spawn required is one\n"},
{.id = E_NO_DATA, .err_msg = "Error\nSome required data is missing\n"},
{.id = E_MLC_ERR, .err_msg = "Error\nMalloc failed\n"},
};

/*********************************/
/*       F U N C T I O N S       */
/*********************************/

/////////////////////////////////////////////////////////////////////
///  E N O R A
/////////////////////////////////////////////////////////////////////

/*----------- I N I T -----------*/

void			init_struct(t_stuff *stuff);

/*-------- P A R S I N G --------*/

int				checknprint(char *buf);
int				check_mlx(t_stuff *stuff);
int				check_extension(char **av);
int				get_file(t_stuff *stuff, char *av);
int				check_file(t_stuff *stuff, int i);
int				check_nb_content(t_stuff *stuff);
int				parse_txtr(t_stuff *stuff, char *linetxtr, char *name);
int				parse_clr(int *rgb, char *path, int i, int j);
int				parse_map(t_stuff *stuff, int i, int j);
int				create_trgb(int t, int r, int g, int b);
int				load_stuff(t_stuff *stuff, char *path, char *name);
int				check_char(char *s);
int				check_split(t_stuff *stuff);
int				check_err(t_stuff *stuff, char **av);
int				line_len(t_stuff *stuff, char *av);
int				p_count(t_stuff *stuff);

char			*read_file(char *av);

/*------ F L O O D F I L L ------*/

int				create_nmap(t_stuff *stuff);
int				fill_one(t_stuff *stuff);
int				set_filter(t_stuff *stuff);
int				flood_fill(t_stuff *stuff, int x, int y, int new_case);
int				check_fail(t_stuff *stuff, int x, int y);

/*---------- U T I L S ----------*/

int				count_arg(char const *s, char c);
int				is_full_digit(char *str);
int				is_full_spaces(char *str);
int				ft_strclen(char *str, char c);
int				initmlc(void *ptr, const size_t size, const char *s);

char			**ft_onlysplit(t_stuff *stuff, char const *s, char c);

t_list			*newnode(char *line);

void			print_err(enum e_errcode id);
void			print_map(t_stuff *stuff);
void			print_struct(t_stuff *stuff);
void			print_tab_int(t_stuff *stuff);

void			load_no(t_stuff *stuff, char *path);
void			load_so(t_stuff *stuff, char *path);
void			load_we(t_stuff *stuff, char *path);
void			load_ea(t_stuff *stuff, char *path);
void			load_no(t_stuff *stuff, char *path);

/*---------- C L E A N ----------*/

int				release(void *ptr);

void			freetab(char **s);
void			free_file(t_stuff *stuff);
void			free_int_tab(t_stuff *stuff);
void			free_stuff(t_stuff *stuff);
void			free_mlx(t_data *mlx, t_img *img, int **map, t_stuff *stuff);

/////////////////////////////////////////////////////////////////////
///  L O U I S
/////////////////////////////////////////////////////////////////////

/* -------------------------------------------------------------------------- */
/*                              FILE = ./main.c                               */
/* -------------------------------------------------------------------------- */
int				main(int ac, char **av);

/* -------------------------------------------------------------------------- */
/*                              FILE = ./mini_map.c                          */
/* -------------------------------------------------------------------------- */
int				has_wall_at(float x, float y, int **map, t_stuff stuff);
void			mini_map(int **map, t_stuff stuff);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
void			free_mlx(t_data *mlx, t_img *img, int **map, t_stuff *stuff);
void			build_walls(int **map, t_img *img, t_stuff *stuff);
void			init_int_tab(t_stuff *stuff);
void			launch_mlx(t_data *mlx, t_combo *combo, t_img *img, int **map);

/* -------------------------------------------------------------------------- */
/*                              FILE = ./direction.c                          */
/* -------------------------------------------------------------------------- */
int				direction(int keycode, t_combo *combo);
int				ft_cross(t_combo *combo);
void			move_right(t_combo *combo);
void			start_angle(t_stuff *stuff);
void			check_direction(t_raycast *raycast, float pa);

/* -------------------------------------------------------------------------- */
/*                              FILE = ./movements.c                          */
/* -------------------------------------------------------------------------- */
void			move_up(t_combo *combo);
void			move_left(t_combo *combo);
void			move_down(t_combo *combo);
void			move_to_right(t_combo *combo);
void			move_to_left(t_combo *combo);

/* -------------------------------------------------------------------------- */
/*                             FILE = ./draw_stuff.c                          */
/* -------------------------------------------------------------------------- */
void			fill_grey(int width, int height, t_img *img);
void			draw_back(t_stuff *stuff, t_img *img);
void			draw_player(t_img *img, t_stuff stuff);
void			draw_wall(t_img *img, t_stuff *stuff, t_img txt, int x);
void			draw_rect(t_rect rect, int color, t_img *img);

/* -------------------------------------------------------------------------- */
/*                           FILE = ./horizon_inter.c                         */
/* -------------------------------------------------------------------------- */
int				increment_steps_h(t_stuff *stuff, int *bc_angle, int **map);
void			init_rays(t_stuff *stuff, float *ray_angle,
					int *bc_angle, int i);
void			calcule_increment_h(t_stuff *stuff, float *ray_angle,
					int *bc_angle);
void			hor_grid_inter(t_stuff *stuff, float *ray_angle,
					int *bc_angle, int **map);
void			draw_rays(t_img *img, t_stuff *stuff, int **map);

/* -------------------------------------------------------------------------- */
/*                            FILE = ./manage_txtr.c                          */
/* -------------------------------------------------------------------------- */
t_img			get_wall_text(t_txt txt, float pa, int orientation);
void			offset_wall(t_stuff *stuff, int *x_off, int *y_off, int x);
void			init_txt(t_data *mlx, t_img *txt, char *path, t_combo *combo);
void			get_txt(t_data *mlx, t_combo *combo);
unsigned int	get_pixel_color(t_img txt, int x, int y);

/* -------------------------------------------------------------------------- */
/*                             FILE = ./mini_calc.c                           */
/* -------------------------------------------------------------------------- */
int				is_in_map(float x, float y, float width, float length);
int				has_wall_at(float x, float y, int **map, t_stuff stuff);
float			distance_bet_points(float x1, float y1, float x2, float y2);

/* -------------------------------------------------------------------------- */
/*                            FILE = ./vertc_inter.c                          */
/* -------------------------------------------------------------------------- */
int				increment_steps_v(t_stuff *stuff, int *bc_angle, int **map);
void			calcule_increment_v(t_stuff *stuff, float *ray_angle,
					int *bc_angle);
void			vrt_grid_inter(t_stuff *stuff, float *ray_angle,
					int *bc_angle, int **map);
void			smalest_val(t_stuff *stuff, int i);
void			calc_ray_distance(t_stuff *stuff);

/* -------------------------------------------------------------------------- */
/*                              FILE = ./wolf.c                               */
/* -------------------------------------------------------------------------- */
void			render_3d(t_img *img, t_stuff *stuff, t_combo combo);

#endif
