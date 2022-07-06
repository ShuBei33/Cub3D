/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:28:32 by estoffel          #+#    #+#             */
/*   Updated: 2022/07/06 19:15:47 by estoffel         ###   ########.fr       */
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
			return (E_CHAR_PATT);
		++i;
	}
	return (EXIT_SUCCESS);
}

char	*read_file(char *av)
{
	int		fd;
	ssize_t	bytes_read;
	char	buf[BUFFER_SIZE + 1];
	char	*line;

	buf[0] = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (print_err(E_OP_F), NULL);
	bytes_read = 1;
	line = NULL;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (!bytes_read || bytes_read == -1 || bytes_read > 10000)
			break ;
		buf[bytes_read] = '\0';
		if (checknprint(buf) != 0)
			return (NULL);
		av = line;
		line = ft_strjoin(line, buf);
		free(av);
	}
	(bytes_read == -1) && release(&line);
	return (close(fd), line);
}

int	check_file(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->no_txtr.img == NULL || data->so_txtr.img == NULL
			|| data->we_txtr.img == NULL || data->ea_txtr.img == NULL
			|| data->f_rgb == -1 || data->c_rgb == -1)
	{
		j = 0;
		while (data->file[i][j] == '\n')
			++i;
		while (data->file[i][j] != '\n' && ft_isspace(data->file[i][j]) != 0)
			++j;
		if (!ft_strncmp(data->file[i], "NO", 2))
			parse_txtr(data, data->file[i], "NO");
		else if (!ft_strncmp(data->file[i], "SO", 2))
			parse_txtr(data, data->file[i], "SO");
		else if (!ft_strncmp(data->file[i], "WE", 2))
			parse_txtr(data, data->file[i], "WE");
		else if (!ft_strncmp(data->file[i], "EA", 2))
			parse_txtr(data, data->file[i], "EA");
		else if (!ft_strncmp(data->file[i], "F", 1))
			parse_txtr(data, data->file[i], "F");
		else if (!ft_strncmp(data->file[i], "C", 1))
			parse_txtr(data, data->file[i], "C");
		else
			return (E_CHAR_PATT);
		i++;
	}
	data->i = i + 1;
	return (EXIT_SUCCESS);
}

int	get_file(t_data *data, char *av)
{
	char	*line;

	line = read_file(av);
	if (!line)
		return (release(&line), E_INIT_MAP);
	data->file = ft_onlysplit(data, line, '\n');
	if (!data->file)
		return (free_data(data), free(line), E_MLC_ERR);
	release(&line);
	if (check_file(data))
		return (E_CHAR_PATT);
	return (parse_map(data));
}
