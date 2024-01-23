/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:23:50 by georgesims        #+#    #+#             */
/*   Updated: 2024/01/23 16:57:49 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Helper function for ft_get_steps_b
static int ft_small_num(t_lst *curr_b, int count, int min, int max)
{
    if (*(curr_b->content) == max) // if max is top of stack B -> put small num on top
        return (0);
    while (*(curr_b->content) != min && curr_b->next != NULL)
    {
        count++;
        curr_b = curr_b->next;
    }
    // Add clause for when in second half of stack (if > half the stack)
    return (count + 1);
}

// Helper function for ft_get_steps_b
static int ft_big_num(t_lst *curr_b, int count, int max)
{
    while (*(curr_b->content) != max && curr_b->next != NULL)
    {
        count++;
        curr_b = curr_b->next;
    }
    //count--;
    return (count);
}

// Helper function for ft_get_steps_b
static int ft_mid_num(t_lst *curr_b, t_lst *last, int count, int num)
{
    if (*(last->content) > num && *(curr_b->content) < num)
        return (0);
    while (curr_b)
    {
        count++;
        if (*(curr_b->content) > num && *(curr_b->next->content) < num)
            break ;
        curr_b = curr_b->next;
    }
    return (count);
}

// Get the amount of steps to reach the correct destination in stack B for the number chosen in stack A
// DOES NOT INCLUDE THE PUSH FROM STACK A TO STACK B
// Only takes into account the order of stack_b, not the placement of num in stack_a
// Does not take into account first half / second half problem or reverse rotates
int ft_get_steps_brut(int num, t_lst *stack_b) //, t_var *v)
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
    count = 0;
    last = ft_lst_last(curr_b);
    if (num < min)
    {
        ft_printf("curr_b content : %d\n", *(curr_b->content));
        count += ft_small_num(curr_b, count, min, max);
    }
    else if (num > max)
        count += ft_big_num(curr_b, count, max);    
    else if (num > min && num < max)
        count += ft_mid_num(curr_b, last, count, num);
    return (count);
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