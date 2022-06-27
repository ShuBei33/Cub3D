/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:09:54 by estoffel          #+#    #+#             */
/*   Updated: 2022/06/24 00:38:16 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// needs to be fixed

static int	releasing(void *ptr)
{
	if (*(void **)ptr)
	{
		free(*(void **)ptr);
		*(void **)ptr = NULL;
		return (0);
	}
	return (-1);
}

static char	**ft_nomalloc(char **output, size_t i)
{
	while (i > 0)
	{
		--i;
		free(output[i]);
	}
	releasing(&output);
	return (NULL);
}

static size_t	count_word(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s && s[i])
	{
		while (s[i] && s[i] == c)
		{
			++count;
			++i;
		}
	}
	return (count);
}

static size_t	count_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	if (*s && *s == c)
		return (1);
	while (*s && *s != c)
	{
		++len;
		++s;
	}
	return (len);
}

char	**ft_only_split(char const *s, char c)
{
	char	**output;
	char	*minitab;
	size_t	count_w;
	size_t	cnt_len;
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
		cnt_len = count_len(s, c);
		minitab = ft_strndup(s, cnt_len);
		if (!minitab)
			return (ft_nomalloc(output, i));
		output[i++] = minitab;
		s += (cnt_len + 1);
	}
	output[i] = '\0';
	return (output);
}