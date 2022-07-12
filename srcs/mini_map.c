/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 01:14:23 by lzaccome          #+#    #+#             */
/*   Updated: 2022/07/11 09:02:35 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	build_walls(int **map, t_img *img, t_stuff *stuff)
{
	int		x;
	int		y;
	t_rect	block;

	y = 0;
	block.width = TILE_SIZE - 2;
	block.height = TILE_SIZE - 2;
	block.y = 0;
	block.x = 0;
	while (y < stuff->line_count)
	{
		x = 0;
		while (x < stuff->line_len)
		{
			if (map[y][x] == 0)
				draw_rect(block, 0x00000000, img);
			else
				draw_rect(block, 0x009CFF9F, img);
			x++;
			block.x += TILE_SIZE;
		}
		block.x = 0;
		block.y += TILE_SIZE;
		y++;
	}
}

void	init_int_tab(t_stuff *stuff)
{
	stuff->raycast->num_rays = WINDOW_WIDTH / WALL_STRIP;
	stuff->raycast->rays = malloc(stuff->raycast->num_rays * sizeof(float));
	if (!stuff->raycast->rays)
		return ;
	stuff->raycast->rays_angle = malloc(stuff->raycast->num_rays
			* sizeof(float));
	if (!stuff->raycast->rays_angle)
		return ;
	stuff->raycast->tab_hrz_x = malloc(stuff->raycast->num_rays
			* sizeof(float));
	if (!stuff->raycast->tab_hrz_x)
		return ;
	stuff->raycast->tab_hrz_y = malloc(stuff->raycast->num_rays
			* sizeof(float));
	if (!stuff->raycast->tab_hrz_y)
		return ;
	stuff->raycast->was_hit_vrt = malloc(stuff->raycast->num_rays
			* sizeof(float));
	if (!stuff->raycast->was_hit_vrt)
		return ;
}

void	launch_mlx(t_data *mlx, t_combo *combo,
	t_img *img, int **map)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
	{
		print_err(E_INIT_MLX);
		free_mlx(mlx, img, map, combo->stuff);
	}
	mlx->win = mlx_new_window(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	combo->mlx = mlx;
	get_txt(mlx, combo);
	img->img = mlx_new_image(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	fill_grey(combo->stuff->map_width, combo->stuff->map_height, img);
	build_walls(map, img, combo->stuff);
	draw_player(img, *combo->stuff);
	draw_rays(img, combo->stuff, map);
	render_3d(img, combo->stuff, *combo);
	combo->img = img;
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	mlx_hook(mlx->win, 17, 0L, &ft_cross, combo);
	mlx_hook(mlx->win, 2, 1L << 0, direction, combo);
	mlx_loop(mlx->mlx);
}

void	mini_map(int **map, t_stuff stuff)
{
	t_data		mlx;
	t_combo		combo;
	t_img		img;
	t_raycast	raycast;

	stuff.px = TILE_SIZE * (stuff.px) + TILE_SIZE / 2;
	stuff.py = TILE_SIZE * (stuff.py) + TILE_SIZE / 2;
	stuff.map_width = TILE_SIZE * stuff.line_len;
	stuff.map_height = TILE_SIZE * stuff.line_count;
	start_angle(&stuff);
	stuff.pdx = cos(stuff.pa) * 5;
	stuff.pdy = sin(stuff.pa) * 5;
	combo.map = map;
	combo.stuff = &stuff;
	combo.count = 0;
	ft_bzero(&raycast, sizeof(t_raycast));
	stuff.raycast = &raycast;
	ft_bzero(&mlx, sizeof(t_data));
	ft_bzero(&mlx, sizeof(t_data));
	launch_mlx(&mlx, &combo, &img, map);
	return ;
}
