/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:22:34 by estoffel          #+#    #+#             */
/*   Updated: 2022/06/21 18:05:49 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include <stdio.h>

void	print_err(enum e_errcode id)
{
	size_t	i;

	i = 0;
	while (i < (sizeof(g_error) / sizeof(*g_error)))
	{
		if (id == g_error[i].id)
		{
			ft_putstr_fd(g_error[i].err_msg, 2);
			break ;
		}
		++i;
	}
}

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
		{
			printf("%s\n", data->map[i]);
			i++;
		}
	}
}

void	print_struct(t_data *data)
{
	int	i;

	i = 0;
	if (data->file)
	{
		printf("data->file :\n");
		while (data->file[i])
			printf("%s\n", data->file[i++]);
	}
	printf("\n");
	i = 0;
	if (data->map)
	{
		printf("data->map :\n");
		while (data->map[i])
			printf("%s\n", data->map[i++]);
	}
	printf("\npos player_x : %e\npos player_y : %e\norient player : %e\n",
		data->pos_p_x, data->pos_p_y, data->orient_p);
	printf("maxlen : %d\n", data->maxlen);
	printf("no_txtr.img : %s\n", (char *)(data->no_txtr.img));
	printf("so_txtr.img : %s\n", (char *)(data->so_txtr.img));
	printf("we_txtr.img : %s\n", (char *)(data->we_txtr.img));
	printf("ea_txtr.img : %s\n", (char *)(data->ea_txtr.img));
	printf("f_rgb : %d\nc_rgb : %d\n", data->f_rgb, data->c_rgb);
}
