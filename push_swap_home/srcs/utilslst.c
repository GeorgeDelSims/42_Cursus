/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilslst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:33:48 by gsims             #+#    #+#             */
/*   Updated: 2024/01/16 10:33:52 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lst_add_back(t_lst **lst, t_lst *new)
{
	t_lst	*curr;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

void	ft_lst_add_front(t_lst **lst, t_lst *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
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

t_lst	*ft_lst_new(void *content)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_lst	*ft_lst_last(t_lst *lst)
{
	t_lst	*curr;

	if (!lst)
		return (NULL);
	curr = lst;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = NULL;
	return (curr);
}
