/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 01:01:14 by lzaccome          #+#    #+#             */
/*   Updated: 2022/07/11 08:48:05 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_cross(t_combo *combo)
{
	free_mlx(combo->mlx, combo->img, combo->map, combo->stuff);
	return (0);
}

int	direction(int keycode, t_combo *combo)
{
	if (keycode == 65307)
		free_mlx(combo->mlx, combo->img, combo->map, combo->stuff);
	else if (keycode == 65363)
		move_right(combo);
	else if (keycode == 100)
		move_to_right(combo);
	else if (keycode == 119 || keycode == 65362)
		move_up(combo);
	else if (keycode == 65361)
		move_left(combo);
	else if (keycode == 97)
		move_to_left(combo);
	else if (keycode == 115 || keycode == 65364)
		move_down(combo);
	return (0);
}

void	move_right(t_combo *combo)
{
	combo->stuff->pa += 0.1;
	if (combo->stuff->pa > 2 * PI)
		combo->stuff->pa -= 2 * PI;
	combo->stuff->pdx = cos(combo->stuff->pa) * 5;
	combo->stuff->pdy = sin(combo->stuff->pa) * 5;
	fill_grey(combo->stuff->map_width, combo->stuff->map_height, combo->img);
	build_walls(combo->map, combo->img, combo->stuff);
	draw_player(combo->img, *(combo->stuff));
	draw_rays(combo->img, combo->stuff, combo->map);
	render_3d(combo->img, combo->stuff, *combo);
	mlx_put_image_to_window(combo->mlx->mlx, combo->mlx->win,
		combo->img->img, 0, 0);
	return ;
}

void	start_angle(t_stuff *stuff)
{
	if (stuff->start_angle == 'S')
	{
		stuff->pa += PI / 2;
	}
	else if (stuff->start_angle == 'W')
	{
		stuff->pa += PI;
	}
	else if (stuff->start_angle == 'N')
	{
		stuff->pa += 3 * (PI / 2);
	}
}

void	check_direction(t_raycast *raycast, float pa)
{
	raycast->down = 0;
	raycast->up = 0;
	raycast->left = 0;
	raycast->right = 0;
	if (pa > 0 && pa < PI)
		raycast->down = 1;
	else
		raycast->up = 1;
	if (pa < 0.5 * PI || pa > 1.5 * PI)
		raycast->right = 1;
	else
		raycast->left = 1;
}
