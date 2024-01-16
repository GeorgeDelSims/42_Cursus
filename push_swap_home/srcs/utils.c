/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:11:31 by georgesims        #+#    #+#             */
/*   Updated: 2024/01/16 17:10:22 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
void    ft_error(int errno, char *str)
{
    ft_printf("Error:\n%s\n", str);
    exit(errno);
}