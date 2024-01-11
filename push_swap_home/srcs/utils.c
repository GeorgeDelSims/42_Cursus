/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:11:31 by georgesims        #+#    #+#             */
/*   Updated: 2024/01/11 15:28:58 by georgesims       ###   ########.fr       */
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
