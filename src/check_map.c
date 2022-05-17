/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:28:32 by estoffel          #+#    #+#             */
/*   Updated: 2022/05/17 18:24:01 by estoffel         ###   ########.fr       */
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
		av = line;
		line = ft_strjoin(line, buf);
		free(av);
	}
	close(fd);
	if (bytes_read == -1)
		return (free(line), NULL);
	return (line);
}

void	get_map(t_data *data, char *av)
{
	char	*line;
	int		i;

	line = read_map(av);
	if (!line)
	{
		data->map = NULL;
		return ;
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
				return ;
			}
		}
		++i;
	}
	data->map = ft_split(line, '\n');
	free(line);
}


