/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:38:05 by estoffel          #+#    #+#             */
/*   Updated: 2022/05/20 01:27:30 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include <stdio.h>

void	init_struct(t_data *data)
{
	ft_memset(data, 0, sizeof(*data));
}

int	main(int ac, char **av)
{
	t_data	data;
	int		ret;

	init_struct(&data);
	if (ac != 2)
	{
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
		return (0);
	}
	ret = check_err(&data, av[1]);
	if (ret != 0)
	{
		print_err(ret);
		return (free_map(&data), EXIT_FAILURE);
	}
	// init_mlx(&data);
	return (0);
}
