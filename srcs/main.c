/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:43:52 by lzaccome          #+#    #+#             */
/*   Updated: 2022/07/10 23:45:55 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_struct(t_stuff *stuff)
{
	ft_memset(stuff, 0, sizeof(*stuff));
	stuff->f_rgb = -1;
	stuff->c_rgb = -1;
}

int	main(int ac, char **av)
{
	t_stuff	stuff;
	int		ret;

	init_struct(&stuff);
	if (ac != 2)
		return (ft_putstr_fd("Error\nWrong number of arguments\n", 2), -1);
	ret = check_err(&stuff, av);
	if (ret)
		return (print_err(ret), free_file(&stuff), -1);
	mini_map(stuff.map, stuff);
	free_file(&stuff);
	return (0);
}
