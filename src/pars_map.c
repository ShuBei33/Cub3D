/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 05:14:15 by estoffel          #+#    #+#             */
/*   Updated: 2022/06/26 02:51:38 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_split(t_data *data)
{
	int	j;

	j = 0;
	if (data->file[i] && data->file[i + 1])
	{
		if (data->file[i][j] == '\n' && data->file[i + 1][j] == '\n')
			return (E_INV_SHP);
	}
	return(EXIT_SUCCESS);
}

int	go_to_map(t_data *data, char *line)
{
	int	i;
	int	len;

	i = 0;
	while (line[i])
	{
		if (!check_char_str(line[i]))
		{
			if (check_if_map(line))
			{
				len = ft_strclen(line[i], '\n');
				i += len + 2;
			}
			else
			{
				len = ft_strclen(line[i], '\n');
				i += len + 3;
				if (line[i] == '\n')
					return (E_INV_SHP);
			}
		}
	}
	return (EXIT_SUCCESS);
}

int	check_char(t_data *data)
{
	int j;

	j = 0;
	while (data->file[data->i][j] && data->file[data->i][j] != '\n')
	{
		if (data->file[data->i][j] != '1' && data->file[data->i][j] != '0' && data->file[data->i][j] != 'N'
			&& data->file[data->i][j] != 'S' && data->file[data->i][j] != 'W' && data->file[data->i][j] != 'E'
			&& data->file[data->i][j] != ' ' && data->file[data->i][j] != '\n')
			return (E_CHAR_PATT);
		++j;
	}
	return (EXIT_SUCCESS);
}

int	parse_map(t_data *data)
{
	int		j;
	int		tmp;
	char	*maxline;

	j = 0;
	while (data->file[data->i] && data->file[data->i][j] == '\n')
		++data->i;
	if (data->file[data->i][j] == '\0')
		return (E_NO_DATA);
	tmp = data->i;
	while (data->file[data->i])
	{
		if (check_char(data))
			return (E_CHAR_PATT);
		if (check_split(data))
			return (E_INV_SHP);
		++data->i;
	}
	data->i = tmp;
	while (data->file[data->i] && data->file[data->i + 1])
	{
		maxline = ft_strclencmp(data->file[data->i], data->file[data->i + 1], '\n');
		data->maxlen = ft_strclen(maxline, '\n');
		data->nb_line++;
		data->i++;
	}
	return (EXIT_SUCCESS);
}
