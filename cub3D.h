/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:17:22 by estoffel          #+#    #+#             */
/*   Updated: 2022/05/20 01:27:15 by estoffel         ###   ########.fr       */
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

# define NORTH "./textures/.xpm"
# define SOUTH "./textures/.xpm"
# define WEST "./textures/.xpm"
# define EAST "./textures/.xpm"

# define OR_NORTH 
# define OR_SOUTH
# define OR_WEST
# define OR_EAST

/*********************************/
/*       L I B R A R I E S       */
/*********************************/

# include <unistd.h>
# include <stdlib.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"

/*********************************/
/*      S T R U C T U R E S      */
/*********************************/

typedef struct s_data	t_data;
typedef struct s_error	t_error;

enum e_errcode
{
	E_INV_FMT = 1,
	E_INIT_MAP,
	E_INV_SHP,
	E_OPEN_MAP,
	E_CHAR_PATT,
	E_SPAWN_ERR,
};

typedef struct s_data
{
	char		**map;
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	int			i;
	int			j;
	void		*wall;
	void		*ground;
	void		*player;
	double		pos_p_x;
	double		pos_p_y;
	double		orient_p;
}				t_data;

typedef struct s_error
{
	enum e_errcode	id;
	char			*err_msg;
}				t_error;

static t_error const	g_error[] = {
{.id = E_INV_FMT, .err_msg = "Error\nInvalid file format or extension\n"},
{.id = E_INIT_MAP, .err_msg = "Error\nTroubles while reading or init Map\n"},
{.id = E_INV_SHP, .err_msg = "Error\nMap has an invalid shape\n"},
{.id = E_OPEN_MAP, .err_msg = "Error\nMap open\n"},
{.id = E_CHAR_PATT, .err_msg = "Error\nFound an invalid char pattern\n"},
{.id = E_SPAWN_ERR, .err_msg = "Error\nOnly one spawn please\n"},
};

/*********************************/
/*       F U N C T I O N S       */
/*********************************/

/*----------- I N I T -----------*/

void	init_struct(t_data *data);

/*-------- P A R S I N G --------*/

char	*read_map(char *av);

int		check_extension(char **av);
int		get_map(t_data *data, char *av);
int		check_char(t_data *data, char *av);
int		check_err(t_data *data, char *av);

/*--------- E V E N T S ---------*/

/*---------- U T I L S ----------*/

void	print_err(enum e_errcode id);

/*---------- C L E A N ----------*/

void	free_map(t_data *data);
void	free_data(t_data *data);

#endif
