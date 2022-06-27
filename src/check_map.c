/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:28:32 by estoffel          #+#    #+#             */
/*   Updated: 2022/06/25 23:26:01 by estoffel         ###   ########.fr       */
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

char	*read_file(char *av)
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
		if (!bytes_read || bytes_read == -1)
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

int	get_file(t_data *data, char *av)
{
	char	*line;
	int		ret;

	line = read_file(av);
	if (!line)
		return (release(&line), E_INIT_MAP);
	ret = go_to_map(data, line);
	if (ret != 0)
		return (print_err(ret));
	data->file = ft_split(line, '\n');
	// for (int k = 0; data->file[k]; k++)
	// 	printf("%s\n", data->file[k]);
	// printf("\n");
	if (!data->file)
		return (free_data(data), free(line), E_MLC_ERR);
	free(line);
	ret = check_file(data);
	if (ret < 0)
		return (ret);
	return (parse_map(data));
}
