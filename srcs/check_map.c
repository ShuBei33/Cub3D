/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:28:32 by estoffel          #+#    #+#             */
/*   Updated: 2022/07/11 04:21:40 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
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

int	check_file(t_stuff *stuff, int i)
{
	while (stuff->no_txtr.img == NULL || stuff->so_txtr.img == NULL
		|| stuff->we_txtr.img == NULL || stuff->ea_txtr.img == NULL
		|| stuff->f_rgb == -1 || stuff->c_rgb == -1)
	{
		if (!ft_strncmp(stuff->file[i], "NO", 2))
			parse_txtr(stuff, stuff->file[i], "NO");
		else if (!ft_strncmp(stuff->file[i], "SO", 2))
			parse_txtr(stuff, stuff->file[i], "SO");
		else if (!ft_strncmp(stuff->file[i], "WE", 2))
			parse_txtr(stuff, stuff->file[i], "WE");
		else if (!ft_strncmp(stuff->file[i], "EA", 2))
			parse_txtr(stuff, stuff->file[i], "EA");
		else if (!ft_strncmp(stuff->file[i], "F", 1))
			parse_txtr(stuff, stuff->file[i], "F");
		else if (!ft_strncmp(stuff->file[i], "C", 1))
			parse_txtr(stuff, stuff->file[i], "C");
		else if (ft_strlen(stuff->file[i]) != 0 && !ft_isspace(stuff->file[i][0]
			&& !check_char(stuff->file[i])))
			return (E_CHAR_PATT);
		i++;
	}
	stuff->i = i;
	if (check_nb_content(stuff))
		return (E_CLONE);
	return (EXIT_SUCCESS);
}

int	checking_char(t_stuff *stuff)
{
	int	i;

	i = stuff->i;
	while (i < stuff->file_line)
	{
		if (check_char(stuff->file[i]))
			return (E_CHAR_PATT);
		++i;
	}
	return (EXIT_SUCCESS);
}

int	get_file(t_stuff *stuff, char *av)
{
	char	*line;
	int		ret;

	line = read_file(av);
	if (!line)
		return (release(&line), E_INIT_MAP);
	stuff->file = ft_onlysplit(stuff, line, '\n');
	if (!stuff->file)
		return (free(line), E_MLC_ERR);
	release(&line);
	ret = check_file(stuff, 0);
	if (ret)
		return (ret);
	if (stuff->file[stuff->i] == NULL)
		return (free(line), E_NO_DATA);
	else if (checking_char(stuff))
		return (E_CHAR_PATT);
	return (parse_map(stuff, 0, 0));
}
