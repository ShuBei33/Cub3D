/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 19:24:20 by estoffel          #+#    #+#             */
/*   Updated: 2021/07/29 18:13:15 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_nomalloc(char **output, size_t i)
{
	while (i > 0)
	{
		--i;
		free(output[i]);
	}
	free(output);
	return (NULL);
}

static size_t	count_word(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] && s[i] == c)
		++i;
	while (s[i])
	{
		++count;
		while (s[i] && s[i] != c)
			++i;
		while (s[i] && s[i] == c)
			++i;
	}
	return (count);
}

static size_t	count_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		++len;
		++s;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	char	*minitab;
	size_t	count_w;
	size_t	i;

	if (!s)
		return (NULL);
	count_w = count_word(s, c);
	output = malloc(sizeof(char *) * (count_w + 1));
	if (!output)
		return (NULL);
	i = 0;
	while (i < count_w)
	{
		while (*s && *s == c)
			++s;
		minitab = ft_strndup(s, count_len(s, c));
		if (!minitab)
			return (ft_nomalloc(output, i));
		output[i++] = minitab;
		while (*s && *s != c)
			++s;
	}
	output[i] = NULL;
	return (output);
}
