/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:36:38 by estoffel          #+#    #+#             */
/*   Updated: 2022/07/11 08:46:41 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	freetab(char **s)
{
	int	i;

	i = 0;
	while (s && s[i])
		free(s[i++]);
	release(&s);
}

void	free_file(t_stuff *stuff)
{
	int	i;

	i = 0;
	while (stuff->file && stuff->file[i])
		free(stuff->file[i++]);
	i = 0;
	while (stuff->map && i < stuff->line_count)
		free(stuff->map[i++]);
	release(&stuff->map);
	release(&stuff->file);
}

void	free_int_tab(t_stuff *stuff)
{
	free(stuff->raycast->rays_angle);
	free(stuff->raycast->rays);
	free(stuff->raycast->tab_hrz_x);
	free(stuff->raycast->tab_hrz_y);
	free(stuff->raycast->was_hit_vrt);
}

void	free_mlx(t_data *mlx, t_img *img, int **map, t_stuff *stuff)
{
	(void)map;
	if (mlx->mlx)
	{
		if (mlx->txt.east.img)
			mlx_destroy_image(mlx->mlx, mlx->txt.east.img);
		if (mlx->txt.north.img)
			mlx_destroy_image(mlx->mlx, mlx->txt.north.img);
		if (mlx->txt.west.img)
			mlx_destroy_image(mlx->mlx, mlx->txt.west.img);
		if (mlx->txt.south.img)
			mlx_destroy_image(mlx->mlx, mlx->txt.south.img);
		if (img->img)
			mlx_destroy_image(mlx->mlx, img->img);
		if (mlx->win)
			mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	free_file(stuff);
	exit(0);
}
