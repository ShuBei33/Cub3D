/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:28:32 by estoffel          #+#    #+#             */
/*   Updated: 2022/05/20 01:27:06 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

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

char	*read_map(char *av)
{
	int		fd;
	ssize_t	bytes_read;
	char	buf[BUFFER_SIZE + 1];
	char	*line;

	buf[0] = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (0);
	bytes_read = 1;
	line = NULL;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		buf[bytes_read] = '\0';
		if (ft_isprint(buf[bytes_read]) == 0)
			return (NULL);
		av = line;
		line = ft_strjoin(line, buf);
		free(av);
	}
	close(fd);
	if (bytes_read == -1)
		return (free(line), NULL);
	return (line);
}

int	get_map(t_data *data, char *av)
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
		if (line[i] == '\n')
		{
			if (line[i + 1] == '\n')
			{
				data->map = NULL;
				free(line);
				return (E_INV_SHP);
			}
		}
		++i;
	}
	data->map = ft_split(line, '\n');
	return (free(line), EXIT_SUCCESS);
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
			&& line[i] != ' ' && line[i] != '\n')
			return (free(line), E_CHAR_PATT);
		++i;
	}
	free(line);
	return (EXIT_SUCCESS);
}

int	check_err(t_data *data, char *av)
{
	int	id;

	if (check_extension(&av) != 0)
		return (E_INV_FMT);
	id = get_map(data, av);
	if (id != 0)
		return (id);
	id = check_char(data, av);
	if (id != 0)
		return (id);
	if (!data->map)
		return (E_INIT_MAP);
	return (EXIT_SUCCESS);
}
