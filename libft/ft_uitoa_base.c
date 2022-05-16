/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:24:12 by estoffel          #+#    #+#             */
/*   Updated: 2021/09/08 20:24:38 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	uintlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n > 15)
	{
		n = n / 16;
		++len;
	}
	return (len);
}

char	*ft_uitoa_base(unsigned int n, char *base)
{
	char			*output;
	int				len;
	int				base_size;

	len = uintlen(n);
	base_size = ft_strlen(base);
	output = malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	output[len] = '\0';
	if (n == 0)
		output[0] = '0';
	while (n != 0 && len > 0)
	{
		--len;
		output[len] = base[n % base_size];
		n = n / base_size;
	}
	return (output);
}
