/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:37:48 by estoffel          #+#    #+#             */
/*   Updated: 2022/05/20 22:03:24 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_extension(char **av)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(av[1]);
	if (len < 5)
		return (E_INV_FMT);
	if ((ft_strncmp(".cub", &av[1][len - 4], 4) != 0)
		|| av[1][len - 5] == '.' || av[1][len - 5] == '/'
		|| av[1][len] != '\0')
		return (E_INV_FMT);
	return (EXIT_SUCCESS);
}

int	check_char(t_data *data, char *av)
{
	char	*line;
	int		i;

	line = read_map(av);
	if (!line)
	{
		data->map = NULL;
		return (E_INIT_MAP);
	}
	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'W' && line[i] != 'E'
			&& !ft_isspace(line[i]))
			return (free(line), E_CHAR_PATT);
		++i;
	}
	free(line);
	return (EXIT_SUCCESS);
}

int	check_err(t_data *data, char **av)
{
	int	id;

	if (check_extension(av) != 0)
		return (E_INV_FMT);
	id = get_map(data, av[1]);
	if (id != 0)
		return (id);
	id = check_char(data, av[1]);
	if (id != 0)
		return (id);
	if (!data->map)
		return (E_INIT_MAP);
	if (p_count(data) != 0)
		return (E_CHAR_PATT);
	return (EXIT_SUCCESS);
}
