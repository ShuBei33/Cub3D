/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:38:05 by estoffel          #+#    #+#             */
/*   Updated: 2022/05/16 19:36:07 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include <stdio.h>

void	init_struct(t_data *data)
{
	
}

int	main(int ac, char **av)
{
	t_data	data;

	init_struct(&data);
	if (ac != 2)
	{
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
		return (0);
	}
}
