/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:36:28 by estoffel          #+#    #+#             */
/*   Updated: 2022/05/19 19:58:27 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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

