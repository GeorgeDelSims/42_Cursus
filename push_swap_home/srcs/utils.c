/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:11:31 by georgesims        #+#    #+#             */
/*   Updated: 2024/01/16 10:21:48 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_max(t_lst *stack)
{
    int max;
    t_lst *curr;

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

int get_min(t_lst *stack)
{
    int min;
    t_lst *curr;

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

// Print node function for debugging (to be used with ft_lst_iter)
void print_node(void *content)
{
    printf("%d\n", *(int *)content);
}

// print for debugging purposes:
void	ft_print_stacks(t_lst *stack_a, t_lst *stack_b)
{
	ft_printf("stack A :\n");
	ft_lst_iter(stack_a, print_node);
	ft_printf("stack B :\n");
	ft_lst_iter(stack_b, print_node);
	ft_lst_iter(stack_a, free);
}

void    error(int errno, char *str)
{
    write(1, "Error:\n", 7);
    ft_printf("%s\n", str);
    exit(errno);
}