/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 19:35:30 by estoffel          #+#    #+#             */
/*   Updated: 2021/07/29 18:10:54 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpy_tmp;
	t_list	*new_lst;

	if (!f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		cpy_tmp = ft_lstnew((*f)(lst->content));
		if (!cpy_tmp && del)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, cpy_tmp);
		lst = lst->next;
	}
	return (new_lst);
}
