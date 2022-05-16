/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:47:31 by estoffel          #+#    #+#             */
/*   Updated: 2021/06/26 19:13:30 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last_lst;

	if (alst)
	{
		last_lst = ft_lstlast(*alst);
		if (new && last_lst)
			last_lst->next = new;
		else
			*alst = new;
	}
}
