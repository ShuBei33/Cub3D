/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:36:38 by estoffel          #+#    #+#             */
/*   Updated: 2022/05/17 18:14:33 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map && data->map[i])
		free(data->map[i++]);
	free(data->map);
}

void	free_data(t_data *data)
{
	free(data->win);
	free(data->mlx);
	free_map(data);
}

/*void	free_image(t_data *data)
{
	free(data->wall);
	free(data->ground);
	free(data->player);
	free(data->collect);
	free(data->exit);
}

int	clean_mlx(t_data *data)
{
	if (data->wall != NULL)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->player != NULL)
		mlx_destroy_image(data->mlx, data->player);
	if (data->collect != NULL)
		mlx_destroy_image(data->mlx, data->collect);
	if (data->exit != NULL)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->ground != NULL)
		mlx_destroy_image(data->mlx, data->ground);
	if (data->win == NULL)
		free(data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data);
	ft_putstr_fd("Error: Oups, something went wrong with Images\n", 2);
	exit (EXIT_FAILURE);
}

int	destroy_mlx(t_data *data)
{
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->collect);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->ground);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data);
	exit (EXIT_SUCCESS);
}*/
