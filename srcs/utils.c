/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:36:28 by estoffel          #+#    #+#             */
/*   Updated: 2022/07/11 03:08:19 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
#include <stdio.h>

int	check_char(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
	{
		if (s[i] != '1' && s[i] != '0' && s[i] != 'N'
			&& s[i] != 'S' && s[i] != 'W' && s[i] != 'E'
			&& !ft_isspace(s[i]))
			return (E_CHAR_PATT);
		++i;
	}
	return (EXIT_SUCCESS);
}

int	ft_strclen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		++i;
	return (i);
}

int	is_full_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (E_CHAR_PATT);
		++i;
	}
	return (EXIT_SUCCESS);
}

int	is_full_digit(char *str)
{
	int		i;
	char	*st;

	st = ft_strtrim(str, " \t");
	i = 0;
	while (st[i])
	{
		if (ft_isdigit(st[i]) == 0)
		{
			free(st);
			return (E_CHAR_PATT);
		}
		++i;
	}
	free(st);
	return (EXIT_SUCCESS);
}

int	count_arg(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		++count;
		while (s[i] && s[i] != c)
			++i;
		while (s[i] && s[i] == c)
			++i;
	}
	return (count);
}
