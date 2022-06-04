/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:01:38 by estoffel          #+#    #+#             */
/*   Updated: 2022/06/04 00:41:51 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

//verif map en last, inv char, pos player, flood fill
int	check_err(t_data *data, char **av)
{
	int	id;

	if (check_extension(av) != 0)
		return (E_INV_FMT);
	id = get_map(data, av[1]);
	if (id != 0)
		return (id);
	// id = check_char(data, av[1]);
	// if (id != 0)
	// 	return (id);
	// if (!data->map)
	// 	return (E_INIT_MAP);
	// if (p_count(data) != 0)
	// 	return (E_CHAR_PATT);
	return (EXIT_SUCCESS);
}

int	check_file(t_data *data, char *line)
{
	int	id;
	int	i;

	i = 0;
	line = line + ft_strclen(line, '\n');
	id = parse_txtr(data, "NO");
	if (id != 0)
		return (id);
	return (EXIT_SUCCESS);
}
