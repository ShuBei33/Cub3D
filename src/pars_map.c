/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 05:14:15 by estoffel          #+#    #+#             */
/*   Updated: 2022/07/06 18:43:56 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_split(t_data *data)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	if (data->file[i] && data->file[i + 1])
	{
		if (data->file[i][j] == '\n' && data->file[i + 1][j] == '\n')
			return (E_INV_SHP);
	}
	return(EXIT_SUCCESS);
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
	if (data->file[data->i] == NULL)
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
	print_struct(data);
	return (EXIT_SUCCESS);
}
