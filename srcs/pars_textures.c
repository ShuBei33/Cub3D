/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:41:57 by estoffel          #+#    #+#             */
/*   Updated: 2022/07/28 06:24:24 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	parse_clr(int *rgb, char *path, int i, int j)
{
	char	**nbr;

	if (count_arg(path, ',') != 3)
		return (E_LOAD_CLR);
	nbr = ft_split(path, ',');
	if (!nbr)
		return (E_MLC_ERR);
	while (nbr[i] && nbr[i][j])
	{
		j = 0;
		if ((is_full_digit(nbr[i]) != 0 || ft_isspace(nbr[i][j++]) != 0)
			|| ft_strlen(nbr[i]) > 11)
			return (freetab(nbr), E_CHAR_PATT);
		if (ft_atoi(nbr[i]) > 255 || ft_atoi(nbr[i]) < 0)
			return (freetab(nbr), E_CHAR_PATT);
		++i;
	}
	*rgb = create_trgb(0, ft_atoi(nbr[0]), ft_atoi(nbr[1]), ft_atoi(nbr[2]));
	freetab(nbr);
	return (EXIT_SUCCESS);
}

int	load_stuff(t_stuff *stuff, char *path, char *name)
{
	if (ft_strcmp(name, "NO") == 0)
		load_no(stuff, path);
	else if (ft_strcmp(name, "SO") == 0)
		load_so(stuff, path);
	else if (ft_strcmp(name, "WE") == 0)
		load_we(stuff, path);
	else if (ft_strcmp(name, "EA") == 0)
		load_ea(stuff, path);
	else if (ft_strcmp(name, "F") == 0)
	{
		stuff->f_cnt++;
		parse_clr(&stuff->f_rgb, path, 0, 0);
	}
	else if (ft_strcmp(name, "C") == 0)
	{
		stuff->c_cnt++;
		parse_clr(&stuff->c_rgb, path, 0, 0);
	}
	else
		return (E_CHAR_PATT);
	return (EXIT_SUCCESS);
}

int	parse_txtr(t_stuff *stuff, char *linetxtr, char *name)
{
	int const	len = ft_strlen(name);

	linetxtr += len;
	if ((*linetxtr < 9 || *linetxtr > 13)
		&& (*linetxtr != ' '))
		return (E_CHAR_PATT);
	while (ft_isspace(*linetxtr) != 0)
		linetxtr++;
	if (*linetxtr == 0)
		return (E_CHAR_PATT);
	return (load_stuff(stuff, linetxtr, name));
}
