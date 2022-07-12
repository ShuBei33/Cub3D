/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_txtr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 08:53:05 by lzaccome          #+#    #+#             */
/*   Updated: 2022/07/11 08:54:10 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

unsigned int	get_pixel_color(t_img txt, int x, int y)
{
	char	*dst;

	dst = txt.addr + (x * (txt.bits_per_pixel / 8) + y * txt.line_length);
	return ((*(unsigned int *)dst));
}

t_img	get_wall_text(t_txt txt, float pa, int orientation)
{
	if (orientation)
	{
		if (pa < 0.5 * PI || pa > 1.5 * PI)
			return (txt.south);
		else
			return (txt.west);
	}
	else
	{
		if (!(pa > 0 && pa < PI))
			return (txt.east);
		else
			return (txt.north);
	}
}

void	offset_wall(t_stuff *stuff, int *x_off, int *y_off, int x)
{
	if (stuff->raycast->wallstrip_height > WINDOW_HEIGHT)
	{
		stuff->y_start = 0;
		stuff->y_end = WINDOW_HEIGHT;
	}
	else
	{
		stuff->y_start = (WINDOW_HEIGHT / 2
				- stuff->raycast->wallstrip_height / 2);
		stuff->y_end = stuff->y_start + stuff->raycast->wallstrip_height;
	}
	if (stuff->raycast->was_hit_vrt[x] == 0)
		*x_off = (int)stuff->raycast->tab_hrz_x[x] % (int)TILE_SIZE;
	else
		*x_off = (int)stuff->raycast->tab_hrz_y[x] % (int)TILE_SIZE;
	*x_off = (*x_off * 64) / TILE_SIZE;
	if (stuff->raycast->wallstrip_height > WINDOW_HEIGHT)
		*y_off = (stuff->raycast->wallstrip_height / 2 - WINDOW_HEIGHT / 2);
	else
		*y_off = 0;
}

void	init_txt(t_data *mlx, t_img *txt, char *path, t_combo *combo)
{
	txt->img = mlx_xpm_file_to_image(mlx->mlx, path, &txt->h, &txt->w);
	if (!txt->img)
	{
		print_err(E_LOAD_IMG);
		free_mlx(mlx, txt, combo->map, combo->stuff);
	}
	txt->addr = mlx_get_data_addr(txt->img, &txt->bits_per_pixel,
			&txt->line_length, &txt->endian);
}

void	get_txt(t_data *mlx, t_combo *combo)
{
	init_txt(mlx, &mlx->txt.east, combo->stuff->ea_txtr.img, combo);
	init_txt(mlx, &mlx->txt.north, combo->stuff->no_txtr.img, combo);
	init_txt(mlx, &mlx->txt.west, combo->stuff->we_txtr.img, combo);
	init_txt(mlx, &mlx->txt.south, combo->stuff->so_txtr.img, combo);
}
