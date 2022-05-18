/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:38:05 by estoffel          #+#    #+#             */
/*   Updated: 2022/05/18 00:38:53 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include <stdio.h>

void	init_struct(t_data *data)
{
	data->map = NULL;
	data->mlx = NULL;
	data->win = NULL;
	data->height = 0;
	data->width = 0;
	data->i = 0;
	data->j = 0;
	data->player = 0;
	data->wall = 0;
	data->ground = 0;
	data->pos_p_x = 0;
	data->pos_p_y = 0;
	data->orient_p = 0;
}

int	main(int ac, char **av)
{
	t_data	data;

	(void)av;
	init_struct(&data);
	if (ac != 2)
	{
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
		return (0);
	}
	if (check_err(&data, av[1]) != 0)
		return (free_map(&data), EXIT_FAILURE);
	init_mlx(&data);
}
