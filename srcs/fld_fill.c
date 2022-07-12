/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fld_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:38:05 by estoffel          #+#    #+#             */
/*   Updated: 2022/07/12 11:45:11 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_fail(t_stuff *stuff, int y, int x)
{
	if (y <= 0 || y >= stuff->line_count - 1
		|| x <= 0 || x >= stuff->line_len - 1)
		return (E_OPEN_MAP);
	if (y == 0 && stuff->map[y][x] == 2)
		return (E_OPEN_MAP);
	if (x == 0 && stuff->map[y][x] == 2)
		return (E_OPEN_MAP);
	if (stuff->map[y][x] == 3)
		return (E_OPEN_MAP);
	return (EXIT_SUCCESS);
}

int	flood_fill(t_stuff *stuff, int y, int x, int new_case)
{
	if ((stuff->map[y][x] == new_case) || (stuff->map[y][x] == 1))
		return (EXIT_SUCCESS);
	else if (check_fail(stuff, y, x))
		return (E_OPEN_MAP);
	else if (stuff->file[y + stuff->i][x])
	{
		stuff->map[y][x] = new_case;
		if (flood_fill(stuff, y + 1, x, new_case))
			return (E_OPEN_MAP);
		if (flood_fill(stuff, y - 1, x, new_case))
			return (E_OPEN_MAP);
		if (flood_fill(stuff, y, x + 1, new_case))
			return (E_OPEN_MAP);
		if (flood_fill(stuff, y, x - 1, new_case))
			return (E_OPEN_MAP);
	}
	return (EXIT_SUCCESS);
}

int	set_filter(t_stuff *stuff)
{
	int	i;
	int	j;
	int	k;
	int	ret;

	i = stuff->i;
	k = 0;
	while (k < stuff->line_count)
	{
		j = 0;
		while (stuff->file[i] && stuff->file[i][j])
		{
			if (stuff->file[i][j] == '0' || stuff->file[i][j] == 'N'
				|| stuff->file[i][j] == 'S' || stuff->file[i][j] == 'W'
				|| stuff->file[i][j] == 'E')
				stuff->map[k][j] = 2;
			else if (stuff->file[i][j] == '1')
					stuff->map[k][j] = 1;
			++j;
		}
		++i;
		++k;
	}
	ret = flood_fill(stuff, stuff->py, stuff->px, 0);
	return (ret);
}

int	fill_one(t_stuff *stuff)
{
	int	i;
	int	j;

	i = 0;
	while (i < stuff->line_count)
	{
		j = 0;
		while (j < stuff->line_len)
		{
			stuff->map[i][j] = 3;
			++j;
		}
		++i;
	}
	return (set_filter(stuff));
}

int	create_nmap(t_stuff *stuff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	stuff->map = (int **)malloc(sizeof(int *) * stuff->file_line);
	if (!stuff->map)
		return (E_MLC_ERR);
	while (i < stuff->line_count)
	{
		stuff->map[i] = (int *)malloc(sizeof(int) * stuff->line_len);
		if (!stuff->map[i])
			return (E_MLC_ERR);
		++i;
	}
	if (stuff->line_count >= WINDOW_HEIGHT / 32
		|| stuff->line_len >= WINDOW_WIDTH / 32)
		return (free_file(stuff), E_BIG_MAP);
	return (fill_one(stuff));
}
