/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:18:57 by gsims             #+#    #+#             */
/*   Updated: 2023/10/17 17:39:09 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterates over linked list, copies it to a new one 
// Returns the copied list. 
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*newnode;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		newnode = ft_lstnew(f(lst->content));
		if (newnode == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		if (!result)
			result = newnode;
		else
			ft_lstadd_back(&result, newnode);
		lst = lst->next;
	}
	return (result);
}
