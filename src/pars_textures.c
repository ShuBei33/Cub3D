/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:41:57 by estoffel          #+#    #+#             */
/*   Updated: 2022/06/22 17:38:48 by estoffel         ###   ########.fr       */
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
		return (E_MLC_ERR);
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

int	load_data(t_data *data, char *name, int len)
{
	t_txtr	*any_txtr;
	int i;

	// printf("name = %s\n", name);
	if ((i = ft_strncmp("NO", name, len)) == 0) {
		any_txtr = &data->no_txtr;
	}
	else if (ft_strncmp("SO", name, len) == 0)
		any_txtr = &data->so_txtr;
	else if (ft_strncmp("WE", name, len) == 0)
		any_txtr = &data->we_txtr;
	else if (ft_strncmp("EA", name, len) == 0)
		any_txtr = &data->ea_txtr;
	else if (ft_strncmp("F", name, len) == 0)
		return (parse_clr(&data->f_rgb, name + len));
	else if (ft_strncmp("C", name, len) == 0)
		return (parse_clr(&data->c_rgb, name + len));
	else
		return (E_CHAR_PATT);
	// printf("pars txt reusit\n");
	if (any_txtr->img)
		return (E_CLONE);
	// printf("if bizard passe\n");
	// any_txtr->img = mlx_xpm_file_to_image(data->mlx, name + len,
	// 		&any_txtr->width, &any_txtr->height);
	// if (!any_txtr->img)
	// 	return (clean_mlx(data), E_LOAD_IMG);
	return (EXIT_SUCCESS);
}

int	parse_txtr(t_data *data, char *name)
{
	int			i;
	int			j;
	int const	len = ft_strlen(name);

	i = 0;
	j = len;
	// printf("i = %d\nj = %d\n", i, j);
	if ((data->file[i][j] < 9 || data->file[i][j] > 13)
		&& (data->file[i][j] != ' '))
		return (E_CHAR_PATT);
	while (ft_isspace(data->file[i][j]) != 0)
		j++;
	if (data->file[i][j] == 0)
		return (E_CHAR_PATT);
	return (load_data(data, data->file[i], len));
}
