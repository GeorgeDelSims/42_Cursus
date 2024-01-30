/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:06:34 by gsims             #+#    #+#             */
/*   Updated: 2024/01/30 15:15:35 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Print node function for debugging (to be used with ft_lst_iter)
void	print_node(void *content)
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

void	ft_print_stack_b(t_lst *stack_b)
{
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

// print for debugging purposes only
void	ft_print_stacks(t_lst *stack_a, t_lst *stack_b)
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
	ft_print_stack_b(stack_b);
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
