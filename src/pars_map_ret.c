/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_ret.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 02:04:59 by estoffel          #+#    #+#             */
/*   Updated: 2022/06/26 02:31:34 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_if_map(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strclen(s, '\n');
	while (i < len)
	{
		if (check_char_str(s[i]))
			return (E_CHAR_PATT);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_ret()