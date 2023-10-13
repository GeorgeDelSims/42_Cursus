/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:30:58 by gsims             #+#    #+#             */
/*   Updated: 2023/10/13 16:57:21 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && *lst)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
int main() {
	long		a = 5;
	long		b = 1;
    //t_list	**head = NULL;
	t_list	*new1 = ft_lstnew((void*)a);
	t_list	*new2 = ft_lstnew((void*)b);
	t_list **ppelem = NULL;
	if(new1)
		ppelem = &new1;
	printf("content de ppelem avant fonction: %d\n", (int) (*ppelem)->content);
	ft_lstadd_front(ppelem, new2); 
    printf("content de ppelem apres fonction %d\n", (int) (*ppelem)->content);
    printf("content pointe par next de ppelem %d\n", (int) (*ppelem)->next->content);
	printf("NULL\n");
    return 0;
}*/
