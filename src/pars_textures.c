/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:41:57 by estoffel          #+#    #+#             */
/*   Updated: 2022/07/06 19:08:38 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	parse_clr(int *rgb, char *path)
{
	char	**nbr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (count_arg(path, ',') != 3)
		return (E_LOAD_CLR);
	nbr = ft_split(path, ',');
	if (!nbr)
		return (free(path), E_MLC_ERR);
	free(path);
	while (nbr[i])
	{
		if (is_full_digit(nbr[i]) != 0)
			return (E_CHAR_PATT);
		if (ft_atoi(nbr[i]) > 255 || ft_atoi(nbr[i]) < 0)
			return (E_CHAR_PATT);
		++i;
	}
	*rgb = create_trgb(0, ft_atoi(nbr[0]), ft_atoi(nbr[1]), ft_atoi(nbr[2]));
	return (EXIT_SUCCESS);
}

int	load_data(t_data *data, char *path, char *name)
{
	if (ft_strcmp(name, "NO") == 0) 
		data->no_txtr.img = path;
	else if (ft_strcmp(name, "SO") == 0)
		data->so_txtr.img = path;
	else if (ft_strcmp(name, "WE") == 0)
		data->we_txtr.img = path;
	else if (ft_strcmp(name, "EA") == 0)
		data->ea_txtr.img = path;
	else if (ft_strcmp(name, "F") == 0)
	{
		parse_clr(&data->f_rgb, path);
	}
	else if (ft_strcmp(name, "C") == 0)
		parse_clr(&data->c_rgb, path);
	else
		return (E_CHAR_PATT);
	if (data->so_txtr.img || data->we_txtr.img || data->ea_txtr.img
		|| data->no_txtr.img || data->f_rgb != -1 || data->c_rgb != -1)
		return (E_CLONE);
	// any_txtr->img = mlx_xpm_file_to_image(data->mlx, name + len,
	// 		&any_txtr->width, &any_txtr->height);
	if (!data->so_txtr.img || !data->we_txtr.img || !data->ea_txtr.img
		|| !data->no_txtr.img || data->f_rgb == -1 || data->c_rgb == -1)
		return (/*clean_mlx(data),*/ E_LOAD_IMG);
	return (EXIT_SUCCESS);
}

int	parse_txtr(t_data *data, char *linetxtr, char *name)
{
	int const	len = ft_strlen(name);

	linetxtr += len;
	// printf("i = %d\n", i);
	if ((*linetxtr < 9 || *linetxtr > 13)
		&& (*linetxtr != ' '))
		return (E_CHAR_PATT);
	while (ft_isspace(*linetxtr) != 0)
		linetxtr++;
	if (*linetxtr == 0)
		return (E_CHAR_PATT);
	// printf("linetxtr = [%s]\n", linetxtr);
	return (load_data(data, linetxtr, name));
}
