/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:11:31 by georgesims        #+#    #+#             */
/*   Updated: 2024/01/12 11:20:24 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_max(t_list *stack)
{
    int max;
    t_list *curr;

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

int get_min(t_list *stack)
{
    int min;
    t_list *curr;

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

// Print node function for debugging (to be used with ft_lstiter)
void print_node(void *content)
{
    printf("%d\n", *(int *)content);
}

// print for debugging purposes:
void	ft_print_stacks(t_list *stack_a, t_list *stack_b)
{
	ft_printf("stack A :\n");
	ft_lstiter(stack_a, print_node);
	ft_printf("stack B :\n");
	ft_lstiter(stack_b, print_node);
	ft_lstiter(stack_a, free);
}