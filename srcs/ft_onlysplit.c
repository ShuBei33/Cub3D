/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onlysplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:14:59 by estoffel          #+#    #+#             */
/*   Updated: 2022/07/10 19:26:10 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	released(void *ptr)
{
	if (*(void **)ptr)
	{
		free(*(void **)ptr);
		*(void **)ptr = NULL;
		return (0);
	}
	return (-1);
}

static char	**ft_nomalloc(char **output, int i)
{
	while (i > 0)
	{
		--i;
		free(output[i]);
	}
	released(&output);
	return (NULL);
}

static int	count_word(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			++count;
		++i;
	}
	if (s[i - 1] != '\n')
		++count;
	return (count);
}

static int	count_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		++len;
		++s;
	}
	return (len);
}

char	**ft_onlysplit(t_stuff *stuff, char const *s, char c)
{
	char	**output;
	char	*minitab;
	int		cnt_l;
	int		i;

	if (!s)
		return (NULL);
	stuff->file_line = count_word(s, c);
	output = malloc(sizeof(char *) * (stuff->file_line + 1));
	if (!output)
		return (NULL);
	i = 0;
	while (i < stuff->file_line)
	{
		cnt_l = count_len(s, c);
		minitab = ft_strndup(s, cnt_l);
		if (!minitab)
			return (ft_nomalloc(output, i));
		output[i++] = minitab;
		s += cnt_l + 1;
	}
	output[i] = NULL;
	return (output);
}
