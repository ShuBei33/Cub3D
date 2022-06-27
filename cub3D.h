/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:17:22 by estoffel          #+#    #+#             */
/*   Updated: 2022/06/21 19:56:14 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*********************************/
/*          D E F I N E          */
/*********************************/

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define LEFT 97
# define RIGHT 100
# define DOWN 115
# define UP 119
# define ESC 65307
# define CLOSE 17

# define WIDTH 720
# define HEIGHT 480

# define OR_NORTH
# define OR_SOUTH
# define OR_WEST
# define OR_EAST

/*********************************/
/*       L I B R A R I E S       */
/*********************************/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"

/*********************************/
/*      S T R U C T U R E S      */
/*********************************/

typedef struct s_data	t_data;
typedef struct s_error	t_error;
typedef struct s_txtr	t_txtr;

enum e_errcode
{
	E_INV_FMT = 1,
	E_INIT_MAP,
	E_INIT_MLX,
	E_LOAD_IMG,
	E_LOAD_CLR,
	E_CLONE,
	E_INV_SHP,
	E_OPEN_MAP,
	E_CHAR_PATT,
	E_SPAWN_ERR,
	E_NO_DATA,
	E_MLC_ERR,
};

typedef struct s_txtr
{
	void	*img;
	int		height;
	int		width;
}				t_txtr;

typedef struct s_data
{
	char		**map;
	char		**file;
	void		*mlx;
	void		*win;
	int			i;
	int			nb_line;
	double		pos_p_x;
	double		pos_p_y;
	int			maxlen;
	double		orient_p;
	t_txtr		no_txtr;
	t_txtr		so_txtr;
	t_txtr		we_txtr;
	t_txtr		ea_txtr;
	int			f_rgb;
	int			c_rgb;
}				t_data;

typedef struct s_error
{
	enum e_errcode	id;
	char			*err_msg;
}				t_error;

static t_error const	g_error[] = {
{.id = E_INV_FMT, .err_msg = "Error\nInvalid file format or extension\n"},
{.id = E_INIT_MAP, .err_msg = "Error\nTroubles while reading or init Map\n"},
{.id = E_INIT_MLX, .err_msg = "Error\nMlx initializaton failed\n"},
{.id = E_LOAD_IMG, .err_msg = "Error\nTroubles while loading or init image\n"},
{.id = E_LOAD_CLR, .err_msg = "Error\nTroubles while loading or init color\n"},
{.id = E_CLONE, .err_msg = "Error\nData already loaded\n"},
{.id = E_INV_SHP, .err_msg = "Error\nMap has an invalid shape\n"},
{.id = E_OPEN_MAP, .err_msg = "Error\nMap open\n"},
{.id = E_CHAR_PATT, .err_msg = "Error\nFound an invalid char pattern\n"},
{.id = E_SPAWN_ERR, .err_msg = "Error\nOnly one spawn please\n"},
{.id = E_NO_DATA, .err_msg = "Error\nSome required data is missing\n"},
{.id = E_MLC_ERR, .err_msg = "Error\nMalloc failed\n"},
};

/*********************************/
/*       F U N C T I O N S       */
/*********************************/

/*----------- I N I T -----------*/

int		init_mlx(t_data *data);

void	init_struct(t_data *data);

/*-------- P A R S I N G --------*/

int		checknprint(char *buf);
int		check_mlx(t_data *data);
int		check_extension(char **av);
int		get_file(t_data *data, char *av);
int		check_file(t_data *data);
int		parse_txtr(t_data *data, char *name);
int		parse_clr(int *rgb, char *path);
int		parse_map(t_data *data);
int		create_trgb(int t, int r, int g, int b);
int		load_data(t_data *data, char *name, int len);
int		check_char(t_data *data);
int		check_split(t_data *data);
int		check_err(t_data *data, char **av);
int		line_len(t_data *data, char *av);
int		p_count(t_data *data);

char	*read_file(char *av);

/*----- R A Y C A S T I N G -----*/

/*---------- U T I L S ----------*/

int		count_arg(char const *s, char c);
int		is_full_digit(char *str);
int		ft_strclen(char *str, char c);
int		initmlc(void *ptr, const size_t size, const char *s);

char	*ft_strclencmp(char *s1, char *s2, char c);

t_list	*newnode(char *line);

void	print_err(enum e_errcode id);
void	print_map(t_data *data);
void	print_struct(t_data *data);

/*---------- C L E A N ----------*/

int		release(void *ptr);
int		clean_mlx(t_data *data);
int		destroy_mlx(t_data *data);

void	free_map(t_data *data);
void	free_file(t_data *data);
void	free_data(t_data *data);

#endif
