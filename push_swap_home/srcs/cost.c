/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:17:16 by gsims             #+#    #+#             */
/*   Updated: 2024/01/25 13:47:07 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// both halves of stack A & first half of Stack B
static void    ft_cost_first_half(t_var *v, int steps_a, int steps_brut, t_lst *curr_a)
{
	if (steps_a <= v->size_a / 2) // first half of stack A 
    {
        if (steps_a > steps_brut)
            *(curr_a->cost) = steps_a + 1;
        else
            *(curr_a->cost) = steps_brut + 1;                    
    }
    else if (steps_a > v->size_a / 2) // second half of stack A
    {
        *(curr_a->cost) = v->size_a - steps_a + steps_brut + 1;
    }
}

// both halves of stack A & second half of Stack B
static void    ft_cost_second_half(t_var *v, int steps_a, int steps_brut, t_lst *curr_a)
{
    steps_brut = v->size_b - steps_brut;
    if (steps_a > v->size_a / 2)  // Second half of stack A
    {
        steps_a = v->size_a - steps_a;
        if (steps_a > steps_brut)
            *(curr_a->cost) += steps_a;
        else
            *(curr_a->cost) += steps_brut;
    }
    else // First half of Stack A
        *(curr_a->cost) = steps_a + steps_brut + 1;
}

// fills the real cost into each node 
void    ft_cost(t_var *v)
{
    int steps_a;
    int steps_brut;
    t_lst   *curr_a;
    t_lst   *curr_b;
    
    steps_a = 0;
    curr_a = v->stack_a;
    curr_b = v->stack_b;
    while (curr_a)
    {
        steps_brut = ft_get_steps_brut(*(curr_a->content), curr_b);
        if (steps_brut <= v->size_b / 2) // first half of the stack B
            ft_cost_first_half(v, steps_a, steps_brut, curr_a); // both halves of stack A
        else if (steps_brut > v->size_b / 2) // second half of the stack B
            ft_cost_second_half(v, steps_a, steps_brut, curr_a); // both halves of stack A
        steps_a++;
        curr_a = curr_a->next;
    }
}

// get raw number of operations to sort node according to position in stack
// Also does all the memory allocation for the cost & index values
void    ft_fill_raw_cost(t_lst *stack, int stack_size)
{
    t_lst   *curr;
    
    curr = stack;
    while (curr)
    {
        if (curr->cost == NULL)
        {
            curr->cost = (int *)malloc(sizeof(int));
            if (curr->cost == NULL)
                ft_error(1, "malloc failure ft_get_cost");
        }
        if (*(curr->idx) <= stack_size / 2)
            *(curr->cost) = *(curr->idx); 
        else if (*(curr->idx) > stack_size / 2)
            *(curr->cost) = stack_size - *(curr->idx);
        curr= curr->next;
    }
}

// Iterate on the idx of each node of the stacks and rewrite it in order for 
void    ft_lst_idx(t_lst *stack)
{
    int     i;
    t_lst   *curr;
    
    if (!stack)
        return ;
    curr = stack;
    i = 0;
    while (curr)
    {
        if (curr->idx == NULL)
        {
            curr->idx = (int *)malloc(sizeof(int));
            if (curr->idx == NULL)
                ft_error(1, "malloc failure ft_lst_idx\n");
        }
        *(curr->idx) = i;
        i++;
        curr = curr->next;
    }
}
