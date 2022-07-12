/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizon_inter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 08:32:14 by lzaccome          #+#    #+#             */
/*   Updated: 2022/07/11 08:36:50 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_rays(t_stuff *stuff, float *ray_angle, int *bc_angle, int i)
{
	*bc_angle = 0;
	stuff->raycast->found_vhit = 0;
	stuff->raycast->found_hhit = 0;
	stuff->raycast->was_hit_vrt[i] = 0;
	if (*ray_angle < 0)
		*ray_angle += 2 * PI;
	if (*ray_angle > 2 * PI)
	*ray_angle -= 2 * PI;
	check_direction(stuff->raycast, *ray_angle);
}

int	increment_steps_h(t_stuff *stuff, int *bc_angle, int **map)
{
	if (has_wall_at(stuff->raycast->next_htouchx,
			stuff->raycast->next_htouchy - *bc_angle, map, *stuff))
	{
		stuff->raycast->found_hhit = 1;
		stuff->raycast->hrz_wall_hitx = stuff->raycast->next_htouchx;
		stuff->raycast->hrz_wall_hity = stuff->raycast->next_htouchy;
		return (1);
	}
	else
	{
		stuff->raycast->next_htouchx += stuff->raycast->xstep;
		stuff->raycast->next_htouchy += stuff->raycast->ystep;
	}
	return (0);
}

void	calcule_increment_h(t_stuff *stuff, float *ray_angle, int *bc_angle)
{
	stuff->raycast->yintercept = (floor(stuff->py / TILE_SIZE) * TILE_SIZE);
	if (stuff->raycast->down)
		stuff->raycast->yintercept += TILE_SIZE;
	stuff->raycast->xintercept = stuff->px + (stuff->raycast->yintercept
			- stuff->py) / tan(*ray_angle);
	stuff->raycast->ystep = TILE_SIZE;
	if (stuff->raycast->up)
		stuff->raycast->ystep *= -1;
	stuff->raycast->xstep = TILE_SIZE / tan(*ray_angle);
	if (stuff->raycast->left && stuff->raycast->xstep > 0)
		stuff->raycast->xstep *= -1;
	if (stuff->raycast->right && stuff->raycast->xstep < 0)
		stuff->raycast->xstep *= -1;
	stuff->raycast->next_htouchx = stuff->raycast->xintercept;
	stuff->raycast->next_htouchy = stuff->raycast->yintercept;
	if (stuff->raycast->up)
		*bc_angle = 1;
}

void	hor_grid_inter(t_stuff *stuff, float *ray_angle,
	int *bc_angle, int **map)
{
	calcule_increment_h(stuff, ray_angle, bc_angle);
	while (is_in_map(stuff->raycast->next_htouchx,
			stuff->raycast->next_htouchy, stuff->map_width,
			stuff->map_height))
	{
		if (increment_steps_h(stuff, bc_angle, map))
			break ;
	}
	*bc_angle = 0;
}

void	draw_rays(t_img *img, t_stuff *stuff, int **map)
{
	int		i;
	int		column_id;
	int		bc_angle;
	float	ray_angle;

	(void)img;
	i = 0;
	init_int_tab(stuff);
	column_id = 0;
	ray_angle = stuff->pa - (FOV_ANGLE / 2);
	while (i < stuff->raycast->num_rays)
	{
		init_rays(stuff, &ray_angle, &bc_angle, i);
		hor_grid_inter(stuff, &ray_angle, &bc_angle, map);
		vrt_grid_inter(stuff, &ray_angle, &bc_angle, map);
		calc_ray_distance(stuff);
		smalest_val(stuff, i);
		stuff->raycast->rays[i] = stuff->raycast->distance;
		stuff->raycast->rays_angle[i] = ray_angle;
		i++;
		column_id++;
		ray_angle += FOV_ANGLE / stuff->raycast->num_rays;
	}
}
