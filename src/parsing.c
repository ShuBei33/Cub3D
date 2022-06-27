/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:01:38 by estoffel          #+#    #+#             */
/*   Updated: 2022/06/22 22:58:34 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_err(t_data *data, char **av)
{
	int	id;

	if (check_extension(av) != 0)
		return (E_INV_FMT);
	id = get_file(data, av[1]);
	if (id != 0)
		return (id);
	return (EXIT_SUCCESS);
}

int	check_file(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	// printf("Try to print full file :\n");
	// for (int k = 0; data->file[k]; k++)
	// 	printf("%s\n", data->file[k]);
	// printf("\n");
	// printf("data->file[i] bf while %s\n", data->file[i]);
	while (data->file[i] && (data->no_txtr.img == NULL
			|| data->so_txtr.img == NULL || data->we_txtr.img == NULL
			|| data->ea_txtr.img == NULL || data->f_rgb == 0
			|| data->c_rgb == 0))
	{
		j = 0;
		while (data->file[i][j] == '\n')
			++i;
		while (data->file[i][j] != '\n' && ft_isspace(data->file[i][j]) != 0)
			++j;
		if (!ft_strncmp(data->file[i], "NO", 2))
			parse_txtr(data, "NO");
		else if (!ft_strncmp(data->file[i], "SO", 2))
			parse_txtr(data, "SO");
		else if (!ft_strncmp(data->file[i], "WE", 2))
			parse_txtr(data, "WE");
		else if (!ft_strncmp(data->file[i], "EA", 2))
			parse_txtr(data, "EA");
		else if (!ft_strncmp(data->file[i], "F", 1))
			parse_txtr(data, "F");
		else if (!ft_strncmp(data->file[i], "C", 1))
			parse_txtr(data, "C");
		else
			return (print_err(E_CHAR_PATT), -1);
		i++;
	}
	data->i = i;
	return (EXIT_SUCCESS);
}
