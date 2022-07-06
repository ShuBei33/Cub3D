/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onlysplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:14:59 by estoffel          #+#    #+#             */
/*   Updated: 2022/07/05 07:25:59 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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

char	**ft_onlysplit(char const *s, char c)
{
	char	**output;
	char	*minitab;
	int		count_w;
	int		cnt_l;
	int		i;

	if (!s)
		return (NULL);
	count_w = count_word(s, c);
	output = malloc(sizeof(char *) * (count_w + 1));
	if (!output)
		return (NULL);
	i = 0;
	while (i < count_w)
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
