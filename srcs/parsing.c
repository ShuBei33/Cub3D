/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:01:38 by estoffel          #+#    #+#             */
/*   Updated: 2022/07/11 01:52:31 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_nb_content(t_stuff *stuff)
{
	if (stuff->no_txtr.cnt != 1 || stuff->so_txtr.cnt != 1
		|| stuff->we_txtr.cnt != 1 || stuff->ea_txtr.cnt != 1
		|| stuff->c_cnt != 1 || stuff->f_cnt != 1)
		return (E_CLONE);
	return (EXIT_SUCCESS);
}

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

int	check_err(t_stuff *stuff, char **av)
{
	int	id;

	if (check_extension(av) != 0)
		return (E_INV_FMT);
	id = get_file(stuff, av[1]);
	if (id != 0)
		return (id);
	return (EXIT_SUCCESS);
}
