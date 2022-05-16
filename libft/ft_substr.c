/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:23:59 by estoffel          #+#    #+#             */
/*   Updated: 2021/07/29 18:13:06 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	slen;
	size_t	i;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len < slen)
		ptr = malloc(sizeof(char) * (len + 1));
	else
		ptr = malloc(sizeof(char) * (slen + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[start] && len)
	{
		ptr[i] = s[start];
		--len;
		++i;
		++start;
	}
	ptr[i] = '\0';
	return (ptr);
}
