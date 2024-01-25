/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:20:09 by gsims             #+#    #+#             */
/*   Updated: 2024/01/25 12:25:56 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Sorting algorithm for extremely small arrays
int ft_sort_small(t_var *v)
{
    ft_printf("Small sorting algo needed for size %d\n", v->size_a);
    return (v->operations);
}


// Find index of cheapest node in Stack A
static t_lst   *ft_find_cheapest(t_var *v)
{
    t_lst   *curr_a;
    t_lst   *find;
    int     min;
    
    if (v->stack_a->next == NULL)
        return (v->stack_a);
    curr_a = v->stack_a;
    min = *(curr_a->cost);
    while (curr_a != NULL)
    {
        if (*(curr_a->cost) < min)
            min = *(curr_a->cost);
        curr_a = curr_a->next;
    }
    find = v->stack_a;
    while (find != NULL)
    {
        if (*(find->cost) == min)
            break ;
        find = find->next;
    }
    return (find);
}

// Function that launches the right amount of operations for the first half of Stack A
static int ft_operator_first_half(t_var *v, t_lst *cheap, int rr, int ra)
{
    int     operations;
    int     steps_b;
    
    operations = 0;
    steps_b = ft_get_steps_brut(*(cheap->content), v->stack_b);
    if (steps_b > v->size_b / 2)
        steps_b = v->size_b - steps_b - rr;  // Possible mistake here 
    while (rr-- > 0)
        operations += ft_rr(v);
    while (ra-- > 0)
        operations += ft_ra(v);
    while (steps_b-- > 0)
        operations += ft_rb(v);
    operations += ft_pa(v);
    return (operations);
}

// Function that launches the right amount of operations for the first half of Stack A
static int ft_operator_second_half(t_var *v, t_lst *cheap, int rrr, int rra)
{
    int operations;
    int     steps_b;
    
    operations = 0;
    steps_b = ft_get_steps_brut(*(cheap->content), v->stack_b);
    ft_printf("steps_b in ft_operator_second_half : %d\n", steps_b);
    if (steps_b > v->size_b / 2)
        steps_b = v->size_b - steps_b;  // Possible mistake here 
    ft_printf("stack_b content in operator second half: %d\n", *(v->stack_b->content));
    while (rrr-- > 0)
        operations += ft_rrr(v);
    while (rra-- > 0)
        operations += ft_rra(v);
    while (steps_b-- > 0)
        operations += ft_rrb(v);
    operations += ft_pa(v); 
    return (operations);
}


static int ft_operator_first_half_a_second_half_b(t_var *v, int ra, int rrb)
{
    int operations;
    
    operations = 0;
    while (ra-- > 0)
        operations += ft_ra(v);
    while (rrb-- > 0)
        operations += ft_rrb(v);
    operations += ft_pa(v); 
    return (operations);
}

// actually sort the nodes by using the operation functions
void    ft_sort(t_var *v)
{
    t_lst   *cheap;
    t_lst   *curr_b;
    int     idx;
    int     idx_b;
    int     cost;
    int     double_ops;

    double_ops = 0;
    while (v->size_a > 0)
    {
        curr_b = v->stack_b;
        cheap = ft_find_cheapest(v);
        idx = *(cheap->idx);
        cost = *(cheap->cost);
        idx_b = ft_get_steps_brut(*(cheap->content), curr_b);
        double_ops = 1 + idx - cost;
        ft_printf("cheap->content : %d\n", *(cheap->content));
        ft_printf("cheap->idx : %d\n", *(cheap->idx));
        ft_printf("cheap->cost : %d\n", *(cheap->cost));
        ft_printf("idx_b : %d\n", idx_b);
        if (idx <= v->size_a / 2) // First half of Stack A
        {
            if (idx_b <= v->size_b / 2) // First half of Stack B
            {
                if (cost <= idx + 1 ) // Check if cost is lower than index + 1 (means there will be double operations to reduce cost)
                    v->operations += ft_operator_first_half(v, cheap, double_ops, idx - double_ops);
                else
                    v->operations += ft_operator_first_half(v, cheap, 0, idx);
            }
            else // Second half of Stack B (But still first half of Stack A)
                v->operations += ft_operator_first_half_a_second_half_b(v, idx, v->size_b - idx_b);
        }
        else // Second half of Stack A 
        {
            if (cost < v->size_a - idx ) // Check if cost is lower than v_size_a - index (means there will be double operations to reduce cost)
                v->operations += ft_operator_second_half(v, cheap, (v->size_a - idx) - cost, v->size_a - idx);
            else
                v->operations += ft_operator_second_half(v, cheap, 0, v->size_a - idx);    
        }
        ft_print_stacks(v->stack_a, v->stack_b);
        ft_printf("operations : %d\n", v->operations);
    }
}