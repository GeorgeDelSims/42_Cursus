/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:29:55 by georgesims        #+#    #+#             */
/*   Updated: 2024/01/30 11:43:20 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Find index of cheapest node in Stack A
t_lst   *ft_find_cheapest(t_var *v)
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

// Runs operations for the situation when the cheapest number 
// is in the first half of A
// This function can definitely be merged with First_half_A_second_half_B (just like the other one)
int ft_operator_first_half(t_var *v, t_lst *cheap, int rr, int ra)
{
    int     operations;
    int     steps_b;
    
    operations = 0;
    steps_b = ft_get_steps_brut(*(cheap->content), v->stack_b);
    if (steps_b > v->size_b / 2)
        steps_b = v->size_b - steps_b - rr;
    while (rr-- > 0)
        operations += ft_rr(v);
    while (ra-- > 0)
        operations += ft_ra(v);
    while (steps_b-- > 0)
        operations += ft_rb(v);
    operations += ft_pa(v);
    return (operations);
}

// Function to bring the largest number in stack B back to the top
void    ft_back_to_top(t_var *v)
{
    int     max;
    int     steps;
    t_lst   *curr_b;
    
    max = get_max(v->stack_b);
    curr_b = v->stack_b;
    steps = 0;
    while (curr_b && *(curr_b->content) != max)
    {
        steps++;
        curr_b = curr_b->next;
    }
    if (steps < v->size_b / 2)
    {
        while (steps-- > 0)
            v->operations += ft_rb(v); 
    }
    else
    {
        while (steps++ < v->size_b)
            v->operations += ft_rrb(v);
    }
}

// Operations for ft_sort_three
static void    ft_ops_three(t_var *v, int rra, int rs)
{
    while (rra-- > 0)
        v->operations += ft_rev_rotate(&v->stack_a);
    while (rs-- > 0)
        v->operations += ft_swap(&v->stack_a);
}

// Sorting algo for less than 5 numbers
void    ft_sort_three(t_var *v)
{
    t_lst   *curr_a;
    
    curr_a = v->stack_a;
    if (*(curr_a->content) == v->max_a)
    {
        if (*(curr_a->next->content) > v->min_a)
            ft_ops_three(v, 2, 1);
        else
            ft_ops_three(v, 2, 0);
    }
    else if (*(curr_a->next->content) == v->max_a)
    {
        if (*(curr_a->content) > v->min_a)
            v->operations = ft_rev_rotate(&v->stack_a);
        else
            ft_ops_three(v, 1, 1);
    }
    else
    {
        if (*(curr_a->content) > v->min_a)
            v->operations = ft_swap(&v->stack_a);
        else
            v->operations = 0;
    }
}
