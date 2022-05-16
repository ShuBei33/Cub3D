/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:26:28 by estoffel          #+#    #+#             */
/*   Updated: 2021/06/26 20:43:45 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *fats, const char *s, size_t len)
{
	size_t	s_len;
	size_t	f_len;
	int		ret_cmp;

	if (*s == '\0')
		return ((char *)fats);
	s_len = ft_strlen(s);
	f_len = ft_strlen(fats);
	if (len > f_len)
		len = f_len;
	if (s_len > len)
		return (NULL);
	while (*fats && (len >= s_len))
	{
		ret_cmp = ft_strncmp(fats, s, s_len);
		if (ret_cmp == 0)
			return ((char *)fats);
		++fats;
		--len;
	}
	return (NULL);
}
