/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:23:50 by georgesims        #+#    #+#             */
/*   Updated: 2024/01/17 15:32:55 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Calculate cost for each node 
// void    ft_calculate_cost(t_var *v)
// {
    // t_lst   *tmp;
    // 
    // tmp = v->stack_a;
    // ft_printf("size_a = %d\n", v->size_a);
// }
// 

// get number of operations to sort node 
void    ft_get_cost(t_lst *stack, int stack_size)
{
    while (stack)
    {
        if (stack->cost == NULL)
        {
            stack->cost = (int *)malloc(sizeof(int));
            if (stack->cost == NULL)
                ft_error(1, "malloc failure ft_get_cost");
        }
        if (*(stack->idx) <= stack_size / 2)
            *(stack->cost) = *(stack->idx);
        else if (*(stack->idx) > stack_size / 2)
            *(stack->cost) = stack_size - *(stack->idx);
        stack = stack->next;
    }
}

// Iterate on the idx of each node of the stacks 
void    ft_lst_idx(t_lst *stack)
{
    int i;
    
    if (!stack)
        return ;
    i = 0;
    while (stack)
    {
        if (stack->idx == NULL)
        {
            stack->idx = (int *)malloc(sizeof(int));
            if (stack->idx == NULL)
                ft_error(1, "malloc failure ft_lst_idx\n");
        }
        *(stack->idx) = i;
        i++;
        stack = stack->next;
    }
}

// Fill values in both linked lists in order to prepare for operations
void    ft_fill_values(t_var *v)
{
    ft_lst_idx(v->stack_a);
    ft_lst_idx(v->stack_b);
    ft_get_cost(v->stack_a, v->size_a);
    ft_get_cost(v->stack_b, v->size_b);
}

// sort 9 numbers or less 
int ft_sort_small(t_var *v)
{
    int res;

    res = ft_pb(v);
    res += ft_pb(v);
    ft_printf("it's small\n");
    return (res);
}

// Sort for 10 numbers or more
int ft_sort_big(t_var *v)
{
    ft_printf("size_a = %d\n", v->size_a);
    ft_printf("it's big\n");
    return (v->size_a);
}

// Main sorting algorithm
int ft_sort(t_var *v)
{
    int res;
    
    if (v->size_a < 10)
        res = ft_sort_small(v);
    else 
        res = ft_sort_big(v);
    return (res);
}
