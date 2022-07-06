/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:36:28 by estoffel          #+#    #+#             */
/*   Updated: 2022/07/06 18:25:30 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include <stdio.h>

int	ft_strclen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		++i;
	return (i);
}

char	*ft_strclencmp(char *s1, char *s2, char c)
{
	if (s1 && s2 && *s1 && *s2)
	{
		if (ft_strclen(s1, c) >= ft_strclen(s2, c))
			return (s1);
		else
			return (s2);
	}
	if (*s1 && !*s2)
		return (s1);
	else
		return (s2);
}

int	is_full_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (E_CHAR_PATT);
		++i;
	}
	printf("succes\n");
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
