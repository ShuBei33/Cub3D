/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:36:28 by estoffel          #+#    #+#             */
/*   Updated: 2022/05/20 22:00:34 by estoffel         ###   ########.fr       */
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
	while (data->map && data->map[i])
	{
		printf("%s\n", data->map[i]);
		i++;
	}
}
