/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 14:18:14 by nilim             #+#    #+#             */
/*   Updated: 2026/08/07 19:27:42 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newhead;
	t_list	*newnode;
	t_list	*curr;

	newhead = NULL;
	curr = lst;
	while (curr != NULL)
	{
		newnode = ft_lstnew(f(curr->content));
		if (newnode == NULL)
		{
			ft_lstclear(&newhead, del);
			return (NULL);
		}
		ft_lstadd_back(&newhead, newnode);
		curr = curr->next;
	}
	return (newhead);
}
