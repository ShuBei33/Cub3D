/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 05:14:15 by estoffel          #+#    #+#             */
/*   Updated: 2022/07/12 11:57:39 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_player(t_stuff *stuff)
{
	int	i;
	int	j;

	i = stuff->i;
	while (stuff->file[i] && ft_strlen(stuff->file[i]) != 0)
	{
		j = 0;
		while (stuff->file[i][j])
		{
			if (stuff->file[i][j] == 'N' || stuff->file[i][j] == 'S'
				|| stuff->file[i][j] == 'W' || stuff->file[i][j] == 'E')
			{
				++stuff->p_cnt;
				stuff->py = i - stuff->i;
				stuff->px = j;
				stuff->start_angle = stuff->file[i][j];
			}
			++j;
		}
		++i;
	}
	if (stuff->p_cnt != 1)
		return (E_SPAWN_ERR);
	return (create_nmap(stuff));
}

int	ft_maxlen(t_stuff *stuff)
{
	int	i;

	i = stuff->i + 1;
	stuff->line_len = ft_strlen(stuff->file[i]);
	while (stuff->file[i + 1] && ft_strlen(stuff->file[i]) != 0)
	{
		if (ft_strlen(stuff->file[i + 1]) >= stuff->line_len)
			stuff->line_len = ft_strlen(stuff->file[i + 1]);
		i++;
	}
	return (ft_player(stuff));
}

int	check_spaces(t_stuff *stuff)
{
	int	i;

	i = stuff->i;
	while (i < stuff->file_line -1)
	{
		if (stuff->file[i] && stuff->file[i + 1] && ft_strlen(stuff->file[i]))
		{
			if (ft_strlen(stuff->file[i + 1]) && ft_strlen(stuff->file[i - 1]))
			{
				if (!is_full_spaces(stuff->file[i]))
					return (E_INV_SHP);
			}
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	parse_map2(t_stuff *stuff, int i, int j)
{
	while (!ft_strlen(stuff->file[stuff->i])
		|| (ft_isspace(stuff->file[stuff->i][j])
		&& stuff->file[stuff->i][j] != ' '))
	{
		if (stuff->file[stuff->i] == NULL)
			return (E_NO_DATA);
		stuff->i++;
	}
	i = stuff->i;
	stuff->line_count = stuff->file_line - stuff->i;
	while (i < stuff->file_line -1)
	{
		if (stuff->file[i] && stuff->file[i + 1]
			&& ft_strlen(stuff->file[i]) == 0)
		{
			if (ft_strlen(stuff->file[i + 1])
				&& ft_strlen(stuff->file[i - 1]))
				return (E_INV_SHP);
		}
		i++;
	}
	return (0);
}

int	parse_map(t_stuff *stuff, int i, int j)
{
	int	count;

	count = 0;
	if (stuff->file[i + 1])
	{
		parse_map2(stuff, i, j);
		if (check_spaces(stuff))
			return (E_INV_SHP);
	}
	i = stuff->i;
	while (stuff->file[i] && !check_char(stuff->file[i])
		&& ft_strlen(stuff->file[i]) != 0)
	{
		++i;
		++count;
	}
	stuff->line_count = count;
	if (count < 3)
	{
		free_file(stuff);
		print_err(E_INV_SHP);
		exit(1);
	}
	return (ft_maxlen(stuff));
}
