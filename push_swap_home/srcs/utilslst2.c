/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilslst2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:30:14 by gsims             #+#    #+#             */
/*   Updated: 2024/01/30 15:12:36 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	get_max(t_lst *stack)
{
	int		max;
	t_lst	*curr;

	if (stack->next == NULL)
		return (*(stack->content));
	curr = stack;
	max = *(int *)(curr->content);
	while (curr != NULL)
	{
		if (*(int *)(curr->content) > max)
			max = *(int *)curr->content;
		curr = curr->next;
	}
	return (max);
}

int	get_min(t_lst *stack)
{
	int		min;
	t_lst	*curr;

	if (stack->next == NULL)
		return (*(stack->content));
	curr = stack;
	min = *(int *)(curr->content);
	while (curr != NULL)
	{
		if (*(int *)(curr->content) < min)
			min = *(int *)curr->content;
		curr = curr->next;
	}
	return (min);
}

// Check if stack is sorted (return 1 if sorted and 0 if not)
int	check_sort_a(t_lst *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (*(stack->content) > *(stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_sort_b(t_lst *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (*(stack->content) < *(stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}
