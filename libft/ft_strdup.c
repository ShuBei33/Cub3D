/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 18:10:21 by estoffel          #+#    #+#             */
/*   Updated: 2021/07/29 18:12:48 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;
	char	*ptr_cpy;

	len = ft_strlen(s1);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr_cpy = ptr;
	while (*s1)
	{
		*ptr_cpy = *s1;
		++s1;
		++ptr_cpy;
	}
	*ptr_cpy = '\0';
	return (ptr);
}
