/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:25:16 by estoffel          #+#    #+#             */
/*   Updated: 2021/07/28 19:25:55 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *s1, size_t n)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	len = ft_strlen(s1);
	if (len < n)
		ptr = malloc(sizeof(char) * (len + 1));
	else
		ptr = malloc(sizeof(char) * (n + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < n && s1[i])
	{
		ptr[i] = s1[i];
		++i;
	}
	ptr[i] = 0;
	return (ptr);
}
