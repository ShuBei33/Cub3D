/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 08:56:58 by lzaccome          #+#    #+#             */
/*   Updated: 2022/07/11 08:57:30 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	render_3d(t_img *img, t_stuff *stuff, t_combo combo)
{
	int		i;
	float	ray;
	float	wallstrip_height;
	float	dist_project_plane;
	t_rect	rect;

	draw_back(stuff, img);
	i = 0;
	dist_project_plane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
	while (i < stuff->raycast->num_rays)
	{
		ray = (stuff->raycast->rays[i] * cos(stuff->raycast->rays_angle[i]
					- stuff->pa));
		wallstrip_height = (TILE_SIZE / ray) * dist_project_plane;
		rect.x = i * WALL_STRIP;
		rect.y = (WINDOW_HEIGHT / 2) - (wallstrip_height / 2);
		rect.width = WALL_STRIP;
		rect.height = wallstrip_height;
		stuff->raycast->wallstrip_height = wallstrip_height;
		draw_wall(img, stuff, get_wall_text(combo.mlx->txt,
				stuff->raycast->rays_angle[i],
				stuff->raycast->was_hit_vrt[i]), i);
		i++;
	}
	free_int_tab(stuff);
}
