/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilslst2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:30:14 by gsims             #+#    #+#             */
/*   Updated: 2024/01/16 16:58:20 by gsims            ###   ########.fr       */
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

int get_max(t_lst *stack)
{
    int max;
    t_lst *curr;

    max = *(int *)(stack->content);
    curr = stack->next;
    while (curr != NULL)
    {
        if (*(int *)(curr->content) > max)
            max = *(int *)curr->content;
        curr = curr->next;
    }
    return (max);
}

int get_min(t_lst *stack)
{
    int min;
    t_lst *curr;

    min = *(int *)(stack->content);
    curr = stack->next;
    while (curr != NULL)
    {
        if (*(int *)(curr->content) < min)
            min = *(int *)curr->content;
        curr = curr->next;
    }
    return (min);
}

// Check if stack is sorted (return 1 if sorted and 0 if not)
int	check_sort(t_lst *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (*(stack->content) > *(stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}