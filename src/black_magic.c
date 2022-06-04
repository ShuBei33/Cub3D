/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black_magic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 02:51:22 by estoffel          #+#    #+#             */
/*   Updated: 2022/06/04 03:24:49 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/*
how to call it:

if (initmlc(&str, sizeof(xxx) * xxx, __FUNCTION__) != 0)
	return (error);

free :

release(&str);*/

int	initmlc(void *ptr, const size_t size, const char *s)
{
	*(void **)ptr = malloc(size);
	if (!*(void **)ptr)
	{
		if (s)
			printf("Error\nMalloc failed in function %s\n", s);
		return (-1);
	}
	ft_bzero(*(void **)ptr, size);
	return (EXIT_SUCCESS); 
}

int	release(void *ptr)
{
	if (*(void **)ptr)
	{
		free(*(void **)ptr);
		*(void **)ptr = NULL;
		return (EXIT_SUCCESS);
	}
	return (-1);
}
