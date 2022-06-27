/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:36:38 by estoffel          #+#    #+#             */
/*   Updated: 2022/06/17 18:33:04 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map && data->map[i])
		free(data->map[i++]);
	release(&data->map);
}

void	free_file(t_data *data)
{
	int	i;

	i = 0;
	while (data->file && data->file[i])
		free(data->file[i++]);
	release(&data->file);
}

void	free_data(t_data *data)
{
	release(&data->win);
	release(&data->mlx);
	free_map(data);
	free_file(data);
}

/*void	free_image(t_data *data)
{
	free(data->wall);
	free(data->ground);
	free(data->player);
	free(data->collect);
	free(data->exit);
}*/

int	clean_mlx(t_data *data)
{
	if (data->no_txtr.img != NULL)
		mlx_destroy_image(data->mlx, data->no_txtr.img);
	if (data->so_txtr.img != NULL)
		mlx_destroy_image(data->mlx, data->so_txtr.img);
	if (data->we_txtr.img != NULL)
		mlx_destroy_image(data->mlx, data->we_txtr.img);
	if (data->ea_txtr.img != NULL)
		mlx_destroy_image(data->mlx, data->ea_txtr.img);
	if (data->win == NULL)
		free(data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data);
	print_err(E_INIT_MLX);
	exit (EXIT_FAILURE);
}

int	destroy_mlx(t_data *data)
{
	// mlx_destroy_image(data->mlx, data->no_txtr.img);
	// mlx_destroy_image(data->mlx, data->so_txtr.img);
	// mlx_destroy_image(data->mlx, data->we_txtr.img);
	// mlx_destroy_image(data->mlx, data->ea_txtr.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	release(&data->mlx);
	free_map(data);
	exit (EXIT_SUCCESS);
}
