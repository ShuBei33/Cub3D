/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:01:38 by estoffel          #+#    #+#             */
/*   Updated: 2022/07/06 17:26:36 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_extension(char **av)
{
	size_t	len;

	len = ft_strlen(av[1]);
	if (len < 5)
		return (E_INV_FMT);
	if ((ft_strncmp(".cub", &av[1][len - 4], 4) != 0)
		|| av[1][len - 5] == '.' || av[1][len - 5] == '/'
		|| av[1][len] != '\0')
		return (E_INV_FMT);
	return (EXIT_SUCCESS);
}

int	check_err(t_data *data, char **av)
{
	int	id;

	if (check_extension(av) != 0)
		return (E_INV_FMT);
	id = get_file(data, av[1]);
	printf("ret = %d\n", id);
	if (id != 0)
		return (id);
	return (EXIT_SUCCESS);
}
