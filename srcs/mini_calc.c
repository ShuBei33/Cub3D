/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 08:50:10 by lzaccome          #+#    #+#             */
/*   Updated: 2022/07/11 08:51:25 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	is_in_map(float x, float y, float width, float length)
{
	if (x >= 0 && x <= width && y >= 0 && y <= length)
		return (1);
	return (0);
}

float	distance_bet_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

int	has_wall_at(float x, float y, int **map, t_stuff stuff)
{
	int	map_posx;
	int	map_posy;

	if (x < 0 || x > stuff.map_width || y < 0 || y > stuff.map_height)
		return (1);
	map_posx = floor(x / TILE_SIZE);
	map_posy = floor(y / TILE_SIZE);
	if (map[map_posy][map_posx] == 1
		|| map[map_posy][map_posx] == 2
		|| map[map_posy][map_posx] == 3)
		return (1);
	return (0);
}
