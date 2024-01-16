/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:46:25 by georgesims        #+#    #+#             */
/*   Updated: 2024/01/16 11:49:39 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Push A: Take the first element at the top of B and put it at the top of A. 
// Do nothing if B is empty
int ft_push(t_lst **stack_a, t_lst **stack_b)
{
    t_lst  *temp;
    if (!(*stack_b))
        return (0);
    temp = *stack_b;
    *stack_b = (*stack_b)->next;
    temp->next = *stack_a;
    *stack_a = temp;
    return (1);
}

//Swap A: Swap the first 2 elements at the top of stack A. 
//Do nothing if there is only one or no elements.

int ft_swap(t_lst **stack)
{
    int     size;
    t_lst  *first;
    t_lst  *second;
    
    size = ft_lst_size(*stack);
    if (size < 2)
        return (0);
    first = *stack;
    second = (*stack)->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
    return (1);
}

// Rotate : Shift all elements of Stack up by 1. 
// The first element becomes the last one

int ft_rotate(t_lst **stack)
{
    int size;
    t_lst  *first;
    t_lst  *second;
    t_lst  *last;
    
    size = ft_lst_size(*stack);
    if (size < 2)
        return (0);
    if (size == 2)
    {
        ft_swap(stack);
        return (1);
    }
    first = *stack;
    second = (*stack)->next;
    last = ft_lst_last(*stack);
    last->next = first;
    *stack = second;
    first->next = NULL;
    return (1);
}

// Reverse rotate: Shift all elements of stack down by one.
// THe last element becomes the first.

int ft_rev_rotate(t_lst **stack)
{
    t_lst  *last;
    t_lst  *second_last;
    
    if (*stack == NULL || (*stack)->next == NULL)
        return (0);
    second_last = *stack; 
    while (second_last->next->next != NULL)
        second_last = second_last->next;
    last = second_last->next;
    second_last->next = NULL;
    last->next = *stack;
    *stack = last;
    return (1);
}
