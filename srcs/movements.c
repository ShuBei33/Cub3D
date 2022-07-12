/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 01:27:42 by lzaccome          #+#    #+#             */
/*   Updated: 2022/07/11 09:30:18 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	move_up(t_combo *combo)
{
	combo->stuff->pdx = cos(combo->stuff->pa) * 5;
	combo->stuff->pdy = sin(combo->stuff->pa) * 5;
	if (!(has_wall_at(combo->stuff->px + combo->stuff->pdx,
				combo->stuff->py, combo->map, *combo->stuff)
			|| has_wall_at(combo->stuff->px, combo->stuff->py
				+ combo->stuff->pdy, combo->map, *combo->stuff)))
	{
		combo->stuff->px += combo->stuff->pdx;
		combo->stuff->py += combo->stuff->pdy;
	}
	fill_grey(combo->stuff->map_width, combo->stuff->map_height, combo->img);
	build_walls(combo->map, combo->img, combo->stuff);
	draw_player(combo->img, *(combo->stuff));
	draw_rays(combo->img, combo->stuff, combo->map);
	render_3d(combo->img, combo->stuff, *combo);
	mlx_put_image_to_window(combo->mlx->mlx, combo->mlx->win,
		combo->img->img, 0, 0);
}

void	move_left(t_combo *combo)
{
	combo->stuff->pa -= 0.1;
	if (combo->stuff->pa < 0)
		combo->stuff->pa += 2 * PI;
	combo->stuff->pdx = cos(combo->stuff->pa) * 5;
	combo->stuff->pdy = sin(combo->stuff->pa) * 5;
	fill_grey(combo->stuff->map_width, combo->stuff->map_height, combo->img);
	build_walls(combo->map, combo->img, combo->stuff);
	draw_player(combo->img, *(combo->stuff));
	draw_rays(combo->img, combo->stuff, combo->map);
	render_3d(combo->img, combo->stuff, *combo);
	mlx_put_image_to_window(combo->mlx->mlx, combo->mlx->win,
		combo->img->img, 0, 0);
}

void	move_down(t_combo *combo)
{
	combo->stuff->pdx = cos(combo->stuff->pa) * 5;
	combo->stuff->pdy = sin(combo->stuff->pa) * 5;
	if (!(has_wall_at(combo->stuff->px - combo->stuff->pdx,
				combo->stuff->py, combo->map, *combo->stuff)
			|| has_wall_at(combo->stuff->px, combo->stuff->py
				- combo->stuff->pdy, combo->map, *combo->stuff)))
	{
		combo->stuff->px -= combo->stuff->pdx;
		combo->stuff->py -= combo->stuff->pdy;
	}
	fill_grey(combo->stuff->map_width, combo->stuff->map_height, combo->img);
	build_walls(combo->map, combo->img, combo->stuff);
	draw_player(combo->img, *(combo->stuff));
	draw_rays(combo->img, combo->stuff, combo->map);
	render_3d(combo->img, combo->stuff, *combo);
	mlx_put_image_to_window(combo->mlx->mlx, combo->mlx->win,
		combo->img->img, 0, 0);
}

void	move_to_right(t_combo *combo)
{
	combo->stuff->pdx = cos((combo->stuff->pa + (PI / 2))) * 5;
	combo->stuff->pdy = sin((combo->stuff->pa + (PI / 2))) * 5;
	if (!(has_wall_at(combo->stuff->px + combo->stuff->pdx,
				combo->stuff->py, combo->map, *combo->stuff)
			|| has_wall_at(combo->stuff->px, combo->stuff->py
				+ combo->stuff->pdy, combo->map, *combo->stuff)))
	{
		combo->stuff->px += combo->stuff->pdx;
		combo->stuff->py += combo->stuff->pdy;
	}
	fill_grey(combo->stuff->map_width, combo->stuff->map_height, combo->img);
	build_walls(combo->map, combo->img, combo->stuff);
	draw_player(combo->img, *(combo->stuff));
	draw_rays(combo->img, combo->stuff, combo->map);
	render_3d(combo->img, combo->stuff, *combo);
	mlx_put_image_to_window(combo->mlx->mlx, combo->mlx->win,
		combo->img->img, 0, 0);
}

void	move_to_left(t_combo *combo)
{
	combo->stuff->pdx = cos((combo->stuff->pa - (PI / 2))) * 5;
	combo->stuff->pdy = sin((combo->stuff->pa - (PI / 2))) * 5;
	if (!(has_wall_at(combo->stuff->px + combo->stuff->pdx,
				combo->stuff->py, combo->map, *combo->stuff)
			|| has_wall_at(combo->stuff->px, combo->stuff->py
				+ combo->stuff->pdy, combo->map, *combo->stuff)))
	{
		combo->stuff->px += combo->stuff->pdx;
		combo->stuff->py += combo->stuff->pdy;
	}
	fill_grey(combo->stuff->map_width, combo->stuff->map_height, combo->img);
	build_walls(combo->map, combo->img, combo->stuff);
	draw_player(combo->img, *(combo->stuff));
	draw_rays(combo->img, combo->stuff, combo->map);
	render_3d(combo->img, combo->stuff, *combo);
	mlx_put_image_to_window(combo->mlx->mlx, combo->mlx->win,
		combo->img->img, 0, 0);
}
