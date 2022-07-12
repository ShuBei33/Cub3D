/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:41:13 by estoffel          #+#    #+#             */
/*   Updated: 2022/07/10 19:57:40 by lzaccome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	load_no(t_stuff *stuff, char *path)
{
	stuff->no_txtr.img = path;
	stuff->no_txtr.cnt = stuff->no_txtr.cnt + 1;
}

void	load_so(t_stuff *stuff, char *path)
{
	stuff->so_txtr.img = path;
	stuff->so_txtr.cnt = stuff->so_txtr.cnt + 1;
}

void	load_we(t_stuff *stuff, char *path)
{
	stuff->we_txtr.img = path;
	stuff->we_txtr.cnt = stuff->we_txtr.cnt + 1;
}

void	load_ea(t_stuff *stuff, char *path)
{
	stuff->ea_txtr.img = path;
	stuff->ea_txtr.cnt = stuff->ea_txtr.cnt + 1;
}
