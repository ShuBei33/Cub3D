/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:17:22 by estoffel          #+#    #+#             */
/*   Updated: 2022/05/16 20:15:38 by estoffel         ###   ########.fr       */
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

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		y;
	int		x;
	int		o;
	void	*wall;
	void	*ground;
	void	*player;
	int		pos_p_x;
	int		pos_p_y;
	int		orient_p;
}				t_data;

/*********************************/
/*       F U N C T I O N S       */
/*********************************/

/*-------- P A R S I N G --------*/

/*--------- E V E N T S ---------*/

/*---------- C L E A N ----------*/

#endif
