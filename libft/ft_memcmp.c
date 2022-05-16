/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:15:13 by estoffel          #+#    #+#             */
/*   Updated: 2021/07/29 18:11:46 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	if (n == 0 || s1 == s2)
		return (0);
	i = 0;
	str1 = s1;
	str2 = s2;
	while (i < n)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		++i;
		++str1;
		++str2;
	}
	return (0);
}
