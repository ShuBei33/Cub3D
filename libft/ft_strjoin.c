/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:42:11 by estoffel          #+#    #+#             */
/*   Updated: 2022/02/16 08:08:49 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	size_t	len;
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len = 0;
	if (s1 != NULL)
		len = ft_strlen(s1);
	if (s2 != NULL)
		len = len + ft_strlen(s2);
	output = malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	i = 0;
	while (s1 && *s1)
		output[i++] = *s1++;
	while (s2 && *s2)
		output[i++] = *s2++;
	output[i] = '\0';
	return (output);
}
