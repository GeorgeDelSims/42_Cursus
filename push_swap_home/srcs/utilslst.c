/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilslst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:33:48 by gsims             #+#    #+#             */
/*   Updated: 2024/01/26 09:34:50 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lst_add_back(t_lst **lst, t_lst *new_node)
{
	t_lst	*curr;

	if (!lst || !new_node)
		return ;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	curr = *lst;
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
}

void	ft_lst_add_front(t_lst **lst, t_lst *new_node)
{
	if (!lst || !new_node)
		return ;
	new_node->next = *lst;
	*lst = new_node;
}

int	ft_lst_size(t_lst *lst)
{
	t_lst	*current;
	int		counter;

	counter = 0;
	current = lst;
	while (current != NULL)
	{
		current = current->next;
		counter++;
	}
	return (counter);
}

void	ft_lst_iter(t_lst *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{	
		f(lst->content);
		lst = lst->next;
	}
}

t_lst	*ft_lst_new(void *content, void *idx, void *cost)
{
	t_lst	*new_node;

	new_node = (t_lst *)malloc(sizeof(t_lst));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->idx = idx;
	new_node->cost = cost;
	new_node->next = NULL;
	return (new_node);
}
