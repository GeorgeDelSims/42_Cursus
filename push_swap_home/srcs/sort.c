/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:23:50 by georgesims        #+#    #+#             */
/*   Updated: 2024/01/18 14:41:24 by georgesims       ###   ########.fr       */
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

// Get the amount of steps to reach the correct destination in stack B for the number chosen in stack A
int ft_get_steps_b(int num, t_lst *stack_b)
{
    int     max;
    int     min;
    int     count;
    t_lst   *last;

    max = get_max(stack_b);
    min = get_min(stack_b);
    count = 1;
    last = ft_lst_last(stack_b);
    if (num < min)
    {
        while (*(stack_b->content) != min)
        {
            count++;
            stack_b = stack_b->next;
        }
    }
    else if (num > max)
    {
        while (*(stack_b->content) != max)
        {
            count++;
            stack_b = stack_b->next;
        }
        count--;
    }
    else if (num > min && num < max)
    {
        if (*(last->content) > num && *(stack_b->content) < num)
            return (0);
        while (stack_b)
        {
            if (*(stack_b->content) > num && *(stack_b->next->content) < num)
                break ;
            count++;
            stack_b = stack_b->next;
        }
    }
    return (count);
}

// get raw number of operations to sort node according to position in stack
void    ft_fill_raw_cost(t_lst *stack, int stack_size)
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
            *(stack->cost) = *(stack->idx); // this is where the cost function calculator goes
        else if (*(stack->idx) > stack_size / 2)
            *(stack->cost) = stack_size - *(stack->idx); // this is where the cost function calculator goes
        stack = stack->next;
    }
}

// fills the real cost into each node 
void    ft_cost(t_var *v)
{
    int steps_a;
    int steps_b;
    
    steps_a = 0;
    steps_b = 0;
    while (v->stack_a)
    {
        steps_b = ft_get_steps_b(*(v->stack_a->content), v->stack_b);
        if (steps_b <= v->size_b / 2) // first half of the stack B
        {
           if (steps_a <= v->size_a / 2) // first half of stack A
            {
                if (steps_a > steps_b)
                    *(v->stack_a->cost) = steps_a;
                else
                    *(v->stack_a->cost) = steps_b;                    
            } 
        }
        else if (steps_b > v->size_b / 2) // second half of the stack B
        {
            steps_b = v->size_b - steps_b;
            if (steps_a > v->size_a / 2) // second half of stack A
            {
                steps_a = v->size_a - steps_a;
                if (steps_a > steps_b)
                    *(v->stack_a->cost) = steps_a;
                else
                    *(v->stack_a->cost) = steps_b;
            }
            else
                *(v->stack_a->cost) = steps_a + steps_b;
        }
        steps_a++;
        v->stack_a = v->stack_a->next;
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
    ft_fill_raw_cost(v->stack_a, v->size_a);
    ft_fill_raw_cost(v->stack_b, v->size_b);
    ft_cost(v);    
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
