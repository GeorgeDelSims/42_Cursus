/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:11:31 by georgesims        #+#    #+#             */
/*   Updated: 2024/01/25 13:39:57 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Print node function for debugging (to be used with ft_lst_iter)
void print_node(void *content)
{
   printf("%d\n", *(int *)content);
}

// print for debugging purposes:
void	ft_print_stacks_backup(t_lst *stack_a, t_lst *stack_b)
{
	ft_printf("stack A :\n");
	ft_lst_iter(stack_a, print_node);
	ft_printf("stack B :\n");
	ft_lst_iter(stack_b, print_node);
}

// print for debugging purposes only 
void ft_print_stacks(t_lst *stack_a, t_lst *stack_b)
{
    ft_printf("stack A :\n");
    while (stack_a)
    {
		if (stack_a->content == NULL)
			ft_printf("content: / | ");
		else
			ft_printf("content: %d |", *(int *)stack_a->content);
		if (stack_a->idx == NULL)
			ft_printf("idx: / | ");
		else
			ft_printf("idx: %d |", *(int *)stack_a->idx);
		if (stack_a->cost == NULL)
			ft_printf("cost: / |\n");
		else
			ft_printf("cost: %d |\n", *(int *)stack_a->cost);
        stack_a = stack_a->next;
    }
	ft_printf("stack B :\n");
    while (stack_b)
    {
		if (stack_b->content == NULL)
			ft_printf("content: / | ");
		else
			ft_printf("content: %d |", *(int *)stack_b->content);
		if (stack_b->idx == NULL)
			ft_printf("idx: / | ");
		else
			ft_printf("idx: %d |", *(int *)stack_b->idx);
		if (stack_b->cost == NULL)
			ft_printf("cost: / |\n");
		else
			ft_printf("cost: %d |\n", *(int *)stack_b->cost);
        stack_b = stack_b->next;
    }
}

void	ft_print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_printf("array[%d] : %s\n", i, array[i]);
		i++;
	}
}

int	ft_count_array(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}


void    ft_error(int errno, char *str)
{
    ft_printf("Error:\n%s\n", str);
    exit(errno);
}