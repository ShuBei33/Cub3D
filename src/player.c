/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:22:44 by estoffel          #+#    #+#             */
/*   Updated: 2022/05/20 22:03:43 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	p_count(t_data *data)
{
	int		i;
	int		j;
	int		p_count;

	p_count = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				++p_count;
				data->pos_p_x = i;
				data->pos_p_y = j;
			}
			++j;
		}
		++i;
	}
	if (p_count != 1)
		return (E_CHAR_PATT);
	return (EXIT_SUCCESS);
}
