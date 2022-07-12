/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:22:34 by estoffel          #+#    #+#             */
/*   Updated: 2022/07/10 21:30:36 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
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

void	print_tab_int(t_stuff *stuff)
{
	int	i;
	int	j;

	i = 0;
	while (i < stuff->line_count)
	{
		j = 0;
		while (j < stuff->line_len)
		{
			printf("%d", stuff->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_map(t_stuff *stuff)
{
	int	i;

	i = 0;
	if (stuff->file)
	{
		while (stuff->file[i])
		{
			printf("%s\n", stuff->file[i]);
			i++;
		}
	}
}

void	print_struct(t_stuff *stuff)
{
	int	i;

	i = 0;
	if (stuff->file)
	{
		printf("stuff->file :\n");
		while (stuff->file[i])
			printf("%s\n", stuff->file[i++]);
	}
	printf("\n");
	printf("\npos player_y : %e\npos player_x : %e\norient player : %c\n",
		stuff->py, stuff->px, stuff->start_angle);
	printf("maxlen : %d\n", stuff->line_len);
	printf("no_txtr.img : %s\n", (char *)(stuff->no_txtr.img));
	printf("so_txtr.img : %s\n", (char *)(stuff->so_txtr.img));
	printf("we_txtr.img : %s\n", (char *)(stuff->we_txtr.img));
	printf("ea_txtr.img : %s\n", (char *)(stuff->ea_txtr.img));
	printf("f_rgb : %d\nc_rgb : %d\n", stuff->f_rgb, stuff->c_rgb);
}
