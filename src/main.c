/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:38:05 by estoffel          #+#    #+#             */
/*   Updated: 2022/07/05 10:17:11 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include <stdio.h>

void	init_struct(t_data *data)
{
	ft_memset(data, 0, sizeof(*data));
}

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		if (data->map)
			free_map(data);
		if (data->file)
			free_file(data);
		return (E_INIT_MLX);
	}
	data->win = mlx_new_window(data->mlx, WIDTH,
			HEIGHT, "Cub3D");
	return (EXIT_SUCCESS);
}

int	check_mlx(t_data *data)
{
	if (!data->mlx || !data->win)
		return (E_INIT_MLX);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		ret;

	init_struct(&data);
	if (ac != 2)
		return (ft_putstr_fd("Error\nWrong number of arguments\n", 2), -1);
	// if (init_mlx(&data))
	// 	return (print_err(E_INIT_MLX), -1);
	// print_struct(&data);
	ret = check_err(&data, av);
	if (ret)
		return (print_err(ret), free_map(&data), -1);
	// if (check_mlx(&data) != 0)
	// 	clean_mlx(&data);
	// mlx_hook(data.win, CLOSE, 0, &destroy_mlx, &data);
	// mlx_loop(data.mlx);
	// print_map(&data);
	return (0);
}
