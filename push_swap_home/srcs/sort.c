/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:23:50 by georgesims        #+#    #+#             */
/*   Updated: 2024/01/22 16:41:16 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


// Get the amount of steps to reach the correct destination in stack B for the number chosen in stack A
int ft_get_steps_b(int num, t_lst *stack_b)
{
    int     max;
    int     min;
    int     count;
    t_lst   *last;
    t_lst   *curr_b;

    curr_b = stack_b;
    if (curr_b == NULL)
        ft_error(1, "stack_b empty");
    max = get_max(curr_b);
    min = get_min(curr_b);
    count = 1;
    last = ft_lst_last(curr_b);
    //ft_print_stacks(curr_a, curr_b);
    if (num < min)
    {
        while (*(curr_b->content) != min && curr_b->next != NULL)
        {
            count++;
            curr_b = curr_b->next;
        }
    }
    else if (num > max)
    {
        while (*(curr_b->content) != max && curr_b->next != NULL)
        {
            count++;
            curr_b = curr_b->next;
        }
        count--;
    }
    else if (num > min && num < max)
    {
        if (*(last->content) > num && *(curr_b->content) < num)
            return (0);
        while (curr_b)
        {
            if (*(curr_b->content) > num && *(curr_b->next->content) < num)
                break ;
            count++;
            curr_b = curr_b->next;
        }
    }
    return (count);
}

// get raw number of operations to sort node according to position in stack
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
            *(curr->cost) = *(curr->idx); // this is where the cost function calculator goes
        else if (*(curr->idx) > stack_size / 2)
            *(curr->cost) = stack_size - *(curr->idx); // this is where the cost function calculator goes
        curr= curr->next;
    }
}

// fills the real cost into each node 
void    ft_cost(t_var *v)
{
    int steps_a;
    int steps_b;
    t_lst   *curr_a;
    t_lst   *curr_b;
    
    steps_a = 1;
    steps_b = 1;
    curr_a = v->stack_a;
    curr_b = v->stack_b;
    while (curr_a)
    {
        steps_b = ft_get_steps_b(*(curr_a->content), curr_b);
        if (steps_b <= v->size_b / 2) // first half of the stack B
        {
           if (steps_a <= v->size_a / 2) // first half of stack A
            {
                if (steps_a > steps_b)
                    *(curr_a->cost) += steps_a;
                else
                    *(curr_a->cost) += steps_b;                    
            } 
        }
        else if (steps_b > v->size_b / 2) // second half of the stack B
        {
            steps_b = v->size_b - steps_b;
            if (steps_a > v->size_a / 2) // second half of stack A
            {
                steps_a = v->size_a - steps_a;
                if (steps_a > steps_b)
                    *(curr_a->cost) += steps_a;
                else
                    *(curr_a->cost) += steps_b;
            }
            else
                *(curr_a->cost) = steps_a + steps_b;
        }
        steps_a++;
        curr_a = curr_a->next;
    }
}

// Iterate on the idx of each node of the stacks 
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
