/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:28:32 by estoffel          #+#    #+#             */
/*   Updated: 2022/05/20 22:03:12 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	checknprint(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (!ft_isprint(buf[i]) && buf[i] != '\n')
			return (EXIT_FAILURE);
		++i;
	}
	return (EXIT_SUCCESS);
}

int	line_len(t_data *data, char *av)
{
	char	*line;
	int		len;
	int		i;

	line = read_map(av);
	if (!line)
		return (0);
	len = 0;
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		++len;
		++i;
	}
	data->max_linelen = len;
	free(line);
	return (len);
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
		if (checknprint(buf))
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
		return (free(line), E_INIT_MAP);
	}
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			if (line[i + 1] == '\n')
			{
				data->map = NULL;
				return (free(line), E_INV_SHP);
			}
		}
		++i;
	}
	data->map = ft_split(line, '\n');
	return (free(line), EXIT_SUCCESS);
}
