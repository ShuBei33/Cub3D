/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertc_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 08:34:52 by lzaccome          #+#    #+#             */
/*   Updated: 2022/07/11 08:37:18 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	increment_steps_v(t_stuff *stuff, int *bc_angle, int **map)
{
	if (has_wall_at(stuff->raycast->next_vtouchx - *bc_angle,
			stuff->raycast->next_vtouchy, map, *stuff))
	{
		stuff->raycast->found_vhit = 1;
		stuff->raycast->vrt_wall_hitx = stuff->raycast->next_vtouchx;
		stuff->raycast->vrt_wall_hity = stuff->raycast->next_vtouchy;
		return (1);
	}
	else
	{
		stuff->raycast->next_vtouchx += stuff->raycast->xstep;
		stuff->raycast->next_vtouchy += stuff->raycast->ystep;
	}
	return (0);
}

void	calcule_increment_v(t_stuff *stuff, float *ray_angle, int *bc_angle)
{
	stuff->raycast->xintercept = (floor(stuff->px / TILE_SIZE) * TILE_SIZE);
	if (stuff->raycast->right)
		stuff->raycast->xintercept += TILE_SIZE;
	stuff->raycast->yintercept = stuff->py + (stuff->raycast->xintercept
			- stuff->px) * tan(*ray_angle);
	stuff->raycast->xstep = TILE_SIZE;
	if (stuff->raycast->left)
		stuff->raycast->xstep *= -1;
	stuff->raycast->ystep = TILE_SIZE * tan(*ray_angle);
	if (stuff->raycast->up && stuff->raycast->ystep > 0)
		stuff->raycast->ystep *= -1;
	if (stuff->raycast->down && stuff->raycast->ystep < 0)
		stuff->raycast->ystep *= -1;
	stuff->raycast->next_vtouchx = stuff->raycast->xintercept;
	stuff->raycast->next_vtouchy = stuff->raycast->yintercept;
	if (stuff->raycast->left)
		*bc_angle = 1;
}

void	vrt_grid_inter(t_stuff *stuff, float *ray_angle,
	int *bc_angle, int **map)
{
	calcule_increment_v(stuff, ray_angle, bc_angle);
	while (is_in_map(stuff->raycast->next_vtouchx,
			stuff->raycast->next_vtouchy, stuff->map_width,
			stuff->map_height))
	{
		if (increment_steps_v(stuff, bc_angle, map))
			break ;
	}
	*bc_angle = 0;
}

void	smalest_val(t_stuff *stuff, int i)
{
	if (stuff->raycast->h_distance < stuff->raycast->v_distance)
	{
		stuff->raycast->wall_hitx = stuff->raycast->hrz_wall_hitx;
		stuff->raycast->wall_hity = stuff->raycast->hrz_wall_hity;
		stuff->raycast->distance = stuff->raycast->h_distance;
		stuff->raycast->tab_hrz_x[i] = stuff->raycast->hrz_wall_hitx;
		stuff->raycast->tab_hrz_y[i] = stuff->raycast->hrz_wall_hity;
	}
	else
	{
		stuff->raycast->wall_hitx = stuff->raycast->vrt_wall_hitx;
		stuff->raycast->wall_hity = stuff->raycast->vrt_wall_hity;
		stuff->raycast->distance = stuff->raycast->v_distance;
		stuff->raycast->was_hit_vrt[i] = 1;
		stuff->raycast->tab_hrz_x[i] = stuff->raycast->vrt_wall_hitx;
		stuff->raycast->tab_hrz_y[i] = stuff->raycast->vrt_wall_hity;
	}
}

void	calc_ray_distance(t_stuff *stuff)
{
	if (stuff->raycast->found_hhit)
		stuff->raycast->h_distance = distance_bet_points(stuff->px,
				stuff->py, stuff->raycast->hrz_wall_hitx,
				stuff->raycast->hrz_wall_hity);
	else
		stuff->raycast->h_distance = 99999999.9;
	if (stuff->raycast->found_vhit)
		stuff->raycast->v_distance = distance_bet_points(stuff->px,
				stuff->py, stuff->raycast->vrt_wall_hitx,
				stuff->raycast->vrt_wall_hity);
	else
		stuff->raycast->v_distance = 99999999.9;
}
