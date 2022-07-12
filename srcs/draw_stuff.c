/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 08:38:42 by lzaccome          #+#    #+#             */
/*   Updated: 2022/07/11 09:12:52 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	fill_grey(int width, int height, t_img *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < height)
	{
		while (x < width)
		{
			my_mlx_pixel_put(img, x, y, 0x50505050);
			x++;
		}
		x = 0;
		y++;
	}
	return ;
}

void	draw_back(t_stuff *stuff, t_img *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			if (!(x < stuff->map_width && y < stuff->map_height))
			{
				if (y < WINDOW_HEIGHT / 2)
					my_mlx_pixel_put(img, x, y, stuff->c_rgb);
				else
					my_mlx_pixel_put(img, x, y, stuff->f_rgb);
			}
			x++;
		}
		y++;
	}
}

void	draw_player(t_img *img, t_stuff stuff)
{
	int	width;
	int	height;
	int	i;

	width = -2;
	height = -2;
	i = 0;
	while (height < 3)
	{
		while (width < 3)
		{
			my_mlx_pixel_put(img, stuff.px + width,
				stuff.py + height, 0xFFDC16);
			width++;
		}
		width = -2;
		height++;
	}
	while (i < (15 * MINIMAP_SCALE_FACTOR))
	{
		stuff.px += stuff.pdx / 5;
		stuff.py += stuff.pdy / 5;
		my_mlx_pixel_put(img, stuff.px, stuff.py, 0xFFDC16);
		i++;
	}
}

void	draw_wall(t_img *img, t_stuff *stuff, t_img txt, int x)
{
	int		y_off;
	int		x_off;
	int		txt_wallstrip;

	txt_wallstrip = 0;
	offset_wall(stuff, &x_off, &y_off, x);
	while (stuff->y_start < stuff->y_end)
	{
		txt_wallstrip = 0;
		while (txt_wallstrip < WALL_STRIP)
		{
			if (!(x < stuff->map_width && stuff->y_start < stuff->map_height))
			{
				my_mlx_pixel_put(img, x, stuff->y_start,
					get_pixel_color(txt, x_off, (y_off * 64)
						/ stuff->raycast->wallstrip_height));
			}
			txt_wallstrip++;
		}
		stuff->y_start++;
		y_off++;
	}
}

void	draw_rect(t_rect rect, int color, t_img *img)
{
	float	x;
	float	y;

	y = rect.y;
	while (y < rect.y + rect.height)
	{
		x = rect.x;
		while (x < rect.x + rect.width)
		{
			my_mlx_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}
