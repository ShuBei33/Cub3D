/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:36:28 by estoffel          #+#    #+#             */
/*   Updated: 2022/06/04 00:58:22 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include <stdio.h>

int	ft_strclen(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i] != c)
		++i;
	return (i);
}

int	is_full_digit(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (E_CHAR_PATT);
		++i;
	}
	return (EXIT_SUCCESS);
}

int	count_arg(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\n')
	{
		++count;
		while (s[i] && s[i] != c)
			++i;
		while (s[i] && s[i] == c)
			++i;
	}
	return (count);
}

void	print_err(enum e_errcode id)
{
	size_t	i;

	i = 0;
	while (i < (sizeof(g_error) / sizeof(*g_error)))
	{
		if (id == g_error[i].id)
		{
			ft_putstr_fd(g_error[i].err_msg, 2);
			break ;
		}
		++i;
	}
}

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
		{
			printf("%s\n", data->map[i]);
			i++;
		}
	}
}
